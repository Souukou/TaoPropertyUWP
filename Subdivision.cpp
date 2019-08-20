#include "pch.h"
#include "Subdivision.h"
#include "TaoConnector.h"
using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

IObservableVector<Subdivision^>^ SubdivisionViewModel::subdivisions;

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