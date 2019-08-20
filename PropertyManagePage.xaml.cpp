//
// PropertyManagePage.xaml.cpp
// Implementation of the PropertyManagePage class
//

#include "pch.h"
#include "PropertyManagePage.xaml.h"
#include "HouseManagePage.xaml.h"
#include "CarportManagePage.xaml.h"
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

PropertyManagePage::PropertyManagePage()
{
	InitializeComponent();
}



void TaoPropertyUWP::PropertyManagePage::PropertyManagePage_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	PropertyTypeComboBox->SelectedIndex = 0;
}


void TaoPropertyUWP::PropertyManagePage::PropertyTypeComboBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	if (HouseComboBox->IsSelected)
	{
		PropertyContentFrame->Navigate(TypeName(HouseManagePage::typeid));
	}
	if (CarportComboBox->IsSelected)
	{
		PropertyContentFrame->Navigate(TypeName(CarportManagePage::typeid));
	}
}


void TaoPropertyUWP::PropertyManagePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (HouseComboBox->IsSelected)
	{
		TaoConnector::RefreshHouses();
	}
	if (CarportComboBox->IsSelected)
	{
		true;// PropertyContentFrame->Navigate(TypeName(CarportManagePage::typeid));
	}
}
