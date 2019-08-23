//
// NewChargeTemplatePage.xaml.cpp
// Implementation of the NewChargeTemplatePage class
//

#include "pch.h"
#include "NewChargeTemplatePage.xaml.h"
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

NewChargeTemplatePage::NewChargeTemplatePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::NewChargeTemplatePage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddChargeTemplate(
		SubdivisionIdBox->Text,
		NameBox->Text,
		ChargeTypeBox->Text,
		UnitPriceBox->Text,
		BillingCycleBox->Text
	);
	this->Frame->GoBack();
	TaoConnector::RefreshChargeTemplates();
}


void TaoPropertyUWP::NewChargeTemplatePage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->GoBack();
}
