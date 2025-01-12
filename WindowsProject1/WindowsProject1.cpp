#ifndef UNICODE
#define UNICODE
#endif 

#include "thread"
#include <windows.h>
#include <d2d1.h>
#pragma comment(lib, "d2d1")
#include <wincodecsdk.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "dwrite.h"
#include <filesystem>

#include "basewin.h"
#include "MoreVK.h"
#include "sstream"
#include "Utils.h"
#include "InputManager.h"
#include "Main.h"
#include "Drawer.h"
#include "MoreWM.h"
#include "Time.h"
#include "ColliderController.h"
#include "Print.h"
#include "GameManager.h"
#include "MenuManager.h"
#include "Death.h"

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

	IDWriteFactory* pDWriteFactory;

	void CalculateLayout();
	HRESULT CreateGraphicsResources();
	void DiscardGraphicsResources();
	void OnPaint();
	void Resize();

	bool dead;

	MainWindow() : pFactory(NULL), pRenderTarget(NULL), pBrush(NULL), iwicFactory(NULL), pDWriteFactory(NULL), ellipse() {
	}

	PCWSTR ClassName() const { return L"Dodecahedron"; }
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
};

void MainWindow::CalculateLayout() {
	if (pRenderTarget != NULL) {
		D2D1_SIZE_F size = pRenderTarget->GetSize();
		const float x = size.width / 2;
		const float y = size.height / 2;
		OutputDebugString((std::to_wstring(size.width) + L", " + std::to_wstring(size.height)).c_str());
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
			if (SUCCEEDED(hr)) {
				if (pDWriteFactory == NULL) {
					hr = DWriteCreateFactory(
						DWRITE_FACTORY_TYPE_SHARED,
						__uuidof(IDWriteFactory),
						reinterpret_cast<IUnknown**>(&pDWriteFactory)
					);
				}
			}
		}
	}
	if (SUCCEEDED(hr)) {
		Drawer::ReadySprites(&hr, pRenderTarget, iwicFactory);
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

		pRenderTarget->FillEllipse(ellipse, pBrush);

		Drawer::DrawSprites(pRenderTarget);
		hr = Drawer::DrawTexts(pRenderTarget, pDWriteFactory);

		if (SUCCEEDED(hr)) {
			hr = pRenderTarget->EndDraw();
			if (SUCCEEDED(hr)) {
				//DiscardGraphicsResources();
			}
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

std::thread thread;
MainWindow win;

static void ResetGame() {
	Drawer::Reset();
	ColliderController::Reset();
	InputManager::ResetKeys();
}

void StartGame() {
	GameManager::Setup(win.Window());
	thread = std::thread([] {
		while (true) {
			GameManager::state = State::BUTTON;
			Main* main = new Main(win.Window());
			GameManager::RegisterTimedCode(main);
			while (!win.dead) {
				Time::calcTimes();
				GameManager::Periodics();
				InputManager::ResetKeys();
				ColliderController::CheckCollisions();
				SendMessage(win.Window(), WM_PAINT, NULL, NULL);
			}
			ResetGame();
			delete main;
			win.dead = false;
		}
		});
	thread.detach();
}

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE, _In_ PWSTR, _In_ int nCmdShow) {

	if (!win.Create(L"Circle", WS_OVERLAPPEDWINDOW)) {
		return 0;
	}

	ShowWindow(win.Window(), TRUE);
	Print::hy(win.Window());

	MSG msg = { };

	StartGame();
	PlaySound((std::filesystem::current_path().wstring() + L"\\yessong.wav").c_str(), NULL, SND_LOOP | SND_ASYNC);

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
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
		m_hwnd = NULL;
		GameManager::Reset();
		ColliderController::Reset();
		Drawer::Reset();
		return 0;

	case WM_PAINT:
		OnPaint();
		return 0;

	case WM_SIZE:
		Resize();
		return 0;

	case WM_KEYDOWN:
		InputManager::SetKeyDown((int)wParam);
		return 0;
	case WM_KEYUP:
		InputManager::SetKeyUp((int)wParam);
		return 0;

	case WM_DRAWSPRITES:
		if (pRenderTarget) {
			pRenderTarget->BeginDraw();
			Drawer::DrawSprites(pRenderTarget);
			pRenderTarget->EndDraw();
		}
		break;

	case WM_PRINTTHREAD:
		Print::Printy();
		break;

	case WM_RESET:
		dead = true;
		break;

	case WM_DIE:
		GameManager::SetState(State::DEATH);
		//Drawer::Reset();
		ColliderController::Reset();
		new Death();
		break;
	}

	return DefWindowProc(m_hwnd, uMsg, wParam, lParam);
}

