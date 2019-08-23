#include "pch.h"
#include "ChargeTemplate.h"
#include "TaoConnector.h"
IObservableVector<ChargeTemplate^>^ ChargeTemplateViewModel::chargeTemplates;

bool ChargeTemplate::Delete()
{
	bool ret = TaoConnector::DeleteChargeTemplate(this->id);
	if (ret)
	{
		int theDeleteOne = -1;
		for (int i = 0; i < ChargeTemplateViewModel::ChargeTemplates->Size; ++i)
		{
			if (ChargeTemplateViewModel::ChargeTemplates->GetAt(i)->getid == this->id)
			{
				theDeleteOne = i;
				break;
			}
		}
		if (theDeleteOne != -1)
		{
			ChargeTemplateViewModel::ChargeTemplates->RemoveAt(theDeleteOne);
		}
	}

	return ret;
}

ChargeTemplateViewModel::ChargeTemplateViewModel()
{

}

IObservableVector<ChargeTemplate^>^ ChargeTemplateViewModel::ChargeTemplates::get()
{
	if (chargeTemplates == nullptr)
	{
		chargeTemplates = ref new Platform::Collections::Vector<ChargeTemplate^>();
		TaoConnector::RefreshChargeTemplates();
	}
	return chargeTemplates;
}

