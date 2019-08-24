//
// PayBillPage.xaml.cpp
// Implementation of the PayBillPage class
//

#include "pch.h"
#include "PayBillPage.xaml.h"
#include "TaoConnector.h"
#include "TransactionPage.xaml.h"
#include "LoginPage.xaml.h"
using namespace TaoPropertyUWP;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::UI::Xaml::Interop;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

PayBillPage::PayBillPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::PayBillPage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddTransaction(
		SubdivisionIdBox->Text,
		BillIdBox->Text,
		TotalCostBox->Text,
		FeePayableBox->Text,
		FeeWaiverBox->Text,
		PaymentMethodBox->Text
	);
	TaoConnector::RefreshTransactions();
	this->Frame->Navigate(TypeName(TransactionPage::typeid));
}


void TaoPropertyUWP::PayBillPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (TaoConnector::UserName->Equals("") || TaoConnector::PassWord->Equals(""))
	{
		this->Frame->Navigate(TypeName(LoginPage::typeid));
	}
}
