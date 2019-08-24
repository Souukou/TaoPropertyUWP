//
// BillManagePage.xaml.h
// Declaration of the BillManagePage class
//

#pragma once

#include "BillManagePage.g.h"
#include "Bill.h"
#include "NewBillPage.xaml.h"
#include "BillDetailPage.xaml.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class BillManagePage sealed
	{
	public:
		BillManagePage();
		static property BillViewModel^ ViewModel
		{
			BillViewModel^ get() {
				if (viewModel == nullptr)
				{
					viewModel = ref new BillViewModel();
				}
				return viewModel;
			}
		}
	private:
		static BillViewModel^ viewModel;
		Windows::UI::Xaml::Media::Brush^ SavedBackground;
		void TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
		void DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e);
		void DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e);
	};
}
