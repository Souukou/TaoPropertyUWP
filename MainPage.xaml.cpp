﻿//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "HomePage.xaml.h"
#include "SubdivisionManagePage.xaml.h"
#include "ResidentManagePage.xaml.h"
#include "PropertyManagePage.xaml.h"
#include "ChargeTemplatePage.xaml.h"
#include "TransactionPage.xaml.h"
#include "LoginPage.xaml.h"
#include "SettingPage.xaml.h"
#include "TaoConnector.h"
#include "BillManagePage.xaml.h"
#include "PayBillPage.xaml.h"
#include "SearchResultPage.xaml.h"

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

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

MainPage::MainPage()
{
	InitializeComponent();
}


void TaoPropertyUWP::MainPage::Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	HomeListBoxItem->IsSelected = true;
}


void TaoPropertyUWP::MainPage::NavigatorButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	NavigatorSplitView->IsPaneOpen = !NavigatorSplitView->IsPaneOpen;
}


void TaoPropertyUWP::MainPage::ListBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e)
{
	if (HomeListBoxItem->IsSelected) 
	{
		TitleTextBlock->Text = "桃物业";
		MainContentFrame->Navigate(TypeName(HomePage::typeid));
	}
	if (ChargeListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "收费系统";
		MainContentFrame->Navigate(TypeName(PayBillPage::typeid));
	}
	if (BillManageListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "账单管理";
		MainContentFrame->Navigate(TypeName(BillManagePage::typeid));
	}
	if (TransactionHistoryBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "交易流水";
		MainContentFrame->Navigate(TypeName(TransactionPage::typeid));
	}
	if (ChargeTemplateListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "收费项目管理";
		MainContentFrame->Navigate(TypeName(ChargeTemplatePage::typeid));
	}
	if (PropertyManageListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "资产管理";
		MainContentFrame->Navigate(TypeName(PropertyManagePage::typeid));
	}
	if (SubdivisionManageListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "小区管理";
		MainContentFrame->Navigate(TypeName(SubdivisionManagePage::typeid));
	}
	if (ResidentManageListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "住户管理";
		MainContentFrame->Navigate(TypeName(ResidentManagePage::typeid));
	}
	if (SettingListBoxItem->IsSelected)
	{
		TitleTextBlock->Text = "设置";
		MainContentFrame->Navigate(TypeName(SettingPage::typeid));
	}
}


void TaoPropertyUWP::MainPage::GoBackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}




void TaoPropertyUWP::MainPage::SearchBox_QuerySubmitted(Windows::UI::Xaml::Controls::AutoSuggestBox^ sender, Windows::UI::Xaml::Controls::AutoSuggestBoxQuerySubmittedEventArgs^ args)
{
	
	MainContentFrame->Navigate(TypeName(SearchResultPage::typeid), args->QueryText);
}
