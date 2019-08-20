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
	private:
		static SubdivisionViewModel^ viewModel;
		Windows::Web::Http::HttpClient^ httpClient;
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
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		
	};


}
