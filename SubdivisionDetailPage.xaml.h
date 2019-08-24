//
// SubdivisionDetailPage.xaml.h
// Declaration of the SubdivisionDetailPage class
//

#pragma once

#include "SubdivisionDetailPage.g.h"
#include "Subdivision.h"


namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class SubdivisionDetailPage sealed
	{
	public:
		SubdivisionDetailPage();
		property Subdivision^ TheSubdivision
		{
			Subdivision^ get() { return this->subdivision; }
			void set(Subdivision^ e) { this->subdivision = e; }
		}
	protected:
		virtual void OnNavigatedTo(Windows::UI::Xaml::Navigation::NavigationEventArgs^ e) override;
	private:
		Subdivision^ subdivision;
		void GoToModifyState();
		void GoToNormalState();
		void ModifyButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void ConfirmButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
		void CancelButton_Click(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
