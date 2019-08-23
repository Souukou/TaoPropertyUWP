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

bool Resident::Delete()
{
	bool ret = TaoConnector::DeleteResident(this->phone);
	if (ret)
	{
		int theDeleteOne = -1;
		for (int i = 0; i < ResidentViewModel::Residents->Size; ++i)
		{
			if (ResidentViewModel::Residents->GetAt(i)->getid == this->id)
			{
				theDeleteOne = i;
				break;
			}
		}
		if (theDeleteOne != -1)
		{
			ResidentViewModel::Residents->RemoveAt(theDeleteOne);
		}

	}
	return ret;

}