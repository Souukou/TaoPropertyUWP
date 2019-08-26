//
// SearchResultPage.xaml.cpp
// Implementation of the SearchResultPage class
//

#include "pch.h"
#include "SearchResultPage.xaml.h"
#include "House.h"
#include "TaoConnector.h"
#include "HouseDetailPage.xaml.h"
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

SearchResultPage::SearchResultPage()
{
	InitializeComponent();
}

void SearchResultPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{
	theQueryText = (String^)e->Parameter;
}


void TaoPropertyUWP::SearchResultPage::TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
{
	PopupFrame->Height = theRelativePanel->ActualHeight;
}


void TaoPropertyUWP::SearchResultPage::HouseListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	DetailPopup->IsOpen = true;
	Object^ ClickedObject = e->ClickedItem;
	House^ ClickedHouse = (House^)ClickedObject;
	PopupFrame->Navigate(TypeName(HouseDetailPage::typeid), ClickedHouse);
}


void TaoPropertyUWP::SearchResultPage::DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e)
{
	HouseTitleGrid->Background = this->SavedBackground;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}


void TaoPropertyUWP::SearchResultPage::DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e)
{
	this->SavedBackground = HouseTitleGrid->Background;
	HouseTitleGrid->Background = nullptr;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Visible;
}


void TaoPropertyUWP::SearchResultPage::HouseDeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	Object^ ClickedObject = e->ClickedItem;

	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedHouse = (House^)ClickedButton->DataContext;

	ClickedHouse->Delete();
}


void TaoPropertyUWP::SearchResultPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::SearchHouses(theQueryText);
}
