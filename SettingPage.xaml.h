//
// SettingPage.xaml.h
// Declaration of the SettingPage class
//

#pragma once

#include "SettingPage.g.h"
#include "Enterprise.h"
#include "TaoConnector.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SettingPage sealed
	{
	public:
		SettingPage();
		property Enterprise^ TheEnterprise
		{
			Enterprise^ get() { return this->enterprise; }
			void set(Enterprise^ e) { this->enterprise = e; }
		}
	private:
		Enterprise^ enterprise;
		void GoToModifyState();
		void GoToNormalState();
		void ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
