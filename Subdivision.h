#pragma once

namespace TaoPropertyUWP
{
	namespace Models 
	{
		public ref class Subdivision sealed
		{
		private:
			int id;
			Platform::String^ name;
			Windows::Globalization::Calendar^ createTime;
			int enterprise;
			Windows::Foundation::Collections::IVector<int>^ operators;
		public:
			Subdivision(
				int id, 
				Platform::String^ name,
				Windows::Globalization::Calendar^ createTime,
				int enterprise,
				Windows::Foundation::Collections::IVector<int>^ operators) :
				id { id }, 
				name { name },
				createTime { createTime },
				enterprise{ enterprise }
				//operators { operators } 
			{
				this->operators = operators;
			}
			
			property int getid
			{
				int get() { return id; };
			}
			property Platform::String^ getname
			{
				Platform::String^ get() { return this->name; }
			}
			property Windows::Globalization::Calendar^ getcreatetime
			{
				Windows::Globalization::Calendar^ get() { return this->createTime; }
			}
			property Platform::String^ getenterprise
			{
				Platform::String^ get()
				{
					return L"1111";
				}
			}
			property Platform::String^ getoperator
			{
				Platform::String^ get()
				{
					return L"1111";
				}
			}

		};

		public ref class SubdivisionViewModel sealed
		{
		private:
			static Windows::Foundation::Collections::IObservableVector<Subdivision^>^ subdivisions;
		public:
			SubdivisionViewModel()
			{
				Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar();
				createTime->Year = 2019;
				createTime->Month = 1;
				createTime->Day = 1;

				Windows::Foundation::Collections::IVector<int>^ theoperator = ref new Platform::Collections::Vector<int>();
				theoperator->Append(1);

				Subdivision^ subdivision = ref new Subdivision(1, L"桃桃A小区", createTime, 1, theoperator);
				Subdivisions->Append(subdivision);

				theoperator = ref new Platform::Collections::Vector<int>();
				theoperator->Append(1);
				theoperator->Append(2);

				subdivision = ref new Subdivision(2, L"桃桃B小区", createTime, 1, theoperator);
				Subdivisions->Append(subdivision);

				theoperator = ref new Platform::Collections::Vector<int>();
				theoperator->Append(1);
				theoperator->Append(2);
				subdivision = ref new Subdivision(3, L"桃桃C小区", createTime, 1, theoperator);
				Subdivisions->Append(subdivision);
			}
			static property Windows::Foundation::Collections::IObservableVector<Subdivision^>^ Subdivisions
			{
				Windows::Foundation::Collections::IObservableVector<Subdivision^>^ get()
				{
					if (subdivisions == nullptr)
					{
						subdivisions = ref new Platform::Collections::Vector<Subdivision^>();
					}
					return subdivisions;
				};
			}
		};
	}
}