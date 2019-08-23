//
// LoginPage.xaml.cpp
// Implementation of the LoginPage class
//

#include "pch.h"
#include "LoginPage.xaml.h"
#include "MainPage.xaml.h"
#include "RegistPage.xaml.h"
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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

LoginPage::LoginPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::LoginPage::LoginButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::UserName = PhoneBox->Text;
	TaoConnector::PassWord = ThePasswordBox->Password;
	this->Frame->Navigate(TypeName(MainPage::typeid));
}


void TaoPropertyUWP::LoginPage::RegistButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(RegistPage::typeid));
}
