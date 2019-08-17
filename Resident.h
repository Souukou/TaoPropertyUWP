#pragma once

using namespace Windows::Foundation::Collections;

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

		public ref class ResidentViewModel sealed
		{
		private:
			static Windows::Foundation::Collections::IObservableVector<Resident^>^ residents;
		public:
			ResidentViewModel();
			static property IObservableVector<Resident^>^ Residents
			{
				IObservableVector<Resident^>^ get()
				{
					if (residents == nullptr)
					{
						residents = ref new Platform::Collections::Vector<Resident^>();
					}
					return residents;
				}
			}
		};
	}
}