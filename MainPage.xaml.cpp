//
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
	
}


void TaoPropertyUWP::MainPage::GoBackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


