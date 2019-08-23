//
// HouseDetailPage.xaml.cpp
// Implementation of the HouseDetailPage class
//

#include "pch.h"
#include "HouseDetailPage.xaml.h"
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

HouseDetailPage::HouseDetailPage()
{
	InitializeComponent();
}

void HouseDetailPage::OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e)
{
	TheHouse = (House^)e->Parameter;
	GoToNormalState();
}

void HouseDetailPage::GoToModifyState()
{
	SubdivisionIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ProprietorIdBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NoBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NoteBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NetFloorAreaBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	GrossFloorAreaBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	BuildingBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	UnitBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FloorBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	HouseStatusBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	LayoutBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	DirectionBox->Visibility = Windows::UI::Xaml::Visibility::Visible;
	SubdivisionIdBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ProprietorIdBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NoBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NoteBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NetFloorAreaBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	GrossFloorAreaBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	BuildingBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	UnitBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FloorBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	HouseStatusBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	LayoutBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	DirectionBlock->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
}
void HouseDetailPage::GoToNormalState()
{
	SubdivisionIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	ProprietorIdBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NoBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NoteBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	NetFloorAreaBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	GrossFloorAreaBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	BuildingBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	UnitBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	FloorBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	HouseStatusBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	LayoutBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	DirectionBox->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	SubdivisionIdBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ProprietorIdBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NoBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NoteBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	NetFloorAreaBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	GrossFloorAreaBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	BuildingBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	UnitBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	FloorBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	HouseStatusBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	LayoutBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	DirectionBlock->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ModifyButton->Visibility = Windows::UI::Xaml::Visibility::Visible;
	ConfirmButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
	CancelButton->Visibility = Windows::UI::Xaml::Visibility::Collapsed;
}



void TaoPropertyUWP::HouseDetailPage::ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToModifyState();
}


void TaoPropertyUWP::HouseDetailPage::ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::PatchHouse(
		"" + this->TheHouse->getid,
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
	SubdivisionIdBlock->Text = SubdivisionIdBox->Text;
	ProprietorIdBlock->Text = ProprietorIdBox->Text;
	NoteBlock->Text = NoteBox->Text;
	NoBlock->Text = NoBox->Text;
	NetFloorAreaBlock->Text = NetFloorAreaBox->Text;
	GrossFloorAreaBlock->Text = GrossFloorAreaBox->Text;
	BuildingBlock->Text = BuildingBox->Text;
	UnitBlock->Text = UnitBox->Text;
	FloorBlock->Text = FloorBox->Text;
	HouseStatusBlock->Text = HouseStatusBox->Text;
	LayoutBlock->Text = LayoutBox->Text;
	DirectionBlock->Text = DirectionBox->Text;
	GoToNormalState();
	TaoConnector::RefreshResidents();
}


void TaoPropertyUWP::HouseDetailPage::CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	GoToNormalState();
}

