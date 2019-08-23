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
		public ref class House sealed
		{
		private:
			int id;
			int subdivisionid;
			IVector<int>^ proprietorid;
			Platform::String^ note;
			Platform::String^ no; //√≈≈∆∫≈
			float netFloorArea;
			float grossFloorArea;
			Platform::String^ building;
			int unit;
			int floor;
			Platform::String^ houseStatus;
			Platform::String^ layout;
			Platform::String^ direction;
		public:
			House(int id,
				int subdivisionid,
				IVector<int>^ proprietorid,
				Platform::String^ note,
				Platform::String^ no,
				float netFloorArea,
				float grossFloorArea,
				Platform::String^ building,
				int unit,
				int floor,
				Platform::String^ houseStatus,
				Platform::String^ layout,
				Platform::String^ direction):
				id {id},
				subdivisionid{ subdivisionid },
				proprietorid{ proprietorid },
				note { note },
				no { no },
				netFloorArea { netFloorArea },
				grossFloorArea { grossFloorArea },
				building { building },
				unit { unit },
				floor { floor },
				houseStatus { houseStatus },
				layout { layout },
				direction { direction }
			{}
			House(int subdivisionid,
				IVector<int>^ proprietorid,
				Platform::String^ note,
				Platform::String^ no,
				float netFloorArea,
				float grossFloorArea,
				Platform::String^ building,
				int unit,
				int floor,
				Platform::String^ houseStatus,
				Platform::String^ layout,
				Platform::String^ direction) :
				subdivisionid{ subdivisionid },
				proprietorid{ proprietorid },
				note{ note },
				no{ no },
				netFloorArea{ netFloorArea },
				grossFloorArea{ grossFloorArea },
				building{ building },
				unit{ unit },
				floor{ floor },
				houseStatus{ houseStatus },
				layout{ layout },
				direction{ direction }
			{}
			bool Delete();
			property int getid
			{
				int get() { return id; }
			}
			property int getsubdivisionid
			{
				int get() { return this->subdivisionid; }
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
			property Platform::String^ getproprietorid
			{
				Platform::String^ get()
				{
					Platform::String^ re = L"[";
					if (proprietorid->Size > 0)
						re += proprietorid->GetAt(0);
					for (int i = 1; i < proprietorid->Size; ++i)
					{					
						re += "," + proprietorid->GetAt(i);
					}
					re += "]";
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
			property float getNetFloorArea
			{
				float get() { return this->netFloorArea; }
			}
			property float getGrossFloorArea
			{
				float get() { return this->grossFloorArea; }
			}
			property Platform::String^ getbuilding
			{
				Platform::String^ get() { return this->building; }
			}
			property int getunit
			{
				int get() { return this->unit; }
			}
			property int getfloor
			{
				int get() { return floor; }
			}
			property Platform::String^ getHouseStatus
			{
				Platform::String^ get() 
				{
					if (this->houseStatus == L"normal")
						return L"’˝≥£";
					return this->houseStatus;
				}
			}
			property Platform::String^ getlayout
			{
				Platform::String^ get() { return this->layout; }
			}
			property Platform::String^ getdirection
			{
				Platform::String^ get() { return this->direction; }
			}
		};
		public ref class HouseViewModel sealed
		{
		private:
			static IObservableVector<House^>^ houses;
		public:
			HouseViewModel();
			static property IObservableVector<House^>^ Houses
			{
				IObservableVector<House^>^ get();
			}
		};

	}
}