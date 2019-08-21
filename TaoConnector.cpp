#include "pch.h"
#include "TaoConnector.h"

std::wstring TaoConnector::username = L"15882381309";
std::wstring TaoConnector::password = L"123456";
Windows::Foundation::Uri^ TaoConnector::BaseUri = ref new Windows::Foundation::Uri(L"http://api.tp.tmiao.tech:16000/api/v1/");
Windows::Web::Http::HttpClient^ TaoConnector::httpClient = ref new HttpClient();

Platform::String^ TaoConnector::GetBase64Cred()
{
	std::wstringstream wstringstream;
	wstringstream << username << ":" << password;
	auto buffer = Windows::Security::Cryptography::CryptographicBuffer::ConvertStringToBinary(
		ref new Platform::String(wstringstream.str().c_str()),
		Windows::Security::Cryptography::BinaryStringEncoding::Utf8);
	Platform::String^ base64token = Windows::Security::Cryptography::CryptographicBuffer::EncodeToBase64String(buffer);
	return base64token;
}

Uri^ TaoConnector::GenerateUri(Platform::String^ subUri)
{
	return BaseUri->CombineUri(subUri);
}

HttpRequestMessage^ TaoConnector::GenerateRequest(Uri^ final_uri, HttpMethod^ method, Platform::String^ cred)
{
	auto request = ref new HttpRequestMessage(method, final_uri);
	request->Headers->Authorization = ref new HttpCredentialsHeaderValue("Basic", cred);
	return request;
}

void TaoConnector::RefreshSubdivisions()
{
	auto request = GenerateRequest(GenerateUri(L"subdivision/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					//SubTitle->Text = ((UINT32) response->StatusCode).ToString();
					//TESTBLOCK->Text = result->ResponseMessage->Content->ToString();
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					//TESTBLOCK->Text = ((UINT32)theJsons->Size).ToString();
					SubdivisionViewModel::Subdivisions->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						Platform::String^ name = nowJson->Lookup("name")->GetString();
						int id = nowJson->Lookup("id")->GetNumber();
						int enterpriseId = nowJson->Lookup("enterprise")->GetNumber();
						Platform::String^ createTime = nowJson->Lookup("createdTime")->GetString();

						auto operatorArray = nowJson->Lookup("operator")->GetArray();
						Platform::Collections::Vector<int>^ nowOperator = ref new Platform::Collections::Vector<int>();
						for (int j = 0; j < operatorArray->Size; ++j)
						{
							nowOperator->Append(operatorArray->GetNumberAt(j));
						}

						//Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar(createdTime);



						SubdivisionViewModel::Subdivisions->Append(ref new Subdivision(id, name, createTime, enterpriseId, nowOperator));

					}

				}
				else
				{
					//SubTitle->Text = "FAILED";
					//TESTBLOCK->Text = result->ResponseMessage->Content->ToString();

					//return task_from_result();
				}
			});
}

void TaoConnector::RefreshEnterprises()
{
	auto request = GenerateRequest(GenerateUri(L"enterprise/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					EnterpriseViewModel::Enterprises->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						Platform::String^ name = nowJson->Lookup("name")->GetString();
						Platform::String^ createTime = nowJson->Lookup("createdTime")->GetString();
						int nowEnterpriseId = nowJson->Lookup("founder")->GetNumber();
						
						auto operatorArray = nowJson->Lookup("manager")->GetArray();
						Platform::Collections::Vector<int>^ nowOperator = ref new Platform::Collections::Vector<int>();
						for (int j = 0; j < operatorArray->Size; ++j)
						{
							nowOperator->Append(operatorArray->GetNumberAt(j));
						}

						EnterpriseViewModel::Enterprises->Append(ref new Enterprise(id, name, createTime, nowEnterpriseId, nowOperator));
					}
				}
			});
}

void TaoConnector::RefreshResidents()
{
	auto request = GenerateRequest(GenerateUri(L"user/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					ResidentViewModel::Residents->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						Platform::String^ name = nowJson->Lookup("name")->GetString();
						Platform::String^ email = nowJson->Lookup("email")->GetString();
						Platform::String^ phone = nowJson->Lookup("phone")->GetString();
						//Platform::String^ createTime = nowJson->Lookup("createTime")->GetString();
						Platform::String^ createTime = L"";

						ResidentViewModel::Residents->Append(ref new Resident(id, name, email, phone, createTime));
					}
				}
			});
}

void TaoConnector::RefreshHouses()
{
	auto request = GenerateRequest(GenerateUri(L"house/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					HouseViewModel::Houses->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						int subdivisionId = nowJson->Lookup("subdivision")->GetNumber();

						auto proprietorArray = nowJson->Lookup("proprietor")->GetArray();
						Platform::Collections::Vector<int>^ proprietor = ref new Platform::Collections::Vector<int>();
						for (int j = 0; j < proprietorArray->Size; ++j)
						{
							proprietor->Append(proprietorArray->GetNumberAt(j));
						}

						Platform::String^ note = nowJson->Lookup("note")->GetString();
						Platform::String^ no = nowJson->Lookup("no")->GetString();
						float netFloorArea = nowJson->Lookup("netFloorArea")->GetNumber();
						float grossFloorArea = nowJson->Lookup("grossFloorArea")->GetNumber();
						Platform::String^ building = nowJson->Lookup("building")->GetString();
						int unit = nowJson->Lookup("unit")->GetNumber();
						int floor = nowJson->Lookup("floor")->GetNumber();
						Platform::String^ houseStatus = nowJson->Lookup("houseStatus")->GetString();
						Platform::String^ layout = nowJson->Lookup("layout")->GetString();
						Platform::String^ direction = nowJson->Lookup("direction")->GetString();
						//Platform::String^ createTime = nowJson->Lookup("createTime")->GetString();

						HouseViewModel::Houses->Append(ref new House(id, subdivisionId, proprietor, note, no, 
							netFloorArea, grossFloorArea, building, unit, floor, houseStatus, layout, direction));
					}
				}
			});
}

void TaoConnector::RefreshOperators()
{
	auto request = GenerateRequest(GenerateUri(L"user/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					OperatorViewModel::Operators->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						Platform::String^ name = nowJson->Lookup("name")->GetString();
						Platform::String^ email = nowJson->Lookup("email")->GetString();
						Platform::String^ phone = nowJson->Lookup("phone")->GetString();
						//Platform::String^ createTime = nowJson->Lookup("createTime")->GetString();
						Platform::String^ createTime = L"";

						OperatorViewModel::Operators->Append(ref new Operator(id, name, email, phone, createTime));
					}
				}
			});
}

void TaoConnector::RefreshCarports()
{
	auto request = GenerateRequest(GenerateUri(L"carport/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					CarportViewModel::Carports->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						int subdivisionId = nowJson->Lookup("subdivision")->GetNumber();

						auto proprietorArray = nowJson->Lookup("proprietor")->GetArray();
						Platform::Collections::Vector<int>^ proprietor = ref new Platform::Collections::Vector<int>();
						for (int j = 0; j < proprietorArray->Size; ++j)
						{
							proprietor->Append(proprietorArray->GetNumberAt(j));
						}

						Platform::String^ note = nowJson->Lookup("note")->GetString();
						Platform::String^ no = nowJson->Lookup("no")->GetString();
						//Platform::String^ createTime = nowJson->Lookup("createTime")->GetString();

						CarportViewModel::Carports->Append(ref new Carport(id, subdivisionId, proprietor, note, no));
					}
				}
			});
}

void TaoConnector::RefreshChargeTemplates()
{
	auto request = GenerateRequest(GenerateUri(L"charge_template/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					ChargeTemplateViewModel::ChargeTemplates->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						int subdivisionId = nowJson->Lookup("subdivision")->GetNumber();
						Platform::String^ name = nowJson->Lookup("name")->GetString();
						Platform::String^ chargeType = nowJson->Lookup("chargeType")->GetString();
						float unitPrice = nowJson->Lookup("unitPrice")->GetNumber();
						int billingCycle = nowJson->Lookup("billingCycle")->GetNumber();
						//Platform::String^ createTime = nowJson->Lookup("createTime")->GetString();

						ChargeTemplateViewModel::ChargeTemplates->Append(ref new ChargeTemplate(id, subdivisionId, name, chargeType, unitPrice, billingCycle));
					}
				}
			});
}

void TaoConnector::RefreshTransactions()
{
	auto request = GenerateRequest(GenerateUri(L"transaction/"), HttpMethod::Get, GetBase64Cred());
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					JsonArray^ theJsons = JsonArray::Parse(result->ResponseMessage->Content->ToString());

					TransactionViewModel::Transactions->Clear();
					for (int i = 0; i < theJsons->Size; ++i)
					{
						JsonObject^ nowJson = theJsons->GetObjectAt(i);
						int id = nowJson->Lookup("id")->GetNumber();
						int subdivisionId = nowJson->Lookup("subdivision")->GetNumber();

						auto billsArray = nowJson->Lookup("bills")->GetArray();
						Platform::Collections::Vector<int>^ bills = ref new Platform::Collections::Vector<int>();
						for (int j = 0; j < billsArray->Size; ++j)
						{
							bills->Append(billsArray->GetNumberAt(j));
						}

						Platform::String^ createTime = nowJson->Lookup("createdTime")->GetString();
						int totalCost = nowJson->Lookup("totalCost")->GetNumber();
						int feePayable = nowJson->Lookup("feePayable")->GetNumber();
						int feeWaiver = nowJson->Lookup("feeWaiver")->GetNumber();
						Platform::String^ paymentMethod = nowJson->Lookup("paymentMethod")->GetString();
						
						TransactionViewModel::Transactions->Append(ref new Transaction(id, subdivisionId, bills, createTime, totalCost, feePayable, feeWaiver, paymentMethod));
					}
				}
			});
}
