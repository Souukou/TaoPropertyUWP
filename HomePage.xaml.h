﻿//
// HomePage.xaml.h
// Declaration of the HomePage class
//

#pragma once

#include "HomePage.g.h"

namespace TaoPropertyUWP
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class HomePage sealed
	{
	public:
		HomePage();
	private:
		void Page_Loaded(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
