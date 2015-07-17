//
// EulaPage.xaml.h
// Declaration of the EulaPage class
//

#pragma once

#include "EulaPage.g.h"

namespace LaunchApp
{
	/// <summary>
	/// An empty page that can be used on its own or navigated to within a Frame.
	/// </summary>
	[Windows::Foundation::Metadata::WebHostHidden]
	public ref class EulaPage sealed
	{
	public:
		EulaPage();
	private:
		void Accepted_ButtonClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e);
	};
}
