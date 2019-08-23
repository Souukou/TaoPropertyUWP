//
// ResidentDetailPage.xaml.h
// Declaration of the ResidentDetailPage class
//

#pragma once

#include "ResidentDetailPage.g.h"
#include "Resident.h"
using namespace TaoPropertyUWP;
using namespace TaoPropertyUWP::Models;
namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class ResidentDetailPage sealed
	{
	public:
		ResidentDetailPage();
		property Resident^ TheResident
		{
			Resident^ get() { return this->resident; }
			void set(Resident^ e) { this->resident = e; }
		}
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		Resident^ resident;
		void ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void GoToModifyState();
		void GoToNormalState();
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
