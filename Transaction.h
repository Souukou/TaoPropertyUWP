#pragma once
#include <sstream>
#include "Subdivision.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class Transaction sealed
		{
		private:
			int id;
			int subdivisionid;
			IVector<int>^ bills;
			Platform::String^ ctreateTime;
			float totalCost;
			float feePayable;
			float feeWaiver;
			Platform::String^ paymentMethod;

		public:
			Transaction(
				int id,
				int subdivisionid,
				IVector<int>^ bills,
				Platform::String^ ctreateTime,
				float totalCost,
				float feePayable,
				float feeWaiver,
				Platform::String^ paymentMethod) :
				id{ id },
				subdivisionid{ subdivisionid },
				bills{ bills },
				ctreateTime{ ctreateTime },
				totalCost{ totalCost },
				feePayable{ feePayable },
				feeWaiver{ feeWaiver },
				paymentMethod{ paymentMethod } {}
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
			property Platform::String^ getBills
			{
				Platform::String^ get()
				{
					Platform::String^ re = L"";
					for (int i = 0; i < bills->Size; ++i)
					{
						re += bills->GetAt(i) + L", ";
					}
					return re;
				}
			}
			property Platform::String^ getCtreateTime
			{
				Platform::String^ get() { return this->ctreateTime; }
			}
			property float getTotalCost
			{
				float get() { return this->totalCost; }
			}
			property float getFeePayable
			{
				float get() { return this->feePayable; }
			}
			property float getFeeWaiver
			{
				float get() { return this->feeWaiver; }
			}
			property Platform::String^ getPaymentMethod
			{
				Platform::String^ get()
				{
					if (this->paymentMethod == "Alipay")
					{
						return L"支付宝";
					}
					if (this->paymentMethod == "WeChatPay")
					{
						return L"微信";
					}
					if (this->paymentMethod == "Card")
					{
						return L"银行卡";
					}
					if (this->paymentMethod == "Cash")
					{
						return L"现金";
					}
					return this->paymentMethod;
				}
			}
		};

		public ref class TransactionViewModel sealed
		{
		private:
			static IObservableVector<Transaction^>^ transactions;
		public:
			TransactionViewModel();
			static property IObservableVector<Transaction^>^ Transactions
			{
				IObservableVector<Transaction^>^ get();
			}
		};
	}

}
