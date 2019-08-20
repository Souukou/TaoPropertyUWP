#pragma once
#include <sstream>
#include "Operator.h"
#include "Enterprise.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

namespace TaoPropertyUWP
{
	namespace Models 
	{
		public ref class Subdivision sealed
		{
		private:
			int id;
			Platform::String^ name;
			Platform::String^ createTime;
			int enterprise;
			IVector<int>^ operators;
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
			Subdivision(
				int id, 
				Platform::String^ name,
				Platform::String^ createTime,
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
			property Platform::String^ getcreatetime
			{
				Platform::String^ get() { return this->createTime; }
			}
			property Platform::String^ getenterprisename
			{
				Platform::String^ get()
				{
					for (int i = 0; i < EnterpriseViewModel::Enterprises->Size; ++i)
						if (EnterpriseViewModel::Enterprises->GetAt(i)->getid == enterprise)
							return EnterpriseViewModel::Enterprises->GetAt(i)->getname;
					return L"";

				}
			}
			property Platform::String^ getoperatorname
			{
				Platform::String^ get()
				{
					int thesize = operators->Size;
					if (thesize == 0)
					{
						return L"нч";
					}
					std::wstringstream wstringstream;
					wstringstream << '[' << thesize << "] ";
					Platform::String^ re = ref new Platform::String();
					for (int i = 0; i < thesize; ++i)
						re += get_operator_name(operators->GetAt(i)) + L" ";
						
					return ref new Platform::String(wstringstream.str().c_str()) + re;
				}
			}

		};

		public ref class SubdivisionViewModel sealed
		{
		private:
			static IObservableVector<Subdivision^>^ subdivisions;
		public:
			SubdivisionViewModel();
			static property IObservableVector<Subdivision^>^ Subdivisions
			{
				IObservableVector<Subdivision^>^ get();
			}
		};
	}
}