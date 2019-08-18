//
// CarportManagePage.xaml.h
// Declaration of the CarportManagePage class
//

#pragma once

#include "CarportManagePage.g.h"
#include "Carport.h"

using namespace TaoPropertyUWP::Models;

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class CarportManagePage sealed
	{
	private:
		static CarportViewModel^ viewModel;
	public:
		CarportManagePage();
		static property CarportViewModel^ ViewModel
		{
			CarportViewModel^ get()
			{
				if (viewModel == nullptr)
				{
					viewModel = ref new CarportViewModel();
				}
				return viewModel;
			}
		}
	};
}
