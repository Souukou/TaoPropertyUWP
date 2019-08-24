//
// BillManagePage.xaml.cpp
// Implementation of the BillManagePage class
//

#include "pch.h"
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

BillViewModel^ BillManagePage::viewModel;

BillManagePage::BillManagePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::BillManagePage::TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
{
	PopupFrame->Height = theRelativePanel->ActualHeight;
}


void TaoPropertyUWP::BillManagePage::DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	Object^ ClickedObject = e->ClickedItem;

	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedBill = (Bill^)ClickedButton->DataContext;

	ClickedBill->Delete();
}


void TaoPropertyUWP::BillManagePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::RefreshBills();
}


void TaoPropertyUWP::BillManagePage::NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(NewBillPage::typeid));
}


void TaoPropertyUWP::BillManagePage::ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	DetailPopup->IsOpen = true;

	Object^ ClickedObject = e->ClickedItem;
	Bill^ ClickedBill = (Bill^)ClickedObject;
	PopupFrame->Navigate(TypeName(BillDetailPage::typeid), ClickedBill);
}


void TaoPropertyUWP::BillManagePage::DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e)
{
	TitleGrid->Background = this->SavedBackground;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}


void TaoPropertyUWP::BillManagePage::DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e)
{
	this->SavedBackground = TitleGrid->Background;
	TitleGrid->Background = nullptr;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Visible;
}
