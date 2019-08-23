//
// HouseDetailPage.xaml.h
// Declaration of the HouseDetailPage class
//

#pragma once

#include "HouseDetailPage.g.h"
#include "House.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class HouseDetailPage sealed
	{
	public:
		HouseDetailPage();
		property House^ TheHouse
		{
			House^ get() { return this->house; }
			void set(House^ e) { this->house = e; }
		}
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		House^ house;
		void GoToModifyState();
		void GoToNormalState();
		void ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
