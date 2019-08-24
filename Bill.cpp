#include "pch.h"
#include "Bill.h"
#include "TaoConnector.h"

IObservableVector<Bill^>^ BillViewModel::bills;

bool Bill::Delete()
{
	bool ret = TaoConnector::DeleteBill(this->id);
	if (ret)
	{
		int theDeleteOne = -1;
		for (int i = 0; i < BillViewModel::Bills->Size; ++i)
		{
			if (BillViewModel::Bills->GetAt(i)->getId == this->id)
			{
				theDeleteOne = i;
				break;
			}
		}
		if (theDeleteOne != -1)
		{
			BillViewModel::Bills->RemoveAt(theDeleteOne);
		}
	}

	return ret;
}

IObservableVector<Bill^>^ BillViewModel::Bills::get()
{
	if (bills == nullptr)
	{
		bills = ref new Platform::Collections::Vector<Bill^>();
		TaoConnector::RefreshBills();
	}
	return bills;
}