#pragma once
#include <cstdlib>

namespace TaoPropertyUWP
{
	namespace Models {
		public ref class Subdivision sealed
		{
		private:
			int id;
			Platform::String^ name;
		public:
			Subdivision(int id, Platform::String^ name): id{ id }, name{ name } {}
			
			property int getid
			{
				int get() { return id; };
			}
			
			property Platform::String^ getname
			{
				Platform::String^ get() { return this->name; }
			}

		};

		public ref class SubdivisionViewModel sealed
		{
		private:
			//Subdivision^ defaultSubdivision;
			Windows::Foundation::Collections::IObservableVector<Subdivision^>^ subdivisions;
		public:
			SubdivisionViewModel()
			{
				Subdivision^ subdivision = ref new Subdivision(1, L"TT1");
				this->Subdivisions->Append(subdivision);
				subdivision = ref new Subdivision(2, L"TT2");
				this->Subdivisions->Append(subdivision);
				subdivision = ref new Subdivision(3, L"TT3");
				this->Subdivisions->Append(subdivision);
			}
			property Windows::Foundation::Collections::IVector<Subdivision^>^ Subdivisions
			{
				Windows::Foundation::Collections::IVector<Subdivision^>^ get()
				{
					if (this->subdivisions == nullptr)
					{
						this->subdivisions = ref new Platform::Collections::Vector<Subdivision^>();
					}
					return this->subdivisions;
				};
			}
		};
	}
}