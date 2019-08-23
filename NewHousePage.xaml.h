//
// NewHousePage.xaml.h
// Declaration of the NewHousePage class
//

#pragma once

#include "NewHousePage.g.h"
#include "House.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NewHousePage sealed
	{
	public:
		NewHousePage();
	private:
		void AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
