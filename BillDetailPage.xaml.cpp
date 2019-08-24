//
// BillDetailPage.xaml.cpp
// Implementation of the BillDetailPage class
//

#include "pch.h"
#include "BillDetailPage.xaml.h"
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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

BillDetailPage::BillDetailPage()
{
	InitializeComponent();
	GoToNormalState();
}

void BillDetailPage::GoToModifyState()
{
	PropertyIdBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	StartTimeBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	EndTimeBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	DueTimeBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	UnitPriceBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	QuantityBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	TotalCostBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FeePayableBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FeeWaiverBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	IsPaidBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	PropertyIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	StartTimeBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	EndTimeBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	DueTimeBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	UnitPriceBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	QuantityBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	TotalCostBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FeePayableBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FeeWaiverBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	IsPaidBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void BillDetailPage::GoToNormalState()
{
	PropertyIdBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	StartTimeBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	EndTimeBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	DueTimeBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	UnitPriceBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	QuantityBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	TotalCostBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FeePayableBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FeeWaiverBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	IsPaidBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	PropertyIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	StartTimeBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	EndTimeBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	DueTimeBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	UnitPriceBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	QuantityBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	TotalCostBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FeePayableBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FeeWaiverBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	IsPaidBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}


void TaoPropertyUWP::BillDetailPage::ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToModifyState();
}


void TaoPropertyUWP::BillDetailPage::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::PatchBill(
		"" + this->TheBill->getId,
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
	PropertyIdBlock->Text = PropertyIdBox->Text;
	NameBlock->Text = NameBox->Text;
	StartTimeBlock->Text = StartTimeBox->Text;
	EndTimeBlock->Text = EndTimeBox->Text;
	DueTimeBlock->Text = DueTimeBox->Text;
	UnitPriceBlock->Text = UnitPriceBox->Text;
	QuantityBlock->Text = QuantityBox->Text;
	TotalCostBlock->Text = TotalCostBox->Text;
	FeePayableBlock->Text = FeePayableBox->Text;
	FeeWaiverBlock->Text = FeePayableBox->Text;
	IsPaidBlock->Text = IsPaidBox->Text;
	GoToNormalState();
	TaoConnector::RefreshBills();
}


void TaoPropertyUWP::BillDetailPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToNormalState();
}

void BillDetailPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{
	this->bill = (Bill^)e->Parameter;
	GoToNormalState();
}