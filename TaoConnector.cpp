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