//
// RegistPage.xaml.cpp
// Implementation of the RegistPage class
//

#include "pch.h"
#include "RegistPage.xaml.h"
#include "HomePage.xaml.h"
#include "TaoConnector.h"
#include <windows.h>
#include "Resident.h"

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

RegistPage::RegistPage()
{
	InitializeComponent();
}

void TaoPropertyUWP::RegistPage::RegistButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddOperator(
		NameBox->Text,
		EmailBox->Text,
		PhoneBox->Text,
		ThePasswordBox->Password
	);
	TaoConnector::UserName = PhoneBox->Text;
	TaoConnector::PassWord = ThePasswordBox->Password;
	
	Sleep(500);
	
	TaoConnector::AddEnterprise(EnterpriseNameBox->Text);
	
	this->Frame->Navigate(TypeName(HomePage::typeid));
	
}


void TaoPropertyUWP::RegistPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->GoBack();
}
