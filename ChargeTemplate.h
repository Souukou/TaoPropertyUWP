#pragma once
#include <sstream>
#include "Operator.h"
#include "Subdivision.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::Foundation::Collections;

namespace TaoPropertyUWP
{
	namespace Models
	{
		public ref class ChargeTemplate sealed
		{
		private:
			int id;
			int subdivisionId;
			Platform::String^ name;
			Platform::String^ chargeType;
			float unitPrice;
			int billingCycle;

		public:
			ChargeTemplate(
				int id,
				int subdivisionId,
				Platform::String^ name,
				Platform::String^ chargeType,
				float unitPrice,
				int billingCycle ):
				id{ id },
				subdivisionId{ subdivisionId },
				name{ name },
				chargeType{ chargeType },
				unitPrice { unitPrice },
				billingCycle { billingCycle } {}

			property int getid
			{
				int get() { return id; };
			}
			property Platform::String^ getSubdivisionName
			{
				Platform::String^ get()
				{
					for (int i = 0; i < SubdivisionViewModel::Subdivisions->Size; ++i)
					{
						if (SubdivisionViewModel::Subdivisions->GetAt(i)->getid == subdivisionId)
						{
							return SubdivisionViewModel::Subdivisions->GetAt(i)->getname;
						}
					}
					return L"";
				}
			}
			property Platform::String^ getname
			{
				Platform::String^ get() { return this->name; }
			}
			property Platform::String^ getchargeType
			{
				Platform::String^ get()
				{
					if (this->chargeType == L"GFABased")
					{
						return L"按建筑面积";
					}
					if (this->chargeType == L"residentBased")
					{
						return L"按户收费";
					}
					if (this->chargeType == L"floorBased")
					{
						return L"按楼层收费";
					}
					if (this->chargeType == L"usageBased")
					{
						return L"按用量收费";
					}
					
					return this->chargeType;
				}
			}
			property int getUnitPrice
			{
				int get() { return unitPrice; };
			}
			property int getBillingCycle
			{
				int get() { return this->billingCycle; }
			}

		};

		public ref class ChargeTemplateViewModel sealed
		{
		private:
			static IObservableVector<ChargeTemplate^>^ chargeTemplates;
		public:
			ChargeTemplateViewModel();
			static property IObservableVector<ChargeTemplate^>^ ChargeTemplates
			{
				IObservableVector<ChargeTemplate^>^ get();
			}
		};
	}
}

