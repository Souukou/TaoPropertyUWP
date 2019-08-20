#include "pch.h"
#include "Carport.h"
#include "TaoConnector.h"

IObservableVector<Carport^>^ CarportViewModel::carports;

CarportViewModel::CarportViewModel()
{

}

IObservableVector<Carport^>^ CarportViewModel::Carports::get()
{
	if (carports == nullptr)
	{
		carports = ref new Platform::Collections::Vector<Carport^>();
		TaoConnector::RefreshCarports();
	}
	return carports;
}
