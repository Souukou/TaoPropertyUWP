#include "pch.h"
#include "Enterprise.h"

IObservableVector<Enterprise^>^ EnterpriseViewModel::enterprises;

EnterpriseViewModel::EnterpriseViewModel()
{
	Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar();
	createTime->Year = 2019;
	createTime->Month = 1;
	createTime->Day = 1;

	IVector<int>^ themanager = ref new Platform::Collections::Vector<int>();
	themanager->Append(1);

	Enterprise^ theenterprise = ref new Enterprise(1, L"桃桃物业-1", createTime, 1, themanager);
	Enterprises->Append(theenterprise);

	themanager = ref new Platform::Collections::Vector<int>();
	themanager->Append(1);
	themanager->Append(2);

	theenterprise = ref new Enterprise(2, L"桃桃物业-2", createTime, 1, themanager);
	Enterprises->Append(theenterprise);

}
