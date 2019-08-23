#include "pch.h"
#include "Subdivision.h"
#include "TaoConnector.h"
using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

IObservableVector<Subdivision^>^ SubdivisionViewModel::subdivisions;


bool Subdivision::Delete()
{
	bool ret = TaoConnector::DeleteSubdivision(this->id);
	if (ret)
	{
		int theDeleteOne = -1;
		for (int i = 0; i < SubdivisionViewModel::Subdivisions->Size; ++i)
		{
			if (SubdivisionViewModel::Subdivisions->GetAt(i)->getid == this->id)
			{
				theDeleteOne = i;
				break;
			}
		}
		if (theDeleteOne != -1)
		{
			SubdivisionViewModel::Subdivisions->RemoveAt(theDeleteOne);
		}
	}
	return ret;
}

SubdivisionViewModel::SubdivisionViewModel()
{

}

IObservableVector<Subdivision^>^ SubdivisionViewModel::Subdivisions::get()
{
	if (subdivisions == nullptr)
	{
		subdivisions = ref new Platform::Collections::Vector<Subdivision^>();
		TaoConnector::RefreshSubdivisions();
	}
	return subdivisions;
}
