//
// HouseManagePage.xaml.cpp
// Implementation of the HouseManagePage class
//

#include "pch.h"
#include "HouseManagePage.xaml.h"

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

HouseViewModel^ HouseManagePage::viewModel;

HouseManagePage::HouseManagePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::HouseManagePage::DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	
	Object^ ClickedObject = e->ClickedItem;
	
	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedHouse = (House^)ClickedButton->DataContext;

	ClickedHouse->Delete();
	


}


