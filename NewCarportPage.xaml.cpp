//
// NewCarportPage.xaml.cpp
// Implementation of the NewCarportPage class
//

#include "pch.h"
#include "NewCarportPage.xaml.h"
#include "CarportManagePage.xaml.h"
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

NewCarportPage::NewCarportPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::NewCarportPage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddCarport(
		SubdivisionIdBox->Text,
		ProprietorIdBox->Text,
		NoBox->Text,
		NoteBox->Text);
	TaoConnector::RefreshCarports();
	this->Frame->Navigate(TypeName(CarportManagePage::typeid));
}


void TaoPropertyUWP::NewCarportPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(CarportManagePage::typeid));
}
