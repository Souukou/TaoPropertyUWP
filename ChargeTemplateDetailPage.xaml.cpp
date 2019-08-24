//
// ChargeTemplateDetailPage.xaml.cpp
// Implementation of the ChargeTemplateDetailPage class
//

#include "pch.h"
#include "ChargeTemplateDetailPage.xaml.h"
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

ChargeTemplateDetailPage::ChargeTemplateDetailPage()
{
	InitializeComponent();
	GoToNormalState();
}


void ChargeTemplateDetailPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{
	chargeTemplate = (ChargeTemplate^)e->Parameter;
}

void ChargeTemplateDetailPage::GoToModifyState()
{
	SubdivisionBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ChargeTemplateNameBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ChargeTypeBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	UnitPriceBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	BillingCycleBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	SubdivisionIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ChargeTemplateNameBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ChargeTypeBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	UnitPriceBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	BillingCycleBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	SubdivisionTitleTextBlock->Text = "小区ID";
}

void ChargeTemplateDetailPage::GoToNormalState()
{
	SubdivisionBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ChargeTemplateNameBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ChargeTypeBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	UnitPriceBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	BillingCycleBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	SubdivisionIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ChargeTemplateNameBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ChargeTypeBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	UnitPriceBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	BillingCycleBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	SubdivisionTitleTextBlock->Text = "小区";

}

void TaoPropertyUWP::ChargeTemplateDetailPage::ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToModifyState();
}


void TaoPropertyUWP::ChargeTemplateDetailPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToNormalState();
}


void TaoPropertyUWP::ChargeTemplateDetailPage::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::PatchChargeTemplate(
		"" + this->TheChargeTemplate->getid,
		SubdivisionIdBox->Text,
		ChargeTemplateNameBox->Text,
		ChargeTypeBox->Text,
		UnitPriceBox->Text,
		BillingCycleBox->Text
	);
	ChargeTemplateNameBlock->Text = ChargeTemplateNameBox->Text;
	UnitPriceBlock->Text = UnitPriceBox->Text;
	BillingCycleBlock->Text = BillingCycleBox->Text;
	GoToNormalState();
	TaoConnector::RefreshChargeTemplates();
}
