// Graphics.cpp
#include "pch.h"
#include "Graphics.h"
#include "GDI.h"
#include "User.h"
#include "GL.h"

#include <windows.ui.xaml.media.dxinterop.h>
#include <math.h>

using namespace OpenGraphicsLibrary;
using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace D2D1;
using namespace DirectX;
using namespace Microsoft::WRL;
using namespace Windows::Graphics::Display;
using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml::Controls;

Graphics::Graphics() :
	m_backgroundColorIndex(0),
	m_textPosition(0.0f, 0.0f)
{
}


bool Graphics::Initialize(CoreWindow^ window, SwapChainBackgroundPanel^ panel, float dpi)
{
	bool returnValue = true;
	int retVal = 0;
    int iFormat = 0;
	PIXELFORMATDESCRIPTOR pfd = {};

	m_window = window;
	m_panel = panel;
	m_nWidth = (int)window->Bounds.Width;
	m_nHeight = (int)window->Bounds.Height;
    pfd.nSize = sizeof(pfd);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 24;
    pfd.iLayerType = PFD_MAIN_PLANE;

	if (!CreateDeviceIndependentResources())
	{
		returnValue = false;
	}
	else if (!CreateDeviceResources())
	{
		returnValue = false;
	}
	else if (!SetDpi(dpi))
	{
		returnValue = false;
	}
	else if (FALSE == glLoadLibrary("user32.dll", "gdi32.dll", "opengl32.dll"))
	{
		returnValue = false;
	}
	else if (nullptr == (m_hWnd = GetHWND(window)))
	{
		returnValue = false;
	}
	else if (nullptr == (m_hDC = GetDC(m_hWnd)))
	{
		returnValue = false;
	}
	else if (0 == (iFormat = ChoosePixelFormat(m_hDC, &pfd)))
	{
		returnValue = false;
	}
    else if (FALSE == (retVal = SetPixelFormat(m_hDC, iFormat, &pfd)))
	{
		returnValue = false;
	}
    else if (nullptr == (m_hGLRC = wglCreateContext(m_hDC)))
	{
		returnValue = false;
	}
	else if (FALSE == wglMakeCurrent(m_hDC, m_hGLRC))
	{
		returnValue = false;
	}	
	
	return returnValue;
}

bool Graphics::CreateDeviceIndependentResources()
{
	bool returnValue = true;
	HRESULT hr = S_OK;
	D2D1_FACTORY_OPTIONS options;

	ZeroMemory(&options, sizeof(D2D1_FACTORY_OPTIONS));

#if defined(_DEBUG)
	options.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
#endif

	if (S_OK != (hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, __uuidof(ID2D1Factory1), &options, &m_d2dFactory)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(IDWriteFactory), &m_dwriteFactory)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = CoCreateInstance(CLSID_WICImagingFactory, nullptr, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&m_wicFactory))))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_dwriteFactory->CreateTextFormat(L"Segoe UI", nullptr, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 42.0f, L"en-US", &m_textFormat)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_textFormat->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING)))
	{
		returnValue = false;
	}

	return returnValue;
}

bool Graphics::CreateDeviceResources()
{
	bool returnValue = true;
	HRESULT hr = S_OK;
	UINT creationFlags = D3D11_CREATE_DEVICE_BGRA_SUPPORT;
	ComPtr<IDXGIDevice> dxgiDevice;
	D3D_FEATURE_LEVEL featureLevels[] = 
	{
		D3D_FEATURE_LEVEL_11_1,
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1
	};
	ComPtr<ID3D11Device> d3dDevice;
	ComPtr<ID3D11DeviceContext> d3dContext;
	Platform::String^ text = "Hello, DirectX!";

#if defined(_DEBUG)
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	if (S_OK != (hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, 0, creationFlags, featureLevels, ARRAYSIZE(featureLevels), D3D11_SDK_VERSION, &d3dDevice, &m_d3dFeatureLevel, &d3dContext)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = d3dDevice.As(&m_d3dDevice)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = d3dContext.As(&m_d3dContext)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_d3dDevice.As(&dxgiDevice)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_d2dFactory->CreateDevice(dxgiDevice.Get(), &m_d2dDevice)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_d2dDevice->CreateDeviceContext(D2D1_DEVICE_CONTEXT_OPTIONS_NONE, &m_d2dContext)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_d2dContext->CreateSolidColorBrush(ColorF(ColorF::Black), &m_blackBrush)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_dwriteFactory->CreateTextLayout(text->Data(), text->Length(), m_textFormat.Get(), 700, 1000, &m_textLayout)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = m_textLayout->GetMetrics(&m_textMetrics)))
	{
		returnValue = false;
	}

	return returnValue;
}
		
bool Graphics::SetDpi(float dpi)
{
	bool returnValue = true;

	if (dpi != m_dpi)
	{
		m_dpi = dpi;
		
		m_d2dContext->SetDpi(m_dpi, m_dpi);
		UpdateForWindowSizeChange();
	}

	return returnValue;
}

bool Graphics::UpdateForWindowSizeChange()
{
	bool returnValue = true;

	if (DisplayProperties::LogicalDpi == m_dpi)
	{
		if (m_window->Bounds.Width  != m_windowBounds.Width ||
			m_window->Bounds.Height != m_windowBounds.Height ||
			m_orientation != DisplayProperties::CurrentOrientation)
		{
			ID3D11RenderTargetView* nullViews[] = {nullptr};
			m_d3dContext->OMSetRenderTargets(ARRAYSIZE(nullViews), nullViews, nullptr);
			m_d2dContext->SetTarget(nullptr);
			m_d2dTargetBitmap = nullptr;
			m_d3dRenderTargetView = nullptr;
			m_d3dDepthStencilView = nullptr;
			m_d3dContext->Flush();
			returnValue = CreateWindowSizeDependentResources();
		}
	}

	return returnValue;
}

bool Graphics::CreateWindowSizeDependentResources()
{
	bool returnValue = true;
	HRESULT hr = S_OK;
	m_windowBounds = m_window->Bounds;
	float windowWidth = ConvertDipsToPixels(m_windowBounds.Width);
	float windowHeight = ConvertDipsToPixels(m_windowBounds.Height);
	m_orientation = DisplayProperties::CurrentOrientation;
	bool swapDimensions = m_orientation == DisplayOrientations::Portrait || m_orientation == DisplayOrientations::PortraitFlipped;
	m_d3dRenderTargetSize.Width = swapDimensions ? windowHeight : windowWidth;
	m_d3dRenderTargetSize.Height = swapDimensions ? windowWidth : windowHeight;

	if (m_swapChain != nullptr)
	{
		hr = m_swapChain->ResizeBuffers(2, static_cast<UINT>(m_d3dRenderTargetSize.Width), static_cast<UINT>(m_d3dRenderTargetSize.Height), DXGI_FORMAT_B8G8R8A8_UNORM, 0);

		if (hr == DXGI_ERROR_DEVICE_REMOVED)
		{
			returnValue = HandleDeviceLost();
		}
		else
		{
			returnValue = false;
		}
	}
	else
	{
		DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {0};
		swapChainDesc.Width = static_cast<UINT>(m_d3dRenderTargetSize.Width); 
		swapChainDesc.Height = static_cast<UINT>(m_d3dRenderTargetSize.Height);
		swapChainDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		swapChainDesc.Stereo = false; 
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.BufferCount = 2; 
		swapChainDesc.Scaling = DXGI_SCALING_STRETCH;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL;
		swapChainDesc.Flags = 0;
		ComPtr<IDXGIDevice1> dxgiDevice;
		ComPtr<IDXGIAdapter> dxgiAdapter;
		ComPtr<IDXGIFactory2> dxgiFactory;
		ComPtr<ISwapChainBackgroundPanelNative> panelNative;
		ComPtr<ID3D11Texture2D> backBuffer;
		CD3D11_TEXTURE2D_DESC depthStencilDesc(DXGI_FORMAT_D24_UNORM_S8_UINT, static_cast<UINT>(m_d3dRenderTargetSize.Width), static_cast<UINT>(m_d3dRenderTargetSize.Height), 1, 1, D3D11_BIND_DEPTH_STENCIL);
		ComPtr<ID3D11Texture2D> depthStencil;
		CD3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc(D3D11_DSV_DIMENSION_TEXTURE2D);
		CD3D11_VIEWPORT viewport(0.0f, 0.0f, m_d3dRenderTargetSize.Width, m_d3dRenderTargetSize.Height);

		if (S_OK != (hr = m_d3dDevice.As(&dxgiDevice)))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = dxgiDevice->GetAdapter(&dxgiAdapter)))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = dxgiAdapter->GetParent(IID_PPV_ARGS(&dxgiFactory))))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = dxgiFactory->CreateSwapChainForComposition(m_d3dDevice.Get(), &swapChainDesc, nullptr, &m_swapChain)))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = reinterpret_cast<IUnknown*>(m_panel)->QueryInterface(IID_PPV_ARGS(&panelNative))))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = panelNative->SetSwapChain(m_swapChain.Get())))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = dxgiDevice->SetMaximumFrameLatency(1)))
		{
			returnValue = false;
		}
		else if (!SetDisplayOrientation())
		{
			returnValue = false;
		}
		else if (S_OK != (hr = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer))))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = m_d3dDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, &m_d3dRenderTargetView)))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = m_d3dDevice->CreateTexture2D(&depthStencilDesc, nullptr, &depthStencil)))
		{
			returnValue = false;
		}
		else if (S_OK != (hr = m_d3dDevice->CreateDepthStencilView(depthStencil.Get(), &depthStencilViewDesc, &m_d3dDepthStencilView)))
		{
			returnValue = false;
		}
		else
		{
			m_d3dContext->RSSetViewports(1, &viewport);
			D2D1_BITMAP_PROPERTIES1 bitmapProperties = BitmapProperties1(D2D1_BITMAP_OPTIONS_TARGET | D2D1_BITMAP_OPTIONS_CANNOT_DRAW, PixelFormat(DXGI_FORMAT_B8G8R8A8_UNORM, D2D1_ALPHA_MODE_PREMULTIPLIED), m_dpi, m_dpi);
			ComPtr<IDXGISurface> dxgiBackBuffer;

			if (S_OK != (hr = m_swapChain->GetBuffer(0, IID_PPV_ARGS(&dxgiBackBuffer))))
			{
				returnValue = false;
			}
			else if (S_OK != (hr = m_d2dContext->CreateBitmapFromDxgiSurface(dxgiBackBuffer.Get(), &bitmapProperties, &m_d2dTargetBitmap)))
			{
				returnValue = false;
			}
			else
			{
				m_d2dContext->SetTarget(m_d2dTargetBitmap.Get());
				m_d2dContext->SetTextAntialiasMode(D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE);
			}
		}
	}

	return returnValue;
}

bool Graphics::SetDisplayOrientation()
{
	bool returnValue = true;
	HRESULT hr = S_OK;

	DXGI_MODE_ROTATION rotation = DXGI_MODE_ROTATION_UNSPECIFIED;
	switch (m_orientation)
	{
		case DisplayOrientations::Landscape:
			rotation = DXGI_MODE_ROTATION_IDENTITY;
			m_orientationTransform2D = Matrix3x2F::Identity();
			m_orientationTransform3D = XMFLOAT4X4(
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
				);
			break;

		case DisplayOrientations::Portrait:
			rotation = DXGI_MODE_ROTATION_ROTATE270;
			m_orientationTransform2D = 
				Matrix3x2F::Rotation(270.0f) *
				Matrix3x2F::Translation(0.0f, m_windowBounds.Width);
			m_orientationTransform3D = XMFLOAT4X4(
				0.0f, 1.0f, 0.0f, 0.0f,
				-1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
				);
			break;

		case DisplayOrientations::LandscapeFlipped:
			rotation = DXGI_MODE_ROTATION_ROTATE180;
			m_orientationTransform2D = 
				Matrix3x2F::Rotation(180.0f) *
				Matrix3x2F::Translation(m_windowBounds.Width, m_windowBounds.Height);
			m_orientationTransform3D = XMFLOAT4X4(
				-1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, -1.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
				);
			break;

		case DisplayOrientations::PortraitFlipped:
			rotation = DXGI_MODE_ROTATION_ROTATE90;
			m_orientationTransform2D = 
				Matrix3x2F::Rotation(90.0f) *
				Matrix3x2F::Translation(m_windowBounds.Height, 0.0f);
			m_orientationTransform3D = XMFLOAT4X4(
				0.0f, -1.0f, 0.0f, 0.0f,
				1.0f, 0.0f, 0.0f, 0.0f,
				0.0f, 0.0f, 1.0f, 0.0f,
				0.0f, 0.0f, 0.0f, 1.0f
				);
			break;

		default:
			returnValue = false;
	}

	if (returnValue)
	{
		if (S_OK != (hr = m_swapChain->SetRotation(rotation)))
		{
			returnValue = false;
		}
	}

	return returnValue;
}

float Graphics::ConvertDipsToPixels(float dips)
{
	static const float dipsPerInch = 96.0f;
	return floor(dips * m_dpi / dipsPerInch + 0.5f);
}

bool Graphics::HandleDeviceLost()
{
	bool returnValue = true;
	float dpi = m_dpi;
	m_dpi = -1.0f;
	m_windowBounds.Width = 0;
	m_windowBounds.Height = 0;
	m_swapChain = nullptr;

	if (!CreateDeviceResources())
	{
		returnValue = false;
	}
	else if (!SetDpi(dpi))
	{
		returnValue = false;
	}
	return returnValue;
}

void Graphics::UpdateTextPosition(Point deltaTextPosition)
{
	m_textPosition.X += deltaTextPosition.X;
	m_textPosition.Y += deltaTextPosition.Y;
}

bool Graphics::ValidateDevice()
{
	bool returnValue = true;
	HRESULT hr = S_OK;
	ComPtr<IDXGIDevice1> dxgiDevice;
	ComPtr<IDXGIAdapter> deviceAdapter;
	DXGI_ADAPTER_DESC deviceDesc;
	ComPtr<IDXGIFactory2> dxgiFactory;
	ComPtr<IDXGIAdapter1> currentAdapter;
	DXGI_ADAPTER_DESC currentDesc;

	if (S_OK != (hr = m_d3dDevice.As(&dxgiDevice)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = dxgiDevice->GetAdapter(&deviceAdapter)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = deviceAdapter->GetDesc(&deviceDesc)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = CreateDXGIFactory1(IID_PPV_ARGS(&dxgiFactory))))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = dxgiFactory->EnumAdapters1(0, &currentAdapter)))
	{
		returnValue = false;
	}
	else if (S_OK != (hr = currentAdapter->GetDesc(&currentDesc)))
	{
		returnValue = false;
	}
	else if (deviceDesc.AdapterLuid.LowPart != currentDesc.AdapterLuid.LowPart ||
		deviceDesc.AdapterLuid.HighPart != currentDesc.AdapterLuid.HighPart ||
		(S_OK == (hr = m_d3dDevice->GetDeviceRemovedReason() ) ) ) 
	{
		dxgiDevice = nullptr;
		deviceAdapter = nullptr;
		returnValue = HandleDeviceLost();
	}

	return returnValue;
}

void Graphics::Update(float timeTotal, float timeDelta)
{
	(void) timeTotal;
	(void) timeDelta;
}

bool Graphics::Render()
{
	bool returnValue = true;

	m_d2dContext->BeginDraw();
	m_d2dContext->Clear(ColorF(ColorF::CornflowerBlue));
	Matrix3x2F translation = Matrix3x2F::Translation(
		m_windowBounds.Width / 2.0f - m_textMetrics.widthIncludingTrailingWhitespace / 2.0f + m_textPosition.X,
		m_windowBounds.Height / 2.0f - m_textMetrics.height / 2.0f + m_textPosition.Y
		);
	m_d2dContext->SetTransform(translation * m_orientationTransform2D);
	m_d2dContext->DrawTextLayout(
		Point2F(0.0f, 0.0f),
		m_textLayout.Get(),
		m_blackBrush.Get(),
		D2D1_DRAW_TEXT_OPTIONS_NO_SNAP
		);
	HRESULT hr = m_d2dContext->EndDraw();
	if (hr != D2DERR_RECREATE_TARGET)
	{
		returnValue = false;
	}

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	//glClear(GL_COLOR_BUFFER_BIT);
	//glPushMatrix();
	//glRotatef(0.0f, 0.0f, 0.0f, 1.0f);
	//glBegin(GL_TRIANGLES);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glVertex2f(0.0f, 1.0f);
	//glColor3f(0.0f, 1.0f, 0.0f);
	//glVertex2f(0.87f, -0.5f);
	//glColor3f(0.0f, 0.0f, 1.0f);   
	//glVertex2f(-0.87f, -0.5f);
	//glEnd();
	//glFlush();
	//glPopMatrix();
	//SwapBuffers(m_hDC);

	return returnValue; 
}

bool Graphics::Present()
{
	bool returnValue = true;
	DXGI_PRESENT_PARAMETERS parameters = {0};
	parameters.DirtyRectsCount = 0;
	parameters.pDirtyRects = nullptr;
	parameters.pScrollRect = nullptr;
	parameters.pScrollOffset = nullptr;
	HRESULT hr = m_swapChain->Present1(1, 0, &parameters);
	m_d3dContext->DiscardView(m_d3dRenderTargetView.Get());
	m_d3dContext->DiscardView(m_d3dDepthStencilView.Get());
	if (hr == DXGI_ERROR_DEVICE_REMOVED)
	{
		returnValue = HandleDeviceLost();
	}
	else
	{
		returnValue = false;
	}

	return returnValue;
}
