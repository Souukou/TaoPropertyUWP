#include "pch.h"
#include "Operator.h"
#include "TaoConnector.h"

using namespace TaoPropertyUWP::Models;
IObservableVector<Operator^>^ OperatorViewModel::operators;

OperatorViewModel::OperatorViewModel()
{
	
}

IObservableVector<Operator^>^ OperatorViewModel::Operators::get()
{
	if (operators == nullptr)
	{
		operators = ref new Platform::Collections::Vector<Operator^>();
		TaoConnector::RefreshOperators();
	}
	return operators;
}
