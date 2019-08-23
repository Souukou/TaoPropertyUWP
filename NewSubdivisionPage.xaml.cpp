//
// NewSubdivisionPage.xaml.cpp
// Implementation of the NewSubdivisionPage class
//

#include "pch.h"
#include "NewSubdivisionPage.xaml.h"
#include "SubdivisionManagePage.xaml.h"
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

NewSubdivisionPage::NewSubdivisionPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::NewSubdivisionPage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddSubdivision(
		SubdivisionNameBox->Text,
		EnterpriseIdBox->Text,
		OperatorIdBox->Text
	);
	this->Frame->Navigate(TypeName(SubdivisionManagePage::typeid));
	TaoConnector::RefreshSubdivisions();
}


void TaoPropertyUWP::NewSubdivisionPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(SubdivisionManagePage::typeid));
}
