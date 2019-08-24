//
// BillDetailPage.xaml.h
// Declaration of the BillDetailPage class
//

#pragma once

#include "BillDetailPage.g.h"
#include "Bill.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class BillDetailPage sealed
	{
	public:
		BillDetailPage();
		property Bill^ TheBill
		{
			Bill^ get() { return this->bill; }
			void set(Bill^ e) { this->bill = e; }
		}
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		Bill^ bill;
		void GoToModifyState();
		void GoToNormalState();
		void ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
