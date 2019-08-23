//
// NewChargeTemplatePage.xaml.h
// Declaration of the NewChargeTemplatePage class
//

#pragma once

#include "NewChargeTemplatePage.g.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class NewChargeTemplatePage sealed
	{
	public:
		NewChargeTemplatePage();
	private:
		void AddButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
