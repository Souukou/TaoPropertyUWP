//
// HouseManagePage.xaml.cpp
// Implementation of the HouseManagePage class
//

#include "pch.h"
#include "HouseManagePage.xaml.h"
#include "HouseDetailPage.xaml.h"
#include "TaoConnector.h"
#include "NewHousePage.xaml.h" 
#include "House.h"
using namespace TaoPropertyUWP;
using namespace TaoPropertyUWP::Models;
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


void TaoPropertyUWP::HouseManagePage::TheListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	DetailPopup->IsOpen = true;

	Object^ ClickedObject = e->ClickedItem;
	House^ ClickedHouse = (House^)ClickedObject;
	PopupFrame->Navigate(TypeName(HouseDetailPage::typeid), ClickedHouse);
}


void HouseManagePage::DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e)
{
	TitleGrid->Background = this->SavedBackground;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}


void HouseManagePage::DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e)
{
	this->SavedBackground = TitleGrid->Background;
	TitleGrid->Background = nullptr;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Visible;
}


void HouseManagePage::TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
{
	PopupFrame->Height = theRelativePanel->ActualHeight;
}
