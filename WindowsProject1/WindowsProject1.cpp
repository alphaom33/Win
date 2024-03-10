#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")
#include <wincodecsdk.h>
#include <stdio.h>
#include <string>

#include "basewin.h"
#include "MoreVK.h"
#include "InputManager.h"
#include "TimedCodeController.h"
#include "TimedCodeIncludes.h"
#include <string>

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)

template <class T> void SafeRelease(T** ppT) {
	if (*ppT) {
		(*ppT)->Release();
		*ppT = NULL;
	}
}


HRESULT LoadResourceBitmap(
	ID2D1RenderTarget* pRenderTarget,
	IWICImagingFactory* pIWICFactory,
	PCWSTR resourceName,
	PCWSTR resourceType,
	UINT destinationWidth,
	UINT destinationHeight,
	ID2D1Bitmap** ppBitmap
);

class MainWindow : public BaseWindow<MainWindow> {
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
	D2D1_ELLIPSE ellipse;

	IWICImagingFactory* iwicFactory;
	ID2D1Bitmap* bitmap;

	void CalculateLayout();
	HRESULT CreateGraphicsResources();
	void DiscardGraphicsResources();
	void OnPaint();
	void Resize();



public:
	MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL), iwicFactory(NULL) {
	}

	PCWSTR ClassName() const { return L"Dodecahedron"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

void MainWindow::CalculateLayout() {
	if (pRenderTarget != NULL) {
		D2D1_SIZE_F size = pRenderTarget->GetSize();
		const float x = size.width / 2;
		const float y = size.height / 2;
		const float radius = min(x, y);
		ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
	}
}

HRESULT MainWindow::CreateGraphicsResources() {
	HRESULT hr = S_OK;
	if (pRenderTarget == NULL) {
		RECT rc;
		GetClientRect(m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		hr = pFactory->CreateHwndRenderTarget(
			D2D1::RenderTargetProperties(),
			D2D1::HwndRenderTargetProperties(m_hwnd, size),
			&pRenderTarget
		);

		if (SUCCEEDED(hr)) {
			const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
			hr = pRenderTarget->CreateSolidColorBrush(color, &pBrush);
			
			if (SUCCEEDED(hr)) {
				CalculateLayout();
				if (SUCCEEDED(hr)) {
					hr = LoadResourceBitmap(
						pRenderTarget,
						iwicFactory,
						L"SampleImage",
						L"Image",
						200,
						0,
						&bitmap
					);
				}
			}
		}
	}
	
	return hr;
}

void MainWindow::DiscardGraphicsResources() {
	SafeRelease(&pRenderTarget);
	SafeRelease(&pBrush);
}

void MainWindow::OnPaint() {

	HRESULT hr = CreateGraphicsResources();
	if (SUCCEEDED(hr)) {
		PAINTSTRUCT ps;
		BeginPaint(m_hwnd, &ps);

		pRenderTarget->BeginDraw();
		pRenderTarget->Clear();

		D2D1_SIZE_F size = bitmap->GetSize();
		D2D1_POINT_2F upperLeft = D2D1::Point2F(100.0f, 10.0f);

		pRenderTarget->DrawBitmap(
			bitmap,
			D2D1::RectF(
				upperLeft.x,
				upperLeft.y,
				upperLeft.x + size.width,
				upperLeft.y + size.height
			)
		);

		pRenderTarget->FillEllipse(ellipse, pBrush);

		hr = pRenderTarget->EndDraw();
		if (SUCCEEDED(hr)) {
			DiscardGraphicsResources();
		}
		EndPaint(m_hwnd, &ps);
	}
}

void MainWindow::Resize() {
	if (pRenderTarget != NULL) {
		RECT rc;
		GetClientRect(m_hwnd, &rc);

		D2D1_SIZE_U size = D2D1::SizeU(rc.right, rc.bottom);

		pRenderTarget->Resize(size);
		CalculateLayout();
		InvalidateRect(m_hwnd, NULL, FALSE);
	}
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR, int nCmdShow) {

	MainWindow win;

	if (!win.Create(L"Circle", WS_OVERLAPPEDWINDOW)) {
		return 0;
	}

	ShowWindow(win.Window(), TRUE);
	
	IncludeTimedCodes(win.Window());
	TimedCodeController::RunStarts();

	
	MessageBox(NULL, L"wow it Succeeded", L"yay", MB_OK);
	MSG msg = { };
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		TimedCodeController::RunPeriodics();
	}

	return 0;
}

LRESULT MainWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
	case WM_CREATE:
		if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &pFactory))) {
			return -1;
		}
		return 0;

	case WM_DESTROY:
		DiscardGraphicsResources();
		SafeRelease(&pFactory);
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
		OnPaint();
		return 0;

	case WM_SIZE:
		Resize();
		return 0;

	case WM_KEYDOWN:
		SetKeyDown((int)wParam);
		return 0;

	case WM_KEYUP:
		SetKeyUp((int)wParam);
		return 0;
	}


	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

HRESULT LoadResourceBitmap(
	ID2D1RenderTarget* pRenderTarget,
	IWICImagingFactory* pIWICFactory,
	PCWSTR resourceName,
	PCWSTR resourceType,
	UINT destinationWidth,
	UINT destinationHeight,
	ID2D1Bitmap** ppBitmap
)
{

	IWICBitmapDecoder* pDecoder = NULL;
	IWICBitmapFrameDecode* pSource = NULL;
	IWICStream* pStream = NULL;
	IWICFormatConverter* pConverter = NULL;
	IWICBitmapScaler* pScaler = NULL;

	HRSRC imageResHandle = NULL;
	HGLOBAL imageResDataHandle = NULL;
	void* pImageFile = NULL;
	DWORD imageFileSize = 0;
	

	// Locate the resource.
	imageResHandle = FindResourceW(HINST_THISCOMPONENT, resourceName, resourceType);
	HRESULT hr = imageResHandle ? S_OK : E_FAIL;
	if (SUCCEEDED(hr))
	{
		// Load the resource.
		imageResDataHandle = LoadResource(HINST_THISCOMPONENT, imageResHandle);

		hr = imageResDataHandle ? S_OK : E_FAIL;
	}

	if (SUCCEEDED(hr))
	{
		// Lock it to get a system memory pointer.
		pImageFile = LockResource(imageResDataHandle);

		hr = pImageFile ? S_OK : E_FAIL;
	}
	if (SUCCEEDED(hr))
	{
		// Calculate the size.
		imageFileSize = SizeofResource(HINST_THISCOMPONENT, imageResHandle);

		hr = imageFileSize ? S_OK : E_FAIL;

	}

	if (SUCCEEDED(hr))
	{
		// Lock it to get a system memory pointer.
		pImageFile = LockResource(imageResDataHandle);

		hr = pImageFile ? S_OK : E_FAIL;
	}
	if (SUCCEEDED(hr))
	{
		// Calculate the size.
		imageFileSize = SizeofResource(HINST_THISCOMPONENT, imageResHandle);

		hr = imageFileSize ? S_OK : E_FAIL;

	}
	if (SUCCEEDED(hr))
	{
		// Create a WIC stream to map onto the memory.
		hr = pIWICFactory->CreateStream(&pStream);
	}
	if (SUCCEEDED(hr))
	{
		// Initialize the stream with the memory pointer and size.
		hr = pStream->InitializeFromMemory(
			reinterpret_cast<BYTE*>(pImageFile),
			imageFileSize
		);
	}
	if (SUCCEEDED(hr))
	{
		// Create a decoder for the stream.
		hr = pIWICFactory->CreateDecoderFromStream(
			pStream,
			NULL,
			WICDecodeMetadataCacheOnLoad,
			&pDecoder
		);
	}
	if (SUCCEEDED(hr))
	{
		// Create the initial frame.
		hr = pDecoder->GetFrame(0, &pSource);
	}
	if (SUCCEEDED(hr))
	{
		// Convert the image format to 32bppPBGRA
		// (DXGI_FORMAT_B8G8R8A8_UNORM + D2D1_ALPHA_MODE_PREMULTIPLIED).
		hr = pIWICFactory->CreateFormatConverter(&pConverter);
	}

	if (SUCCEEDED(hr))
	{
		hr = pConverter->Initialize(
			pSource,
			GUID_WICPixelFormat32bppPBGRA,
			WICBitmapDitherTypeNone,
			NULL,
			0.f,
			WICBitmapPaletteTypeMedianCut
		);
	}
	if (SUCCEEDED(hr))
	{
		//create a Direct2D bitmap from the WIC bitmap.
		hr = pRenderTarget->CreateBitmapFromWicBitmap(
			pConverter,
			NULL,
			ppBitmap
		);

	}

	SafeRelease(&pDecoder);
	SafeRelease(&pSource);
	SafeRelease(&pStream);
	SafeRelease(&pConverter);
	SafeRelease(&pScaler);


	return hr;
}

//wchar_t* convertCharArrayToLPCWSTR(const char* charArray)
//{
//	wchar_t* wString = new wchar_t[4096];
//	MultiByteToWideChar(CP_ACP, 0, charArray, -1, wString, 4096);
//	return wString;
//}
