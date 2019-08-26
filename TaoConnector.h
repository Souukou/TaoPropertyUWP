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
#include "Bill.h"
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
using namespace std;

namespace TaoPropertyUWP
{
	public ref class TaoConnector sealed
	{
	private:
		static String^ username;
		static String^ password;
		static Windows::Foundation::Uri^ BaseUri;
		static Windows::Web::Http::HttpClient^ httpClient;
	public:
		static property String^ UserName
		{
			String^ get() { return username; }
			void set(String^ e) { username = e; }
		}
		static property String^ PassWord
		{
			String^ get() {	return password; }
			void set(String^ e) { password = e; }
		}
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
		static void RefreshBills();
		static bool DeleteSubdivision(int id);
		static bool DeleteEnterprise(int id);
		static bool DeleteResident(String^);
		static bool DeleteOperator(int id);
		static bool DeleteHouse(int id);
		static bool DeleteCarport(int id);
		static bool DeleteChargeTemplate(int id);
		static bool DeleteBill(int id);
		static bool AddEnterprise(String^);
		static bool AddHouse(String^,String^,String^,String^,String^,String^,
			String^,String^,String^,String^,String^,String^);
		static bool AddCarport(String^, String^, String^, String^);
		static bool AddSubdivision(String^, String^, String^);
		static bool AddResidnet(String^, String^, String^, String^);
		static bool AddOperator(String^, String^, String^, String^);
		static bool AddChargeTemplate(String^, String^, String^, String^, String^);
		static bool AddBill(String^, String^, String^, String^, String^, 
			String^, String^, String^, String^, String^, String^);
		static bool AddTransaction(String^, String^, String^, String^, String^, String^);
		static bool PatchHouse(String^, String^, String^, String^, String^, String^, String^,
			String^, String^, String^, String^, String^, String^);
		static bool PatchCarport(String^, String^, String^, String^, String^);
		static bool PatchSubdivision(String^, String^, String^, String^);
		static bool PatchChargeTemplate(String^, String^, String^, String^, String^, String^);
		static bool PatchResident(String^, String^, String^, String^, String^);
		static bool PatchEnterprise(String^, String^, String^);
		static bool PatchBill(String^, String^, String^, String^, String^, String^,
			String^, String^, String^, String^, String^, String^);
		static void SearchHouses(String^);
	};

}



