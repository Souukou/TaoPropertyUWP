#pragma once
#include <sstream>
#include "Operator.h"
#include "Subdivision.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;
using namespace Platform;

namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class Bill sealed
		{
		private:
			int id;
			int propertyId;
			String^ name;
			String^ createdTime;
			String^ startTime;
			String^ endTime;
			String^ dueTime;
			float unitPrice;
			float quantity;
			float totalCost;
			float feePayable;
			float feeWaiver;
			bool isPaid;
		public:
			Bill(
				int id,
				int propertyId,
				String^ name,
				String^ createdTime,
				String^ startTime,
				String^ endTime,
				String^ dueTime,
				float unitPrice,
				float quantity,
				float totalCost,
				float feePayable,
				float feeWaiver,
				bool isPaid) :
				id{ id },
				propertyId{ propertyId },
				name{ name },
				createdTime{ createdTime },
				startTime{ startTime },
				endTime{ endTime },
				dueTime{ dueTime },
				unitPrice{ unitPrice },
				quantity{ quantity },
				totalCost{ totalCost },
				feePayable{ feePayable },
				feeWaiver{ feeWaiver },
				isPaid{ isPaid } {}

			property int getId
			{
				int get() { return id; };
			}
			property int getPropertyId
			{
				int get() { return propertyId; };
			}
			property Platform::String^ getName
			{
				Platform::String^ get() { return this->name; }
			}
			property Platform::String^ getCreatedTime
			{
				Platform::String^ get() { return this->createdTime; }
			}
			property Platform::String^ getStartTime
			{
				Platform::String^ get() { return this->startTime; }
			}
			property Platform::String^ getEndTime
			{
				Platform::String^ get() { return this->endTime; }
			}
			property Platform::String^ getDueTime
			{
				Platform::String^ get() { return this->dueTime; }
			}
			property Platform::String^ getSubdivisionName
			{
				Platform::String^ get()
				{
					
					return L"";
				}
			}
			property float getUnitPrice
			{
				float get() { return unitPrice; };
			}
			property float getQuantity
			{
				float get() { return quantity; };
			}
			property float getTotalCost
			{
				float get() { return totalCost; };
			}
			property float getFeePayable
			{
				float get() { return feePayable; };
			}
			property float getFeeWaiver
			{
				float get() { return feeWaiver; };
			}
			property bool getIsPaid
			{
				bool get() { return isPaid; };
			}
			bool Delete();
		};

		public ref class BillViewModel sealed
		{
		private:
			static IObservableVector<Bill^>^ bills;
		public:
			BillViewModel() {}
			static property IObservableVector<Bill^>^ Bills
			{
				IObservableVector<Bill^>^ get();
			}
		};
	}
}

