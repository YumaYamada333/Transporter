//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   RenderingManager.h
//!
//! @brief 描画に使用する各要素の管理クラスのソースファイル
//!
//! @date   2017/04/24		
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

//インクルード===============================================================
#include <Windows.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <SimpleMath.h>
#include <Algorithm>
#include <wrl.h>
#include "..\..\StepTimer.h"

//クラス＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
class RenderingResourceManager
{
private:
	HWND                                            m_window;				//ウィンドウ
	int                                             m_outputWidth;			//画面幅
	int                                             m_outputHeight;			//画面高さ

	D3D_FEATURE_LEVEL                               m_featureLevel;			//機能レベル
	Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;			//デバイス
	Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;			//コンテキスト
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

	Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;			//スワップチェーン
	Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;		//レンダーターゲットビュー
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;		//深度ステンシルビュー

public:
	RenderingResourceManager(HWND window, int width, int height);
	~RenderingResourceManager();
	void OnWindowSizeChanged(int width, int height);

	void Clear();
	void Present();

	ID3D11Device*				GetDevice();			
	ID3D11DeviceContext*		GetContext();

private:
	void CreateDevice();		//デバイスの作成
	void CreateResources();	

	void OnDeviceLost();
};
