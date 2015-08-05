//
// LaunchPage.xaml.cpp
// Implementation of the LaunchPage class
//

#include "pch.h"
#include "LaunchPage.xaml.h"
#include "MainPage.xaml.h"
#include <ppltasks.h>
#include <agents.h>

#include "SharedClass.h"

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

task<void> complete_after(unsigned int timeout)
{
	// A task completion event that is set when a timer fires.
	task_completion_event<void> tce;

	// Create a non-repeating timer.
	auto fire_once = new timer<int>(timeout, 0, nullptr, false);
	// Create a call object that sets the completion event after the timer fires.
	auto callback = new call<int>([tce](int)
	{
		tce.set();
	});

	// Connect the timer to the callback and start the timer.
	fire_once->link_target(callback);
	fire_once->start();

	// Create a task that completes after the completion event is set.
	task<void> event_set(tce);

	// Create a continuation task that cleans up resources and 
	// and return that continuation task. 
	return event_set.then([callback, fire_once]()
	{
		delete callback;
		delete fire_once;
	});
}

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

	task<void> failure_task = complete_after(5000).then([this]
	{
		//to dispatch to UI thread
		this->Dispatcher->RunAsync( Windows::UI::Core::CoreDispatcherPriority::Normal,
											 ref new Windows::UI::Core::DispatchedHandler([this]()
		{
			if (!this->Frame->Navigate(MainPage::typeid, this))
			{
				throw ref new FailureException("Failed to create the next page");
			}
		}));
	});
}

#pragma region Navigation support

void
LaunchPage::OnNavigatedTo( NavigationEventArgs^ e )
{
	Page^ prevPage = (Page^)e->Parameter;

	int gg = 0;
	//SharedClass^ sharedClass = (SharedClass^)e.Parameter;

	//std::string myString = sharedClass->mTextInfo;
	//double		myDouble = sharedClass->mValue;
}

#pragma endregion
