#include "pch.h"
#include "House.h"

IObservableVector<House^>^ HouseViewModel::houses;

HouseViewModel::HouseViewModel()
{
	House^ thehouse = ref new House(1, 1, 1, L"", L"1-1-702", 100, 120, L"һ��", L"һ��Ԫ", 7, L"����", L"����һ��", L"��������");
	Houses->Append(thehouse);

	thehouse = ref new House(1, 1, 2, L"", L"1-1-701", 80, 100, L"һ��", L"һ��Ԫ", 7, L"����", L"����һ��", L"��������");
	Houses->Append(thehouse);
}