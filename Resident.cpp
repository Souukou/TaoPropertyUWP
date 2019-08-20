#include "pch.h"
#include "Resident.h"
#include "TaoConnector.h"
using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

IObservableVector<Resident^> ^ ResidentViewModel::residents;

ResidentViewModel::ResidentViewModel()
{
	
}

IObservableVector<Resident^>^ ResidentViewModel::Residents::get()
{
	if (residents == nullptr)
	{
		residents = ref new Platform::Collections::Vector<Resident^>();
		TaoConnector::RefreshResidents();
	}
	return residents;
}