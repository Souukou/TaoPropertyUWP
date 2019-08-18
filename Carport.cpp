#include "pch.h"
#include "Carport.h"

IObservableVector<Carport^>^ CarportViewModel::carports;

CarportViewModel::CarportViewModel()
{
	Platform::Collections::Vector<int>^ proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(1);
	Carport^ thecarport = ref new Carport(1, 1, proprietor, L"出租", L"地面-101");
	Carports->Append(thecarport);

	proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(2);
	proprietor->Append(3);
	thecarport = ref new Carport(2, 1, proprietor, L"私有", L"地下-123");
	Carports->Append(thecarport);

	proprietor = ref new Platform::Collections::Vector<int>();
	proprietor->Append(2);
	proprietor->Append(3);
	thecarport = ref new Carport(3, 1, proprietor, L"私有", L"地下-124");
	Carports->Append(thecarport);

}
