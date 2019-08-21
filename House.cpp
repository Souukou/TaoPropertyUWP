#include "pch.h"
#include "House.h"
#include "TaoConnector.h"
IObservableVector<House^>^ HouseViewModel::houses;

HouseViewModel::HouseViewModel()
{

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

bool House::Delete()
{
	bool ret = TaoConnector::DeleteHouse(this->id);
	if (ret)
	{
		int theDeleteOne = -1;
		for (int i = 0; i < HouseViewModel::Houses->Size; ++i)
		{
			if (HouseViewModel::Houses->GetAt(i)->getid == this->id)
			{
				theDeleteOne = i;
				break;
			}
		}
		if (theDeleteOne != -1)
		{
			HouseViewModel::Houses->RemoveAt(theDeleteOne);
		}
		
	}
	return ret;
}