//
// PropertyManagePage.xaml.h
// Declaration of the PropertyManagePage class
//

#pragma once

#include "PropertyManagePage.g.h"
#include "Resident.h"

using namespace TaoPropertyUWP::Models;

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class PropertyManagePage sealed
	{
	public:
		PropertyManagePage();
	private:
		void PropertyManagePage_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void PropertyTypeComboBox_SelectionChanged(Platform::Object^ sender, Windows::UI::Xaml::Controls::SelectionChangedEventArgs^ e);
		void RefreshButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void NewButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
