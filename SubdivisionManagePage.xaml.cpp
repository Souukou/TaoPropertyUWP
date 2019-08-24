//
// SubdivisionManagePage.xaml.cpp
// Implementation of the SubdivisionManagePage class
//

#include "pch.h"
#include "SubdivisionManagePage.xaml.h"
#include "Subdivision.h"
#include "NewSubdivisionPage.xaml.h"
#include "LoginPage.xaml.h"
#include "SubdivisionDetailPage.xaml.h"
#include "TaoConnector.h"
#include <sstream>

using namespace TaoPropertyUWP;
using namespace Windows::Data::Json;
using namespace concurrency;
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
using namespace Windows::Web::Http;
using namespace Windows::Web::Http::Headers;
using namespace Windows::Web::Http::Filters;
using namespace Windows::Security::Cryptography::Certificates;
// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

SubdivisionViewModel^ SubdivisionManagePage::viewModel;

SubdivisionManagePage::SubdivisionManagePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::SubdivisionManagePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::RefreshSubdivisions();
}


void TaoPropertyUWP::SubdivisionManagePage::DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	Object^ ClickedObject = e->ClickedItem;

	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedSubdivision = (Subdivision^)ClickedButton->DataContext;

	ClickedSubdivision->Delete();
}


void TaoPropertyUWP::SubdivisionManagePage::NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(NewSubdivisionPage::typeid));
}



void TaoPropertyUWP::SubdivisionManagePage::TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
{
	PopupFrame->Height = theRelativePanel->ActualHeight;
}


void TaoPropertyUWP::SubdivisionManagePage::ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	DetailPopup->IsOpen = true;
	Object^ ClickedObject = e->ClickedItem;
	Subdivision^ ClickedSubdivision = (Subdivision^)ClickedObject;
	PopupFrame->Navigate(TypeName(SubdivisionDetailPage::typeid), ClickedSubdivision);
}


void TaoPropertyUWP::SubdivisionManagePage::DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e)
{
	TitleGrid->Background = this->SavedBackground;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}


void TaoPropertyUWP::SubdivisionManagePage::DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e)
{
	this->SavedBackground = TitleGrid->Background;
	TitleGrid->Background = nullptr;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Visible;
}


void TaoPropertyUWP::SubdivisionManagePage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (TaoConnector::UserName->Equals("") || TaoConnector::PassWord->Equals(""))
	{
		this->Frame->Navigate(TypeName(LoginPage::typeid));
	}
}
