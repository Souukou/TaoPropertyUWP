//
// SubdivisionDetailPage.xaml.cpp
// Implementation of the SubdivisionDetailPage class
//

#include "pch.h"
#include "SubdivisionDetailPage.xaml.h"
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

SubdivisionDetailPage::SubdivisionDetailPage()
{
	InitializeComponent();
	GoToNormalState();
}

void SubdivisionDetailPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{
	subdivision = (Subdivision^)e->Parameter;
}

void SubdivisionDetailPage::GoToModifyState()
{
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	EnterpriseIdBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	OperatorIdBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	EnterpriseIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	OperatorIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
}

void SubdivisionDetailPage::GoToNormalState()
{
	NameBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	EnterpriseIdBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	OperatorIdBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NameBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	EnterpriseIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	OperatorIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}

void TaoPropertyUWP::SubdivisionDetailPage::ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToModifyState();
}


void TaoPropertyUWP::SubdivisionDetailPage::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	NameBlock->Text = NameBox->Text;
	EnterpriseIdBlock->Text = EnterpriseIdBox->Text;
	OperatorIdBlock->Text = OperatorIdBox->Text;
	TaoConnector::PatchSubdivision(
		"" + this->TheSubdivision->getid,
		NameBox->Text,
		EnterpriseIdBox->Text,
		OperatorIdBox->Text
	);
	GoToNormalState();
	TaoConnector::RefreshSubdivisions();
}


void TaoPropertyUWP::SubdivisionDetailPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToNormalState();
}
