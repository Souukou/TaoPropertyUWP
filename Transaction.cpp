#include "pch.h"
#include "Transaction.h"
#include "TaoConnector.h"

IObservableVector<Transaction^>^ TransactionViewModel::transactions;

TransactionViewModel::TransactionViewModel()
{

}

IObservableVector<Transaction^>^ TransactionViewModel::Transactions::get()
{
	if (transactions == nullptr)
	{
		transactions = ref new Platform::Collections::Vector<Transaction^>();
		TaoConnector::RefreshTransactions();
	}
	return transactions;
}
