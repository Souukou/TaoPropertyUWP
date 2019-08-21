#pragma once
#include <sstream>
#include "pch.h"
#include "Subdivision.h"
#include "Enterprise.h"
#include "Resident.h"
#include "House.h"
#include "Carport.h"
#include "Operator.h"
#include "ChargeTemplate.h"
#include "Transaction.h"
using namespace TaoPropertyUWP;
using namespace Windows::Data::Json;
using namespace concurrency;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Headers;
using namespace Windows::Web::Http::Filters;
using namespace Windows::Security::Cryptography::Certificates;
namespace TaoPropertyUWP
{
	public ref class TaoConnector sealed
	{
	private:
		static std::wstring username;
		static std::wstring password;
		static Windows::Foundation::Uri^ BaseUri;
		static Windows::Web::Http::HttpClient^ httpClient;
	public:
		
		TaoConnector()
		{

		}
		static Platform::String^ GetBase64Cred();
		static HttpRequestMessage^ GenerateRequest(Uri^ final_uri, HttpMethod^ method, Platform::String^ cred);
		static Uri^ GenerateUri(Platform::String^ subUri);
		static void RefreshSubdivisions();
		static void RefreshEnterprises();
		static void RefreshResidents();
		static void RefreshHouses();
		static void RefreshCarports();
		static void RefreshOperators();
		static void RefreshChargeTemplates();
		static void RefreshTransactions();
		static bool DeleteHouse(int id);
		
	};

}



