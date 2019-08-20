//
// ResidentManagePage.xaml.h
// Declaration of the ResidentManagePage class
//

#pragma once

#include "ResidentManagePage.g.h"
#include "Resident.h"

using namespace std;
using namespace Platform::Collections;
using namespace TaoPropertyUWP::Models;

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ResidentManagePage sealed
	{
	private:
		static ResidentViewModel^ viewModel;
	public:
		ResidentManagePage();
		static property ResidentViewModel^ ViewModel
		{
			ResidentViewModel^ get()
			{
				if (viewModel == nullptr)
				{
					viewModel = ref new ResidentViewModel();
				}
				return viewModel;
			}
		}
	private:
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
