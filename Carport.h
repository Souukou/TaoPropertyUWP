#pragma once
#include <sstream>
#include "Resident.h"
#include "Subdivision.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class Carport sealed
		{
		private:
			int id;
			int subdivisionid;
			IVector<int>^ proprietorid;
			Platform::String^ note;
			Platform::String^ no;
		
		public:
			Carport(int id,
				int subdivisionid,
				IVector<int>^ proprietorid,
				Platform::String^ note,
				Platform::String^ no):
				id {id},
				subdivisionid { subdivisionid },
				proprietorid { proprietorid },
				note { note },
				no { no }
			{}
			property int getid
			{
				int get() { return id; }
			}
			property Platform::String^ getsubdivisionname
			{
				Platform::String^ get()
				{
					for (int i = 0; i < SubdivisionViewModel::Subdivisions->Size; ++i)
					{
						if (SubdivisionViewModel::Subdivisions->GetAt(i)->getid == subdivisionid)
						{
							return SubdivisionViewModel::Subdivisions->GetAt(i)->getname;
						}
					}
					return L"";
				}
			}
			property Platform::String^ getproprietorname
			{
				Platform::String^ get()
				{
					Platform::String^ re = L"";
					for (int i = 0; i < proprietorid->Size; ++i)
					{
						int curr_proprietorid = proprietorid->GetAt(i);
						for (int j = 0; j < ResidentViewModel::Residents->Size; ++j)
						{
							if (ResidentViewModel::Residents->GetAt(j)->getid == curr_proprietorid)
							{
								re += ResidentViewModel::Residents->GetAt(j)->getname + L" ";
							}
						}
					}
					return re;
				}
			}
			property Platform::String^ getnote
			{
				Platform::String^ get() { return this->note; }
			}
			property Platform::String^ getno
			{
				Platform::String^ get() { return this->no; }
			}
		};

		public ref class CarportViewModel sealed
		{
		private:
			static IObservableVector<Carport^>^ carports;
		public:
			CarportViewModel();
			static property IObservableVector<Carport^>^ Carports
			{
				IObservableVector<Carport^>^ get();
			}
		};
	}

}
