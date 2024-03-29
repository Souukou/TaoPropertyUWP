﻿//
// CarportManagePage.xaml.cpp
// Implementation of the CarportManagePage class
//

#include "pch.h"
#include "CarportManagePage.xaml.h"

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

CarportViewModel^ CarportManagePage::viewModel;

CarportManagePage::CarportManagePage()
{
	InitializeComponent();
}


void TaoPropertyUWP::CarportManagePage::DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e)
{
	Object^ ClickedObject = e->ClickedItem;

	Button^ ClickedButton = (Button^)ClickedObject;
	auto ClickedCarport = (Carport^)ClickedButton->DataContext;

	ClickedCarport->Delete();
}
