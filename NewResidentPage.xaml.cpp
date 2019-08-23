//
// NewResidentPage.xaml.cpp
// Implementation of the NewResidentPage class
//

#include "pch.h"
#include "NewResidentPage.xaml.h"
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

NewResidentPage::NewResidentPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::NewResidentPage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddResidnet(
		NameBox->Text,
		EmailBox->Text,
		PhoneBox->Text,
		PasswordBox->Password
	);
	this->Frame->GoBack();
	TaoConnector::RefreshResidents();
}


void TaoPropertyUWP::NewResidentPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->GoBack();
}
