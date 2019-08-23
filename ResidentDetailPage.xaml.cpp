//
// ResidentDetailPage.xaml.cpp
// Implementation of the ResidentDetailPage class
//

#include "pch.h"
#include "ResidentDetailPage.xaml.h"
#include "TaoConnector.h"

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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

ResidentDetailPage::ResidentDetailPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::ResidentDetailPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	
}

void ResidentDetailPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) 
{
	
	TheResident = (Resident^)e->Parameter;
}

void ResidentDetailPage::GoToModifyState()
{
	PasswordTextBlockTitle->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	EmailBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	PhoneBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	EmailBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	PhoneBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	PasswordBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}

void TaoPropertyUWP::ResidentDetailPage::ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToModifyState();
}

void ResidentDetailPage::GoToNormalState()
{
	PasswordTextBlockTitle->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	EmailBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	PhoneBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	EmailBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	PhoneBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	PasswordBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
}


void TaoPropertyUWP::ResidentDetailPage::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::PatchResident(
		this->TheResident->getphone,
		NameBox->Text,
		EmailBox->Text,
		PhoneBox->Text,
		PasswordBox->Password
	);
	NameBlock->Text = NameBox->Text;
	EmailBlock->Text = EmailBox->Text;
	PhoneBlock->Text = PhoneBox->Text;
	PasswordBox->Password = L"";
	GoToNormalState();
	TaoConnector::RefreshResidents();
}


void TaoPropertyUWP::ResidentDetailPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToNormalState();
}
