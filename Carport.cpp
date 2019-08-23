#include "pch.h"
#include "Carport.h"
#include "TaoConnector.h"

IObservableVector<Carport^>^ CarportViewModel::carports;

bool Carport::Delete()
{
	bool ret = TaoConnector::DeleteCarport(this->id);
	if (ret)
	{
		int theDeleteOne = -1;
		for (int i = 0; i < CarportViewModel::Carports->Size; ++i)
		{
			if (CarportViewModel::Carports->GetAt(i)->getid == this->id)
			{
				theDeleteOne = i;
				break;
			}
		}
		if (theDeleteOne != -1)
		{
			CarportViewModel::Carports->RemoveAt(theDeleteOne);
		}
	}

	return ret;
}

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
