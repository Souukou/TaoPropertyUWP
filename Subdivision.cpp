#include "pch.h"
#include "Subdivision.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

IObservableVector<Subdivision^>^ SubdivisionViewModel::subdivisions;

SubdivisionViewModel::SubdivisionViewModel()
{
	Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar();
	createTime->Year = 2019;
	createTime->Month = 1;
	createTime->Day = 1;

	Windows::Foundation::Collections::IVector<int>^ theoperator = ref new Platform::Collections::Vector<int>();
	theoperator->Append(1);

	Subdivision^ subdivision = ref new Subdivision(1, L"桃桃A小区", createTime, 1, theoperator);
	Subdivisions->Append(subdivision);

	theoperator = ref new Platform::Collections::Vector<int>();
	theoperator->Append(1);
	theoperator->Append(2);

	subdivision = ref new Subdivision(2, L"桃桃B小区", createTime, 1, theoperator);
	Subdivisions->Append(subdivision);

	theoperator = ref new Platform::Collections::Vector<int>();
	theoperator->Append(2);
	theoperator->Append(3);
	subdivision = ref new Subdivision(3, L"桃桃C小区", createTime, 1, theoperator);
	Subdivisions->Append(subdivision);
}

