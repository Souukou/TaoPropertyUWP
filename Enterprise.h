#pragma once
#include <sstream>
#include "Operator.h"

using namespace Windows::Foundation::Collections;
using namespace TaoPropertyUWP::Models;

namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class Enterprise sealed
		{
		private:
			int id;
			Platform::String^ name;
			Platform::String^ createTime;
			int founderid;
			IVector<int>^ managers;
			static Platform::String^ get_operator_name(int operator_id)
			{
				int thesize = OperatorViewModel::Operators->Size;
				for (int i = 0; i < thesize; ++i)
				{
					if (OperatorViewModel::Operators->GetAt(i)->getid == operator_id)
						return OperatorViewModel::Operators->GetAt(i)->getname;
				}
				return L"";
			}

		public:
			Enterprise(
				int id,
				Platform::String^ name,
				Platform::String^ createTime,
				int founder,
				IVector<int>^ operators) :
				id{ id },
				name{ name },
				createTime{ createTime },
				founderid{ founderid },
				managers{ managers } {}
			property int getid
			{
				int get() { return id; };
			}
			property Platform::String^ getname
			{
				Platform::String^ get() { return this->name; }
			}
			property Platform::String^ getcreatetime
			{
				Platform::String^ get() { return this->createTime; }
			}
			property Platform::String^ getfounder
			{
				Platform::String^ get()
				{
					return get_operator_name(founderid);
				}
			}
			property int getfounderid
			{
				int get()
				{
					return this->founderid;
				}
			}
			property Platform::String^ getmanagername
			{
				Platform::String^ get()
				{
					int thesize = managers->Size;
					if (thesize == 0)
					{
						return L"нч";
					}
					std::wstringstream wstringstream;
					wstringstream << '[' << thesize << "] ";
					Platform::String^ re = ref new Platform::String();
					for (int i = 0; i < thesize; ++i)
						re += get_operator_name(managers->GetAt(i)) + L" ";

					return ref new Platform::String(wstringstream.str().c_str()) + re;
				}
			}
		};

		public ref class EnterpriseViewModel sealed
		{
		private:
			static IObservableVector<Enterprise^>^ enterprises;
		public:
			EnterpriseViewModel();
			static property IObservableVector<Enterprise^>^ Enterprises
			{
				IObservableVector<Enterprise^>^ get();
			}
		};
	}
}