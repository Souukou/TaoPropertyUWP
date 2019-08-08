//
// MainPage.xaml.cpp
// Implementation of the MainPage class.
//

#include "pch.h"
#include "MainPage.xaml.h"
#include "HomePage.xaml.h"


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
	
	//MainContentFrame->Navigate(TypeName(HomePage::typeid));
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
}


void TaoPropertyUWP::MainPage::GoBackButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{

}


