#pragma once

namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class Resident sealed
		{
		private:
			int id;
			Platform::String^ name;
			Platform::String^ email;
			Platform::String^ phone;
			Windows::Globalization::Calendar^ createTime;
		public:
			Resident(int id,
				Platform::String^ name,
				Platform::String^ email,
				Platform::String^ phone,
				Windows::Globalization::Calendar^ createTime) :
				id {id},
				name{name},
				phone{phone},
				email{email},
				createTime{createTime}{}
			property int getid
			{
				int get() { return id; }
			}
			property Platform::String^ getname 
			{
				Platform::String^ get() { return this->name; }
				void set(Platform::String^ name) { this->name = name; }
			}
			property Platform::String^ getemail 
			{
				Platform::String^ get() { return this->email; }
				void set(Platform::String^ email) { this->email = email; }
			}
			property Platform::String^ getphone 
			{
				Platform::String^ get() { return this->phone; }
				void set(Platform::String^ phone) { this->phone = phone; }
			}
			property  Windows::Globalization::Calendar^ getcreatetime
			{
				Windows::Globalization::Calendar^ get() { return this->createTime; }
				void set(Windows::Globalization::Calendar^ createTime) { this->createTime = createTime; }
			}
		};

		public ref class ResidentModelView sealed
		{
		private:
			static Windows::Foundation::Collections::IObservableVector<Resident^>^ residents;
		public:
			ResidentModelView()
			{
				Windows::Globalization::Calendar^ createTime = ref new Windows::Globalization::Calendar();
				createTime->Year = 2019;
				createTime->Month = 1;
				createTime->Day = 1;
				Resident^ resident = ref new Resident(1, L"A", L"1@qq.com", L"158", createTime);
				this->Residents->Append(resident);
				resident = ref new Resident(2, L"B", L"2@qq.com", L"135", createTime);
				this->Residents->Append(resident);
				resident = ref new Resident(3, L"C", L"3@qq.com", L"189", createTime);
				this->Residents->Append(resident);
				
			}
			
			static property Windows::Foundation::Collections::IObservableVector<Resident^>^ Residents
			{
				Windows::Foundation::Collections::IObservableVector<Resident^>^ get()
				{
					
					if (residents == nullptr) {
						residents = ref new Platform::Collections::Vector<Resident^>();
					}
					return residents;
					
				}
			}
			
		};
	}
}