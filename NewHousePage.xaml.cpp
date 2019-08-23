//
// NewHousePage.xaml.cpp
// Implementation of the NewHousePage class
//

#include "pch.h"
#include "NewHousePage.xaml.h"
#include "HouseManagePage.xaml.h"
#include "TaoConnector.h"
using namespace std;
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
using namespace Windows::UI::Xaml::Interop;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

NewHousePage::NewHousePage()
{
	InitializeComponent();
}

void TaoPropertyUWP::NewHousePage::AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::AddHouse(
		SubdivisionIdBox->Text,
		ProprietorIdBox->Text,
		NoteBox->Text,
		NoBox->Text,
		NetFloorAreaBox->Text,
		GrossFloorAreaBox->Text,
		BuildingBox->Text,
		UnitBox->Text,
		FloorBox->Text,
		HouseStatusBox->Text,
		LayoutBox->Text,
		DirectionBox->Text
		);
	TaoConnector::RefreshHouses();
	this->Frame->Navigate(TypeName(HouseManagePage::typeid));
}

void TaoPropertyUWP::NewHousePage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(HouseManagePage::typeid));
}
