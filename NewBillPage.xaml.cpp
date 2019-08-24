//
// NewBillPage.xaml.cpp
// Implementation of the NewBillPage class
//

#include "pch.h"
#include "NewBillPage.xaml.h"
#include "BillManagePage.xaml.h"
#include "TaoConnector.h"

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

NewBillPage::NewBillPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::NewBillPage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddBill(
		PropertyIdBox->Text,
		NameBox->Text,
		StartTimeBox->Text,
		EndTimeBox->Text,
		DueTimeBox->Text,
		UnitPriceBox->Text,
		QuantityBox->Text,
		TotalCostBox->Text,
		FeePayableBox->Text,
		FeeWaiverBox->Text,
		IsPaidBox->Text
	);
	this->Frame->Navigate(TypeName(BillManagePage::typeid));
}


void TaoPropertyUWP::NewBillPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(BillManagePage::typeid));
}
