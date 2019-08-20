#include "pch.h"
#include "Enterprise.h"
#include "TaoConnector.h"

IObservableVector<Enterprise^>^ EnterpriseViewModel::enterprises;

EnterpriseViewModel::EnterpriseViewModel()
{

}

IObservableVector<Enterprise^>^ EnterpriseViewModel::Enterprises::get()
{
	if (enterprises == nullptr)
	{
		enterprises = ref new Platform::Collections::Vector<Enterprise^>();
		TaoConnector::RefreshEnterprises();
	}
	return enterprises;
}
