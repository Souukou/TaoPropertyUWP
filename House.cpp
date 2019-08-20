#include "pch.h"
#include "House.h"
#include "TaoConnector.h"
IObservableVector<House^>^ HouseViewModel::houses;

HouseViewModel::HouseViewModel()
{
	TaoConnector::RefreshHouses();
}

IObservableVector<House^>^ HouseViewModel::Houses::get()
{
	if (houses == nullptr)
	{
		houses = ref new Platform::Collections::Vector<House^>();
		TaoConnector::RefreshHouses();
	}
	return houses;
}