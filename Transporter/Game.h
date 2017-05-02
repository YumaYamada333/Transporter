//
// Game.h
//

#pragma once

//インクルード===============================================================
#include <Windows.h>
#include <d3d11.h>
#include <SimpleMath.h>
#include "StepTimer.h"
#include "Game\Scene\SceneManager.h"
#include "Game\Render\RenderingResourceManager.h"

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:
	//定数
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:

	// Device resources.
	//HWND                                            m_window;
	//int                                             m_outputWidth;
	//int                                             m_outputHeight;

	//D3D_FEATURE_LEVEL                               m_featureLevel;			//機能レベル
	//Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;			//デバイス
	//Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
	//Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;			//コンテキスト
	//Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

	//Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;			//スワップチェーン
	//Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
	//Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;		//レンダーターゲットビュー
	//Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;		//深度ステンシルビュー
																		
	DX::StepTimer                                   m_timer;				// Rendering loop timer.(フレーム管理？)

	std::unique_ptr<SceneManager>					m_scene_manager;		//シーン管理オブジェクト
	std::unique_ptr<RenderingResourceManager>		m_rendering_manager;	//描画管理オブジェクト

public:

    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    /*void Clear();
    void Present();*/

    //void CreateDevice();		//デバイスを作成
    //void CreateResources();		

    //void OnDeviceLost();
};