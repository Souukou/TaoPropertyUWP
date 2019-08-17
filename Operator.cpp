#include "pch.h"
#include "Operator.h"

using namespace TaoPropertyUWP::Models;
IObservableVector<Operator^>^ OperatorViewModel::operators;

OperatorViewModel::OperatorViewModel()
{
	Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar();
	createTime->Year = 2019;
	createTime->Month = 1;
	createTime->Day = 1;
	Operator^ theoperator = ref new Operator(1, L"����", L"1@qq.com", L"158", createTime);
	this->Operators->Append(theoperator);
	theoperator = ref new Operator(2, L"����", L"2@qq.com", L"135", createTime);
	this->Operators->Append(theoperator);
	theoperator = ref new Operator(3, L"����", L"3@qq.com", L"189", createTime);
	this->Operators->Append(theoperator);
}
