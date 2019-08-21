//
// ChargeTemplatePage.xaml.cpp
// Implementation of the ChargeTemplatePage class
//

#include "pch.h"
#include "ChargeTemplatePage.xaml.h"
#include "ChargeTemplate.h"
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

ChargeTemplateViewModel^ ChargeTemplatePage::viewModel;

ChargeTemplatePage::ChargeTemplatePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::ChargeTemplatePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::RefreshChargeTemplates();
}
