//
// ChargeTemplatePage.xaml.h
// Declaration of the ChargeTemplatePage class
//

#pragma once

#include "ChargeTemplatePage.g.h"
#include "ChargeTemplate.h"

using namespace std;
using namespace Platform::Collections;
using namespace TaoPropertyUWP::Models;

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ChargeTemplatePage sealed
	{
	public:
		ChargeTemplatePage();
		static property ChargeTemplateViewModel^ ViewModel
		{
			ChargeTemplateViewModel^ get()
			{
				if (viewModel == nullptr)
				{
					viewModel = ref new ChargeTemplateViewModel();
				}
				return viewModel;
			}
		}
	private:
		static ChargeTemplateViewModel^ viewModel;
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void DeleteFlyoutButton_Click(Platform::Object^ sender, Windows::UI::Xaml::Controls::ItemClickEventArgs^ e);
		void NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
