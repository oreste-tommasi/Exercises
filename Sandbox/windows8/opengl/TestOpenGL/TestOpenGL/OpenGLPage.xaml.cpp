//
// OpenGLPage.xaml.cpp
// Implementation of the OpenGLPage.xaml class.
//

#include "pch.h"
#include "OpenGLPage.xaml.h"

using namespace TestOpenGL;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Input;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

OpenGLPage::OpenGLPage() :
	m_renderNeeded(true),
	m_lastPointValid(false)
{
	InitializeComponent();

	m_Graphics = ref new Graphics();

	m_Graphics->Initialize(
		Window::Current->CoreWindow,
		SwapChainPanel,
		DisplayProperties::LogicalDpi
		);

	Window::Current->CoreWindow->SizeChanged += 
		ref new TypedEventHandler<CoreWindow^, WindowSizeChangedEventArgs^>(this, &OpenGLPage::OnWindowSizeChanged);

	DisplayProperties::LogicalDpiChanged +=
		ref new DisplayPropertiesEventHandler(this, &OpenGLPage::OnLogicalDpiChanged);

	DisplayProperties::OrientationChanged +=
        ref new DisplayPropertiesEventHandler(this, &OpenGLPage::OnOrientationChanged);

	DisplayProperties::DisplayContentsInvalidated +=
		ref new DisplayPropertiesEventHandler(this, &OpenGLPage::OnDisplayContentsInvalidated);
	
	m_eventToken = CompositionTarget::Rendering::add(ref new EventHandler<Object^>(this, &OpenGLPage::OnRendering));

	m_timer = ref new BasicTimer();
}


void OpenGLPage::OnPointerMoved(Object^ sender, PointerRoutedEventArgs^ args)
{
	auto currentPoint = args->GetCurrentPoint(nullptr);
	if (currentPoint->IsInContact)
	{
		if (m_lastPointValid)
		{
			Windows::Foundation::Point delta(
				currentPoint->Position.X - m_lastPoint.X,
				currentPoint->Position.Y - m_lastPoint.Y
				);
			m_Graphics->UpdateTextPosition(delta);
			m_renderNeeded = true;
		}
		m_lastPoint = currentPoint->Position;
		m_lastPointValid = true;
	}
	else
	{
		m_lastPointValid = false;
	}
}

void OpenGLPage::OnPointerReleased(Object^ sender, PointerRoutedEventArgs^ args)
{
	m_lastPointValid = false;
}

void OpenGLPage::OnWindowSizeChanged(CoreWindow^ sender, WindowSizeChangedEventArgs^ args)
{
	m_Graphics->UpdateForWindowSizeChange();
	m_renderNeeded = true;
}

void OpenGLPage::OnLogicalDpiChanged(Object^ sender)
{
	m_Graphics->SetDpi(DisplayProperties::LogicalDpi);
	m_renderNeeded = true;
}

void OpenGLPage::OnOrientationChanged(Object^ sender)
{
	m_Graphics->UpdateForWindowSizeChange();
	m_renderNeeded = true;
}

void OpenGLPage::OnDisplayContentsInvalidated(Object^ sender)
{
	m_Graphics->ValidateDevice();
	m_renderNeeded = true;
}

void OpenGLPage::OnRendering(Object^ sender, Object^ args)
{
	if (m_renderNeeded)
	{
		m_timer->Update();
		m_Graphics->Update(m_timer->Total, m_timer->Delta);
		m_Graphics->Render();
		m_Graphics->Present();
		//m_renderNeeded = false;
	}
}

void OpenGLPage::SaveInternalState(IPropertySet^ state)
{
}

void OpenGLPage::LoadInternalState(IPropertySet^ state)
{
}
