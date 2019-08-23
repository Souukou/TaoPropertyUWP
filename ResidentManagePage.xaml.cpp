﻿//
// ResidentManagePage.xaml.cpp
// Implementation of the ResidentManagePage class
//

#include "pch.h"
#include "ResidentManagePage.xaml.h"
#include "NewResidentPage.xaml.h"
#include "Resident.h"
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
using namespace Windows::UI::Xaml::Interop;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=234238

ResidentViewModel^ ResidentManagePage::viewModel;

ResidentManagePage::ResidentManagePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::ResidentManagePage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::RefreshResidents();
}


void TaoPropertyUWP::ResidentManagePage::NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	this->Frame->Navigate(TypeName(NewResidentPage::typeid));
}


void TaoPropertyUWP::ResidentManagePage::DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	Object^ ClickedObject = e->ClickedItem;

	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedResident = (Resident^)ClickedButton->DataContext;

	ClickedResident->Delete();
}
