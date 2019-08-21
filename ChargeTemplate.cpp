#include "pch.h"
#include "ChargeTemplate.h"
#include "TaoConnector.h"
IObservableVector<ChargeTemplate^>^ ChargeTemplateViewModel::chargeTemplates;

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