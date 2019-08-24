//
// SettingPage.xaml.cpp
// Implementation of the SettingPage class
//

#include "pch.h"
#include "SettingPage.xaml.h"
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

SettingPage::SettingPage()
{
	InitializeComponent();
	enterprise = EnterpriseViewModel::Enterprises->GetAt(0);
}


void TaoPropertyUWP::SettingPage::ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToModifyState();
}

void SettingPage::GoToModifyState()
{
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FounderIdBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FounderIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void SettingPage::GoToNormalState()
{
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FounderIdBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FounderIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}

void TaoPropertyUWP::SettingPage::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::PatchEnterprise(
		this->TheEnterprise->getid + "",
		NameBox->Text,
		FounderIdBox->Text
	);
	NameBlock->Text = NameBox->Text;
	FounderIdBlock->Text = FounderIdBox->Text;
	GoToNormalState();
}


void TaoPropertyUWP::SettingPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToNormalState();
}


void TaoPropertyUWP::SettingPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (TaoConnector::UserName->Equals("") || TaoConnector::PassWord->Equals(""))
	{
		this->Frame->Navigate(TypeName(LoginPage::typeid));
	}
}
