﻿//
// HouseManagePage.xaml.h
// Declaration of the HouseManagePage class
//

#pragma once

#include "HouseManagePage.g.h"
#include "House.h"

using namespace TaoPropertyUWP::Models;
using namespace Windows::UI::Xaml::Input;
namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class HouseManagePage sealed
	{
	private:
		static HouseViewModel^ viewModel;
	public:
		HouseManagePage();
		static property HouseViewModel^ ViewModel
		{
			HouseViewModel^ get()
			{

				if (viewModel == nullptr)
				{
					viewModel = ref new HouseViewModel();
				}

				return viewModel;
			}
		}
	private:
		void DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void TheListView_ItemClick(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void DetailPopup_Closed(Platform::Object^ sender, Platform::Object^ e);
		void DetailPopup_Opened(Platform::Object^ sender, Platform::Object^ e);
		Windows::UI::Xaml::Media::Brush^ SavedBackground;
		void TheRelativePanel_SizeChanged(Platform::Object^ sender, Windows::UI::Xaml::SizeChangedEventArgs^ e);
	};
}
