//
// ChargeTemplatePage.xaml.cpp
// Implementation of the ChargeTemplatePage class
//

#include "pch.h"
#include "ChargeTemplatePage.xaml.h"
#include "ChargeTemplateDetailPage.xaml.h"
#include "ChargeTemplate.h"
#include "TaoConnector.h"
#include "NewChargeTemplatePage.xaml.h"
#include "LoginPage.xaml.h"
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

ChargeTemplateViewModel^ ChargeTemplatePage::viewModel;

ChargeTemplatePage::ChargeTemplatePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::ChargeTemplatePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::RefreshChargeTemplates();
}


void TaoPropertyUWP::ChargeTemplatePage::DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	Object^ ClickedObject = e->ClickedItem;

	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedChargeTemplate = (ChargeTemplate^)ClickedButton->DataContext;

	ClickedChargeTemplate->Delete();
}


void TaoPropertyUWP::ChargeTemplatePage::NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(NewChargeTemplatePage::typeid));
}


void TaoPropertyUWP::ChargeTemplatePage::TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e)
{
	PopupFrame->Height = theRelativePanel->ActualHeight;
}


void TaoPropertyUWP::ChargeTemplatePage::ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	DetailPopup->IsOpen = true;

	Object^ ClickedObject = e->ClickedItem;
	ChargeTemplate^ ClickedChargeTemplate = (ChargeTemplate^)ClickedObject;
	PopupFrame->Navigate(TypeName(ChargeTemplateDetailPage::typeid), ClickedChargeTemplate);

}


void TaoPropertyUWP::ChargeTemplatePage::DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e)
{
	TitleGrid->Background = this->SavedBackground;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}


void TaoPropertyUWP::ChargeTemplatePage::DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e)
{
	this->SavedBackground = TitleGrid->Background;
	TitleGrid->Background = nullptr;
	CoverRectangle->Visibility = Windows::UI::Xaml::Visibility::Visible;
}


void TaoPropertyUWP::ChargeTemplatePage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (TaoConnector::UserName->Equals("") || TaoConnector::PassWord->Equals(""))
	{
		this->Frame->Navigate(TypeName(LoginPage::typeid));
	}
}
