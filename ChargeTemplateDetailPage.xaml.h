//
// ChargeTemplateDetailPage.xaml.h
// Declaration of the ChargeTemplateDetailPage class
//

#pragma once

#include "ChargeTemplateDetailPage.g.h"
#include "ChargeTemplate.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ChargeTemplateDetailPage sealed
	{
	public:
		ChargeTemplateDetailPage();
		property ChargeTemplate^ TheChargeTemplate
		{
			ChargeTemplate^ get() { return this->chargeTemplate; }
			void set(ChargeTemplate^ e) { this->chargeTemplate = e; }
		}
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		ChargeTemplate^ chargeTemplate;
		void GoToModifyState();
		void GoToNormalState();
		void ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
