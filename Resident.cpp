#include "pch.h"
#include "Resident.h"
using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

IObservableVector<Resident^> ^ ResidentViewModel::residents;

ResidentViewModel::ResidentViewModel()
{
	Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar();
	createTime->Year = 2019;
	createTime->Month = 1;
	createTime->Day = 1;
	Resident^ resident = ref new Resident(1, L"A", L"1@qq.com", L"158", createTime);
	this->Residents->Append(resident);
	resident = ref new Resident(2, L"B", L"2@qq.com", L"135", createTime);
	this->Residents->Append(resident);
	resident = ref new Resident(3, L"C", L"3@qq.com", L"189", createTime);
	this->Residents->Append(resident);
}