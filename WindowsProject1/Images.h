#include "Windows.h"
#include <d2d1.h>
#pragma comment(lib, "d2d1")
#include <wincodecsdk.h>
#include "Utils.h"
#pragma once

using namespace utils;

namespace image {
	HRESULT LoadBitmapFromFile(
		ID2D1RenderTarget* pRenderTarget,
		IWICImagingFactory* pIWICFactory,
		PCWSTR uri,
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

		HRESULT hr = pIWICFactory->CreateDecoderFromFilename(
			uri,
			NULL,
			GENERIC_READ,
			WICDecodeMetadataCacheOnLoad,
			&pDecoder
		);

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

			// Create a Direct2D bitmap from the WIC bitmap.
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
}
