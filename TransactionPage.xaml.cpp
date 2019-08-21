//
// TransactionPage.xaml.cpp
// Implementation of the TransactionPage class
//

#include "pch.h"
#include "TransactionPage.xaml.h"
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

TransactionViewModel^ TransactionPage::viewModel;

TransactionPage::TransactionPage()
{
	InitializeComponent();
}

void TaoPropertyUWP::TransactionPage::RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	TaoConnector::RefreshTransactions();
}
