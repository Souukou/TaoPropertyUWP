#pragma once

using namespace Windows::Foundation::Collections;


namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class Operator sealed
		{
		private:
			int id;
			Platform::String^ name;
			Platform::String^ email;
			Platform::String^ phone;
			Platform::String^ createTime;
		public:
			Operator(int id,
				Platform::String^ name,
				Platform::String^ email,
				Platform::String^ phone,
				Platform::String^ createTime) :
				id{ id },
				name{ name },
				phone{ phone },
				email{ email },
				createTime{ createTime }{}
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
			property  Platform::String^ getcreatetime
			{
				Platform::String^ get() { return this->createTime; }
				//void set(Windows::Globalization::Calendar^ createTime) { this->createTime = createTime; }
			}

		};

		public ref class OperatorViewModel sealed
		{
		private:
			static IObservableVector<Operator^>^ operators;
		public:
			OperatorViewModel();
			static property IObservableVector<Operator^>^ Operators
			{
				IObservableVector<Operator^>^ get();
			}
		};

	}
}