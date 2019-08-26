//
// SearchResultPage.xaml.h
// Declaration of the SearchResultPage class
//

#pragma once

#include "SearchResultPage.g.h"
#include "House.h"

using namespace Platform;

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SearchResultPage sealed
	{
	public:
		SearchResultPage();
		property HouseViewModel^ TheHouseViewModel
		{
			HouseViewModel^ get()
			{
				if (theHouseViewModel == nullptr)
				{
					theHouseViewModel = ref new HouseViewModel();
				}

				return theHouseViewModel;
			}
		}
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		HouseViewModel^ theHouseViewModel;
		Windows::UI::Xaml::Media::Brush^ SavedBackground;
		String^ theQueryText;
		void TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
		void HouseListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e);
		void DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e);
		void HouseDeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
