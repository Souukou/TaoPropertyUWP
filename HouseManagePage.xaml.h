//
// HouseManagePage.xaml.h
// Declaration of the HouseManagePage class
//

#pragma once

#include "HouseManagePage.g.h"
#include "House.h"

using namespace TaoPropertyUWP::Models;

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
	};
}
