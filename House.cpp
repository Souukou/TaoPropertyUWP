#include "pch.h"
#include "House.h"
#include "TaoConnector.h"
IObservableVector<House^>^ HouseViewModel::houses;

HouseViewModel::HouseViewModel()
{
	TaoConnector::RefreshHouses();
	/*
	Platform::Collections::Vector<int>^ proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(1);
	House^ thehouse = ref new House(1, 1, proprietor, L"", L"1-1-702", 100, 120, L"һ��", L"һ��Ԫ", 7, L"����", L"����һ��", L"��������");
	Houses->Append(thehouse);

	proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(2);
	proprietor->Append(3);
	thehouse = ref new House(1, 1, proprietor, L"", L"1-1-701", 80, 100, L"һ��", L"һ��Ԫ", 7, L"����", L"����һ��", L"��������");
	Houses->Append(thehouse);
	*/
}