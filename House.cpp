#include "pch.h"
#include "House.h"

IObservableVector<House^>^ HouseViewModel::houses;

HouseViewModel::HouseViewModel()
{
	Platform::Collections::Vector<int>^ proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(1);
	House^ thehouse = ref new House(1, 1, proprietor, L"", L"1-1-702", 100, 120, L"一栋", L"一单元", 7, L"正常", L"三室一厅", L"坐北朝南");
	Houses->Append(thehouse);

	proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(2);
	proprietor->Append(3);
	thehouse = ref new House(1, 1, proprietor, L"", L"1-1-701", 80, 100, L"一栋", L"一单元", 7, L"闲置", L"三室一厅", L"坐北朝南");
	Houses->Append(thehouse);
}