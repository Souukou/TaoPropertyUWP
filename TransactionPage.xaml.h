//
// TransactionPage.xaml.h
// Declaration of the TransactionPage class
//

#pragma once

#include "TransactionPage.g.h"
#include "Transaction.h"
using namespace std;
using namespace Platform::Collections;
using namespace TaoPropertyUWP::Models;
namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class TransactionPage sealed
	{
	public:
		TransactionPage();
		static property TransactionViewModel^ ViewModel
		{
			TransactionViewModel^ get()
			{
				if (viewModel == nullptr)
				{
					viewModel = ref new TransactionViewModel();
				}
				return viewModel;
			}
		}
	private:
		static TransactionViewModel^ viewModel;
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
