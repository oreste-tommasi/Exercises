#pragma once

#include <wrl/client.h>
#include <d3d11_1.h>
#include <d2d1_1.h>
#include <d2d1effects.h>
#include <dwrite_1.h>
#include <wincodec.h>
#include <DirectXMath.h>
#include <agile.h>

using namespace Windows::UI::Core;
using namespace Windows::UI::Xaml::Controls;

namespace OpenGraphicsLibrary
{
	[Windows::Foundation::Metadata::WebHostHidden]
    public ref class Graphics sealed
    {
    public:
        Graphics();
		bool Initialize(CoreWindow^ window, SwapChainBackgroundPanel^ panel, float dpi);
		void UpdateTextPosition(Windows::Foundation::Point deltaTextPosition);
		bool UpdateForWindowSizeChange();
		bool SetDpi(float dpi);
		bool ValidateDevice();
		void Update(float timeTotal, float timeDelta);
		bool Render();
		bool Present();

	private:
		bool CreateDeviceIndependentResources();
		bool CreateDeviceResources();
		bool CreateWindowSizeDependentResources();
		float ConvertDipsToPixels(float dips);
		bool HandleDeviceLost();
		bool SetDisplayOrientation();

	protected private:
		Platform::Agile<Windows::UI::Core::CoreWindow> m_window;
		Windows::UI::Xaml::Controls::SwapChainBackgroundPanel^ m_panel;
		Microsoft::WRL::ComPtr<IDWriteFactory1> m_dwriteFactory;
		Microsoft::WRL::ComPtr<IWICImagingFactory2> m_wicFactory;
		Microsoft::WRL::ComPtr<ID3D11Device1> m_d3dDevice;
		Microsoft::WRL::ComPtr<ID3D11DeviceContext1> m_d3dContext;
		Microsoft::WRL::ComPtr<IDXGISwapChain1> m_swapChain;
		Microsoft::WRL::ComPtr<ID3D11RenderTargetView> m_d3dRenderTargetView;
		Microsoft::WRL::ComPtr<ID2D1Factory1> m_d2dFactory;
		Microsoft::WRL::ComPtr<ID2D1Device> m_d2dDevice;
		Microsoft::WRL::ComPtr<ID2D1DeviceContext> m_d2dContext;
		Microsoft::WRL::ComPtr<ID2D1Bitmap1> m_d2dTargetBitmap;
		Microsoft::WRL::ComPtr<ID3D11DepthStencilView> m_d3dDepthStencilView;
		D3D_FEATURE_LEVEL m_d3dFeatureLevel;
		Windows::Foundation::Size m_d3dRenderTargetSize;
		Windows::Foundation::Rect m_windowBounds;
		float m_dpi;
		Windows::Graphics::Display::DisplayOrientations m_orientation;
		D2D1::Matrix3x2F m_orientationTransform2D;
		DirectX::XMFLOAT4X4 m_orientationTransform3D;
		Microsoft::WRL::ComPtr<ID2D1SolidColorBrush> m_blackBrush;
		Microsoft::WRL::ComPtr<IDWriteTextFormat> m_textFormat;
		Microsoft::WRL::ComPtr<IDWriteTextLayout> m_textLayout;
		DWRITE_TEXT_METRICS m_textMetrics;
		Windows::Foundation::Point m_textPosition;
		int m_backgroundColorIndex;
		int m_nWidth;
		int m_nHeight;
		HWND m_hWnd;
		HDC m_hDC;
		HGLRC m_hGLRC;
	};
}