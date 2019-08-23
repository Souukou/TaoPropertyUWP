#include "pch.h"
#include "TaoConnector.h"
#include "NewHousePage.xaml.h"

String^ TaoConnector::username = L"15882381309";
String^ TaoConnector::password = L"123456";
Windows::Foundation::Uri^ TaoConnector::BaseUri = ref new Windows::Foundation::Uri(L"http://api.tp.tmiao.tech:16000/api/v1/");
Windows::Web::Http::HttpClient^ TaoConnector::httpClient = ref new HttpClient();

Platform::String^ TaoConnector::GetBase64Cred()
{
	auto buffer = Windows::Security::Cryptography::CryptographicBuffer::ConvertStringToBinary(
		UserName + ":" + PassWord,
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

bool TaoConnector::DeleteSubdivision(int id)
{
	auto request = GenerateRequest(GenerateUri(L"subdivision/" + id + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}
bool TaoConnector::DeleteEnterprise(int id)
{
	auto request = GenerateRequest(GenerateUri(L"enterprise/" + id + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}
bool TaoConnector::DeleteResident(String^ phone)
{
	auto request = GenerateRequest(GenerateUri(L"user/" + phone + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}
bool TaoConnector::DeleteOperator(int id)
{
	auto request = GenerateRequest(GenerateUri(L"user/" + id + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}
bool TaoConnector::DeleteHouse(int id)
{
	auto request = GenerateRequest(GenerateUri(L"house/" + id + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}
bool TaoConnector::DeleteCarport(int id)
{
	auto request = GenerateRequest(GenerateUri(L"carport/" + id + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}

bool TaoConnector::DeleteChargeTemplate(int id)
{
	auto request = GenerateRequest(GenerateUri(L"charge_template/" + id + "/"), HttpMethod::Delete, GetBase64Cred());
	//bool isSucceeded = false;
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)mutable
			{
				//isSucceeded = result->Succeeded;
			});
	return true;
}

bool TaoConnector::AddHouse(
	String^ subdivisionid, //int
	String^ proprietorid,
	String^ note,
	String^ no,
	String^ netFloorArea, //float
	String^ grossFloorArea, //float
	String^ building,
	String^ unit, //int
	String^ floor, //int
	String^ houseStatus,
	String^ layout,
	String^ direction)
{
	JsonObject^ requestJson = ref new JsonObject();
	if(subdivisionid != L"")
		requestJson->Insert("subdivision", JsonValue::CreateNumberValue(stoi(subdivisionid->Data())));
	if (proprietorid != L"")
		requestJson->Insert("proprietor", JsonArray::Parse("[" + proprietorid + "]"));
	if (note != L"")
		requestJson->Insert("note", JsonValue::CreateStringValue(note));
	if (no != L"")
		requestJson->Insert("no", JsonValue::CreateStringValue(no));
	if (netFloorArea != L"")
		requestJson->Insert("netFloorArea", JsonValue::CreateNumberValue(stof(netFloorArea->Data())));
	if (grossFloorArea != L"")
		requestJson->Insert("grossFloorArea", JsonValue::CreateNumberValue(stof(grossFloorArea->Data())));
	if (building != L"")
		requestJson->Insert("building", JsonValue::CreateStringValue(building));
	if (unit != L"")
		requestJson->Insert("unit", JsonValue::CreateNumberValue(stoi(unit->Data())));
	if (floor != L"")
		requestJson->Insert("floor", JsonValue::CreateNumberValue(stoi(floor->Data())));
	if (houseStatus != L"")
		requestJson->Insert("houseStatus", JsonValue::CreateStringValue(houseStatus));
	if (layout != L"")
		requestJson->Insert("layout", JsonValue::CreateStringValue(layout));
	if (direction != L"")
		requestJson->Insert("direction", JsonValue::CreateStringValue(direction));
	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri(L"house/"), HttpMethod::Post, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;					
				}
			});
	return true;
}

bool TaoConnector::AddCarport(
	String^ subdivisionid, //int
	String^ proprietorid,
	String^ note,
	String^ no)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (subdivisionid != L"")
		requestJson->Insert("subdivision", JsonValue::CreateNumberValue(stoi(subdivisionid->Data())));
	if (proprietorid != L"")
		requestJson->Insert("proprietor", JsonArray::Parse("[" + proprietorid + "]"));
	if (note != L"")
		requestJson->Insert("note", JsonValue::CreateStringValue(note));
	if (no != L"")
		requestJson->Insert("no", JsonValue::CreateStringValue(no));
	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri(L"carport/"), HttpMethod::Post, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::AddSubdivision(
	String^ name,
	String^ enterprise, //int
	String^ operators)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (name != L"")
		requestJson->Insert("name", JsonValue::CreateStringValue(name));
	if (enterprise != L"")
		requestJson->Insert("enterprise", JsonValue::CreateNumberValue(stoi(enterprise->Data())));
	if (operators != L"")
		requestJson->Insert("operator", JsonArray::Parse("[" + operators + "]"));
	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri(L"subdivision/"), HttpMethod::Post, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::AddResidnet(
	String^ name,
	String^ email,
	String^ phone,
	String^ password)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (name != L"")
		requestJson->Insert("name", JsonValue::CreateStringValue(name));
	if (email != L"")
		requestJson->Insert("email", JsonValue::CreateStringValue(email));
	if (phone != L"")
		requestJson->Insert("phone", JsonValue::CreateStringValue(phone));	
		requestJson->Insert("username", JsonValue::CreateStringValue(phone));
	if (password != L"")
		requestJson->Insert("password", JsonValue::CreateStringValue(password));
	requestJson->Insert("is_active", JsonValue::CreateNumberValue(1));
	requestJson->Insert("is_staff", JsonValue::CreateNumberValue(0));

	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri(L"user/"), HttpMethod::Post, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::AddChargeTemplate(
	String^ subdivisionId, //int
	String^ name,
	String^ chargeType,
	String^ unitPrice, //float
	String^ billingCycle //int 
)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (subdivisionId != L"")
		requestJson->Insert("subdivision", JsonValue::CreateNumberValue(stoi(subdivisionId->Data())));
	if (name != L"")
		requestJson->Insert("name", JsonValue::CreateStringValue(name));
	if (chargeType != L"")
		requestJson->Insert("chargeType", JsonValue::CreateStringValue(chargeType));
	if (unitPrice != L"")
		requestJson->Insert("unitPrice", JsonValue::CreateNumberValue(stof(unitPrice->Data())));
	if (billingCycle != L"")
		requestJson->Insert("billingCycle", JsonValue::CreateNumberValue(stoi(billingCycle->Data())));

	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri(L"charge_template/"), HttpMethod::Post, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::PatchResident(
	String^ id,
	String^ name,
	String^ email,
	String^ phone,
	String^ password)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (name != L"")
		requestJson->Insert("name", JsonValue::CreateStringValue(name));
	if (email != L"")
		requestJson->Insert("email", JsonValue::CreateStringValue(email));
	if (phone != L"")
		requestJson->Insert("phone", JsonValue::CreateStringValue(phone));
	requestJson->Insert("username", JsonValue::CreateStringValue(phone));
	if (password != L"")
		requestJson->Insert("password", JsonValue::CreateStringValue(password));
	//requestJson->Insert("is_active", JsonValue::CreateNumberValue(1));
	//requestJson->Insert("is_staff", JsonValue::CreateNumberValue(0));

	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri("user/" + id + "/"), HttpMethod::Patch, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::PatchHouse(
	String^ id,
	String^ subdivisionid, //int
	String^ proprietorid,
	String^ note,
	String^ no,
	String^ netFloorArea, //float
	String^ grossFloorArea, //float
	String^ building,
	String^ unit, //int
	String^ floor, //int
	String^ houseStatus,
	String^ layout,
	String^ direction)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (subdivisionid != L"")
		requestJson->Insert("subdivision", JsonValue::CreateNumberValue(stoi(subdivisionid->Data())));
	if (proprietorid != L"")
		requestJson->Insert("proprietor", JsonArray::Parse("[" + proprietorid + "]"));
	if (note != L"")
		requestJson->Insert("note", JsonValue::CreateStringValue(note));
	if (no != L"")
		requestJson->Insert("no", JsonValue::CreateStringValue(no));
	if (netFloorArea != L"")
		requestJson->Insert("netFloorArea", JsonValue::CreateNumberValue(stof(netFloorArea->Data())));
	if (grossFloorArea != L"")
		requestJson->Insert("grossFloorArea", JsonValue::CreateNumberValue(stof(grossFloorArea->Data())));
	if (building != L"")
		requestJson->Insert("building", JsonValue::CreateStringValue(building));
	if (unit != L"")
		requestJson->Insert("unit", JsonValue::CreateNumberValue(stoi(unit->Data())));
	if (floor != L"")
		requestJson->Insert("floor", JsonValue::CreateNumberValue(stoi(floor->Data())));
	if (houseStatus != L"")
		requestJson->Insert("houseStatus", JsonValue::CreateStringValue(houseStatus));
	if (layout != L"")
		requestJson->Insert("layout", JsonValue::CreateStringValue(layout));
	if (direction != L"")
		requestJson->Insert("direction", JsonValue::CreateStringValue(direction));
	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri("house/" + id + "/"), HttpMethod::Patch, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::PatchCarport(
	String^ id, 
	String^ subdivisionid, //int
	String^ proprietorid,
	String^ note,
	String^ no)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (subdivisionid != L"")
		requestJson->Insert("subdivision", JsonValue::CreateNumberValue(stoi(subdivisionid->Data())));
	if (proprietorid != L"")
		requestJson->Insert("proprietor", JsonArray::Parse("[" + proprietorid + "]"));
	if (note != L"")
		requestJson->Insert("note", JsonValue::CreateStringValue(note));
	if (no != L"")
		requestJson->Insert("no", JsonValue::CreateStringValue(no));
	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri("carport/" + id + "/"), HttpMethod::Patch, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::PatchSubdivision(
	String^ id,
	String^ name,
	String^ enterprise, //int
	String^ operators)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (name != L"")
		requestJson->Insert("name", JsonValue::CreateStringValue(name));
	if (enterprise != L"")
		requestJson->Insert("enterprise", JsonValue::CreateNumberValue(stoi(enterprise->Data())));
	if (operators != L"")
		requestJson->Insert("operator", JsonArray::Parse("[" + operators + "]"));
	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri("subdivision/" + id + "/"), HttpMethod::Patch, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}

bool TaoConnector::PatchChargeTemplate(
	String^ id,
	String^ subdivisionId, //int
	String^ name,
	String^ chargeType,
	String^ unitPrice, //float
	String^ billingCycle //int 
)
{
	JsonObject^ requestJson = ref new JsonObject();
	if (subdivisionId != L"")
		requestJson->Insert("subdivision", JsonValue::CreateNumberValue(stoi(subdivisionId->Data())));
	if (name != L"")
		requestJson->Insert("name", JsonValue::CreateStringValue(name));
	if (chargeType != L"")
		requestJson->Insert("chargeType", JsonValue::CreateStringValue(chargeType));
	if (unitPrice != L"")
		requestJson->Insert("unitPrice", JsonValue::CreateNumberValue(stof(unitPrice->Data())));
	if (billingCycle != L"")
		requestJson->Insert("billingCycle", JsonValue::CreateNumberValue(stoi(billingCycle->Data())));

	HttpStringContent^ requestContent = ref new HttpStringContent(requestJson->ToString());
	auto request = GenerateRequest(GenerateUri(L"charge_template/" + id + "/"), HttpMethod::Patch, GetBase64Cred());
	request->Content = requestContent;
	request->Content->Headers->ContentType = ref new HttpMediaTypeHeaderValue("application/json");
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					true;
				}
			});
	return true;
}