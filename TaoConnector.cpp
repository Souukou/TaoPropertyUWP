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
						Platform::String^ nowName = nowJson->Lookup("name")->GetString();
						int nowId = nowJson->Lookup("id")->GetNumber();
						int nowEnterpriseId = nowJson->Lookup("enterprise")->GetNumber();
						Platform::String^ createTime = nowJson->Lookup("createdTime")->GetString();

						auto operatorArray = nowJson->Lookup("operator")->GetArray();
						Platform::Collections::Vector<int>^ nowOperator = ref new Platform::Collections::Vector<int>();
						for (int j = 0; j < operatorArray->Size; ++j)
						{
							nowOperator->Append(operatorArray->GetNumberAt(j));
						}

						//Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar(createdTime);



						SubdivisionViewModel::Subdivisions->Append(ref new Subdivision(nowId, nowName, createTime, nowEnterpriseId, nowOperator));

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
