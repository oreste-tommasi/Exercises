//
// LaunchPage.xaml.cpp
// Implementation of the LaunchPage class
//

#include "pch.h"
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
using namespace Windows::UI::Xaml::Media::Imaging;
using namespace Windows::Storage;
using namespace Windows::Storage::Streams;
using namespace Concurrency;

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234238

LaunchPage::LaunchPage()
{
	InitializeComponent();

	this->Loaded += ref new Windows::UI::Xaml::RoutedEventHandler(this, &LaunchApp::LaunchPage::OnLoaded);

	Uri^ uri = ref new Uri("ms-appx:///Assets/splash.png");

	create_task(StorageFile::GetFileFromApplicationUriAsync(uri)).then([this](task<StorageFile^> task)
	{
		try
		{
			auto file = task.get();
			create_task(file->OpenAsync(Windows::Storage::FileAccessMode::Read)).then([this](IRandomAccessStream^ fileStream)
				{

					auto bitmapImage = ref new BitmapImage(); 
					bitmapImage->SetSource(fileStream);
					SplashImage->Height = bitmapImage->PixelHeight;
					SplashImage->Width = bitmapImage->PixelWidth;
					SplashImage->Source = bitmapImage;
				});
		}
		catch(Exception^ e)
		{
			throw ref new FailureException("Failed to load image");
		}

	});
}

void
LaunchPage::OnLoaded(Platform::Object ^sender, Windows::UI::Xaml::RoutedEventArgs ^e)
{
	const char* buffer = new char[1024];

	delete[] buffer;
}