//
// SubdivisionManagePage.xaml.h
// Declaration of the SubdivisionManagePage class
//

#pragma once

#include "SubdivisionManagePage.g.h"
#include "Subdivision.h"


using namespace std;
using namespace Platform::Collections;
using namespace TaoPropertyUWP::Models;

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SubdivisionManagePage sealed
	{
	public:
		SubdivisionManagePage();
		static property SubdivisionViewModel^ ViewModel
		{
			SubdivisionViewModel^ get()
			{
				if (viewModel == nullptr)
				{
					viewModel = ref new SubdivisionViewModel();
				}
				return viewModel;
			}
		}
		
	private:
		static SubdivisionViewModel^ viewModel;
		Windows::UI::Xaml::Media::Brush^ SavedBackground;
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
		void ListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e);
		void DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e);
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};


}
