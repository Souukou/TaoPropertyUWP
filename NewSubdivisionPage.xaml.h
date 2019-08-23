//
// NewSubdivisionPage.xaml.h
// Declaration of the NewSubdivisionPage class
//

#pragma once

#include "NewSubdivisionPage.g.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NewSubdivisionPage sealed
	{
	public:
		NewSubdivisionPage();
	private:
		void AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
