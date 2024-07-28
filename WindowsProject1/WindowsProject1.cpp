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
#include <iostream>
#include <string>
#include "Utils.h"
#include "Main.h"
#include "Drawer.h"

using namespace utils;

EXTERN_C IMAGE_DOS_HEADER __ImageBase;
#define HINST_THISCOMPONENT ((HINSTANCE)&__ImageBase)

class MainWindow : public BaseWindow<MainWindow> {
public:
	ID2D1Factory* pFactory;
	ID2D1HwndRenderTarget* pRenderTarget;
	ID2D1SolidColorBrush* pBrush;
	D2D1_ELLIPSE ellipse;

	IWICImagingFactory* iwicFactory;

	void CalculateLayout();
	HRESULT CreateGraphicsResources();
	void DiscardGraphicsResources();
	void OnPaint();
	void Resize();



	MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL), iwicFactory(NULL), ellipse() {
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
		}
		if (SUCCEEDED(hr)) {
			CalculateLayout();
		}
		if (SUCCEEDED(hr)) {
			if (iwicFactory == NULL) {
				hr = CoCreateInstance(
					CLSID_WICImagingFactory,
					NULL,
					CLSCTX_INPROC_SERVER,
					IID_PPV_ARGS(&iwicFactory)
				);
			}
		}
		if (SUCCEEDED(hr)) {
			Drawer::ReadySprites(&hr, pRenderTarget, iwicFactory);
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
		pRenderTarget->Clear(D2D1::ColorF(D2D1::ColorF::Coral));

		//D2D1_POINT_2F upperLeft = D2D1::Point2F(100.0f, 10.0f);
		D2D1_RECT_F rcBrushRect = D2D1::RectF(
			upperLeft.x,
			upperLeft.y,
			upperLeft.x + 100,
			upperLeft.y + 100
		);

		pRenderTarget->FillEllipse(ellipse, pBrush);

		Drawer::DrawSprites(pRenderTarget, &rcBrushRect);

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

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int nCmdShow) {

	MainWindow win;

	if (!win.Create(L"Circle", WS_OVERLAPPEDWINDOW)) {
		return 0;
	}

	ShowWindow(win.Window(), TRUE);
	
	new Main(win.Window());
	TimedCodeController::RunStarts();

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

