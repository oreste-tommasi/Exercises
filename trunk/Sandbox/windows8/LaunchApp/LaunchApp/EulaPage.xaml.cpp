//
// EulaPage.xaml.cpp
// Implementation of the EulaPage class
//

#include "pch.h"
#include "EulaPage.xaml.h"
#include "LaunchPage.xaml.h"
#include <ppltasks.h>

using namespace LaunchApp;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Concurrency;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

EulaPage::EulaPage()
{
	InitializeComponent();

	Uri^ uri = ref new Uri("ms-appx:///Common/license.txt");

	create_task(StorageFile::GetFileFromApplicationUriAsync(uri)).then([this](task<StorageFile^> task)
	{
		try
		{
			auto file = task.get();
			create_task(FileIO::ReadTextAsync(file)).then([this](String^ text)
				{
					EulaText->Text = text;
				});
		}
		catch(Exception^ e)
		{
			throw ref new FailureException("Failed to load image");
		}
	});
}


void
EulaPage::Accepted_ButtonClick(Platform::Object^ sender, Windows::UI::Xaml::RoutedEventArgs^ e)
{
	if (!Frame->Navigate(LaunchPage::typeid))
	{
		throw ref new FailureException("Failed to create the next page");
	}
}
