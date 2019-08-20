//
// SubdivisionManagePage.xaml.cpp
// Implementation of the SubdivisionManagePage class
//

#include "pch.h"
#include "SubdivisionManagePage.xaml.h"
#include "Subdivision.h"
#include <sstream>

using namespace TaoPropertyUWP;
using namespace Windows::Data::Json;
using namespace concurrency;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Headers;
using namespace Windows::Web::Http::Filters;
using namespace Windows::Security::Cryptography::Certificates;
// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

SubdivisionViewModel^ SubdivisionManagePage::viewModel;

SubdivisionManagePage::SubdivisionManagePage()
{
	InitializeComponent();
	ref new TaoPropertyUWP::Models::OperatorViewModel();
	ref new TaoPropertyUWP::Models::EnterpriseViewModel();
}




void TaoPropertyUWP::SubdivisionManagePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	Windows::Foundation::Uri^ uri = ref new Windows::Foundation::Uri("http://api.tp.tmiao.tech:16000/api/v1/subdivision/");
	std::wstring USERNAME = L"15882381309";
	std::wstring PASSWORD = L"123456";
	std::wstringstream wstringstream;
	wstringstream << USERNAME << ":" << PASSWORD;
	//TESTBLOCK->Text = ref new Platform::String(wstringstream.str().c_str());
	auto buffer = Windows::Security::Cryptography::CryptographicBuffer::ConvertStringToBinary(
		ref new Platform::String(wstringstream.str().c_str()),
		Windows::Security::Cryptography::BinaryStringEncoding::Utf8);
	Platform::String^ base64token = Windows::Security::Cryptography::CryptographicBuffer::EncodeToBase64String(buffer);
	auto request = ref new HttpRequestMessage(HttpMethod::Get, uri);
	request->Headers->Authorization = ref new HttpCredentialsHeaderValue("Basic", base64token);

	httpClient = ref new HttpClient();
	create_task(httpClient->TrySendRequestAsync(request))
		.then([=](HttpRequestResult^ result)
			{
				if (result->Succeeded)
				{
					HttpResponseMessage^ response = result->ResponseMessage;
					//SubTitle->Text = ((UINT32) response->StatusCode).ToString();
					TESTBLOCK->Text = result->ResponseMessage->Content->ToString();
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
					SubTitle->Text = "FAILED";
					//TESTBLOCK->Text = result->ResponseMessage->Content->ToString();
					
					//return task_from_result();
				}
			});


}
