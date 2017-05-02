//
// Game.cpp
//

#include <ctime>
#include "pch.h"
#include "Game.h"

extern void ExitGame();

using namespace DirectX;

using Microsoft::WRL::ComPtr;


//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] なし
//----------------------------------------------------------------------
Game::Game()
  /*  m_window(0),
    m_outputWidth(800),
    m_outputHeight(600),
    m_featureLevel(D3D_FEATURE_LEVEL_9_1)*/
{
	srand((unsigned int)time(nullptr));
}


//----------------------------------------------------------------------
//! @brief Initialize the Direct3D resources required to run.(Direct3Dの動作に必要な要素の初期化)
//!
//! @param[in] ウィンドウ、画面幅、画面高さ
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Initialize(HWND window, int width, int height)
{
	//レンダリングマネージャの実体化
	m_rendering_manager = std::make_unique<RenderingResourceManager>(window, width, height);

	//シーンの実体化
	m_scene_manager = std::make_unique<SceneManager>(GameBase::TITLE, m_rendering_manager.get());

    /*m_window = window;
    m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);

    CreateDevice();

    CreateResources();*/

    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
	//（タイマーの初期設定を変更したい場合ここに処理を書く）
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */
}

//----------------------------------------------------------------------
//! @brief Executes the basic game loop.(基本のゲームループの実行)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Tick()
{
    m_timer.Tick([&]()
    {
        Update(m_timer);
    });

    Render();
}


//----------------------------------------------------------------------
//! @brief Updates the world.(ゲームの更新)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
	// (ここから下に更新処理を追加)
    elapsedTime;

	//シーンの更新
	m_scene_manager->Update();
}

//----------------------------------------------------------------------
//! @brief Draws the scene.(ゲームの描画)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Game::Render()
{
    // Don't try to render anything before the first Update.
	// (最初の更新の前には描画処理を行わない)
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    m_rendering_manager->Clear();

    // TODO: Add your rendering code here.
	// (ここから下に描画処理を追加)

	//シーンの描画
	m_scene_manager->Render();

	m_rendering_manager->Present();
}


//----------------------------------------------------------------------
//! @brief Helper method to clear the back buffers.(バックバッファのクリアを補助する)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
//使っているのか？
//void Game::Clear()
//{
//    // Clear the views.
//	//（ビューをクリア）
//    m_d3dContext->ClearRenderTargetView(m_renderTargetView.Get(), Colors::CornflowerBlue);
//    m_d3dContext->ClearDepthStencilView(m_depthStencilView.Get(), D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
//
//    m_d3dContext->OMSetRenderTargets(1, m_renderTargetView.GetAddressOf(), m_depthStencilView.Get());
//
//    // Set the viewport.
//	//(表示領域を設定)
//    CD3D11_VIEWPORT viewport(0.0f, 0.0f, static_cast<float>(m_outputWidth), static_cast<float>(m_outputHeight));
//    m_d3dContext->RSSetViewports(1, &viewport);
//}

//----------------------------------------------------------------------
//! @brief Presents the back buffer contents to the screen.(バックバッファ上のモノをスクリーンに送る)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
//void Game::Present()
//{
//    // The first argument instructs DXGI to block until VSync, putting the application
//    // to sleep until the next VSync. This ensures we don't waste any cycles rendering
//    // frames that will never be displayed to the screen.
//    HRESULT hr = m_swapChain->Present(1, 0);
//
//    // If the device was reset we must completely reinitialize the renderer.
//    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
//    {
//        OnDeviceLost();
//    }
//    else
//    {
//        DX::ThrowIfFailed(hr);
//    }
//}

// Message handlers
void Game::OnActivated()
{
    // TODO: Game is becoming active window.
}

void Game::OnDeactivated()
{
    // TODO: Game is becoming background window.
}

void Game::OnSuspending()
{
    // TODO: Game is being power-suspended (or minimized).
}

void Game::OnResuming()
{
    m_timer.ResetElapsedTime();

    // TODO: Game is being power-resumed (or returning from minimize).
}

void Game::OnWindowSizeChanged(int width, int height)
{
   /* m_outputWidth = std::max(width, 1);
    m_outputHeight = std::max(height, 1);*/
	/*m_outputWidth = width;
	m_outputHeight = height;

    CreateResources();*/
	m_rendering_manager->OnWindowSizeChanged(width, height);

    // TODO: Game window is being resized.
}

//----------------------------------------------------------------------
//! @brief 初期画面サイズを取得
//!
//! @param[in] 代入する変数(参照)
//!
//! @return なし
//----------------------------------------------------------------------
// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width  = SCREEN_WIDTH;
    height = SCREEN_HEIGHT;
}

//----------------------------------------------------------------------
//! @brief These are the resources that depend on the device.(デバイス関連の諸機能のセットアップ)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
//void Game::CreateDevice()
//{
//    UINT creationFlags = 0;
//
//#ifdef _DEBUG
//    creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
//#endif
//
//    static const D3D_FEATURE_LEVEL featureLevels [] =
//    {
//        // TODO: Modify for supported Direct3D feature levels (see code below related to 11.1 fallback handling).
//        D3D_FEATURE_LEVEL_11_1,
//        D3D_FEATURE_LEVEL_11_0,
//        D3D_FEATURE_LEVEL_10_1,
//        D3D_FEATURE_LEVEL_10_0,
//        D3D_FEATURE_LEVEL_9_3,
//        D3D_FEATURE_LEVEL_9_2,
//        D3D_FEATURE_LEVEL_9_1,
//    };
//
//    // Create the DX11 API device object, and get a corresponding context.
//    HRESULT hr = D3D11CreateDevice(
//        nullptr,                                // specify nullptr to use the default adapter
//        D3D_DRIVER_TYPE_HARDWARE,
//        nullptr,
//        creationFlags,
//        featureLevels,
//        _countof(featureLevels),
//        D3D11_SDK_VERSION,
//        m_d3dDevice.ReleaseAndGetAddressOf(),   // returns the Direct3D device created
//        &m_featureLevel,                        // returns feature level of device created
//        m_d3dContext.ReleaseAndGetAddressOf()   // returns the device immediate context
//        );
//
//    if (hr == E_INVALIDARG)
//    {
//        // DirectX 11.0 platforms will not recognize D3D_FEATURE_LEVEL_11_1 so we need to retry without it.
//        hr = D3D11CreateDevice(nullptr,
//            D3D_DRIVER_TYPE_HARDWARE,
//            nullptr,
//            creationFlags,
//            &featureLevels[1],
//            _countof(featureLevels) - 1,
//            D3D11_SDK_VERSION,
//            m_d3dDevice.ReleaseAndGetAddressOf(),
//            &m_featureLevel,
//            m_d3dContext.ReleaseAndGetAddressOf()
//            );
//    }
//
//    DX::ThrowIfFailed(hr);
//
//#ifndef NDEBUG
//    ComPtr<ID3D11Debug> d3dDebug;
//    if (SUCCEEDED(m_d3dDevice.As(&d3dDebug)))
//    {
//        ComPtr<ID3D11InfoQueue> d3dInfoQueue;
//        if (SUCCEEDED(d3dDebug.As(&d3dInfoQueue)))
//        {
//#ifdef _DEBUG
//            d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_CORRUPTION, true);
//            d3dInfoQueue->SetBreakOnSeverity(D3D11_MESSAGE_SEVERITY_ERROR, true);
//#endif
//            D3D11_MESSAGE_ID hide [] =
//            {
//                D3D11_MESSAGE_ID_SETPRIVATEDATA_CHANGINGPARAMS,
//                // TODO: Add more message IDs here as needed.
//            };
//            D3D11_INFO_QUEUE_FILTER filter = {};
//            filter.DenyList.NumIDs = _countof(hide);
//            filter.DenyList.pIDList = hide;
//            d3dInfoQueue->AddStorageFilterEntries(&filter);
//        }
//    }
//#endif
//
//    // DirectX 11.1 if present
//    if (SUCCEEDED(m_d3dDevice.As(&m_d3dDevice1)))
//        (void)m_d3dContext.As(&m_d3dContext1);
//
//    // TODO: Initialize device dependent objects here (independent of window size).
//}

//----------------------------------------------------------------------
//! @brief Allocate all memory resources that change on a window SizeChanged event.(全てのメモリにウィンドウ変更関連のリソースを割り振る)
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
//void Game::CreateResources()
//{
    //// Clear the previous window size specific context.
    //ID3D11RenderTargetView* nullViews [] = { nullptr };
    //m_d3dContext->OMSetRenderTargets(_countof(nullViews), nullViews, nullptr);
    //m_renderTargetView.Reset();
    //m_depthStencilView.Reset();
    //m_d3dContext->Flush();
    //UINT backBufferWidth = static_cast<UINT>(m_outputWidth);
    //UINT backBufferHeight = static_cast<UINT>(m_outputHeight);
    //DXGI_FORMAT backBufferFormat = DXGI_FORMAT_B8G8R8A8_UNORM;
    //DXGI_FORMAT depthBufferFormat = DXGI_FORMAT_D24_UNORM_S8_UINT;
    //UINT backBufferCount = 2;
    //// If the swap chain already exists, resize it, otherwise create one.
    //if (m_swapChain)
    //{
    //    HRESULT hr = m_swapChain->ResizeBuffers(backBufferCount, backBufferWidth, backBufferHeight, backBufferFormat, 0);
    //    if (hr == DXGI_ERROR_DEVICE_REMOVED || hr == DXGI_ERROR_DEVICE_RESET)
    //    {
    //        // If the device was removed for any reason, a new device and swap chain will need to be created.
    //        OnDeviceLost();
    //        // Everything is set up now. Do not continue execution of this method. OnDeviceLost will reenter this method 
    //        // and correctly set up the new device.
    //        return;
    //    }
    //    else
    //    {
    //        DX::ThrowIfFailed(hr);
    //    }
    //}
    //else
    //{
    //    // First, retrieve the underlying DXGI Device from the D3D Device.
    //    ComPtr<IDXGIDevice1> dxgiDevice;
    //    DX::ThrowIfFailed(m_d3dDevice.As(&dxgiDevice));
    //    // Identify the physical adapter (GPU or card) this device is running on.
    //    ComPtr<IDXGIAdapter> dxgiAdapter;
    //    DX::ThrowIfFailed(dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf()));
    //    // And obtain the factory object that created it.
    //    ComPtr<IDXGIFactory1> dxgiFactory;
    //    DX::ThrowIfFailed(dxgiAdapter->GetParent(IID_PPV_ARGS(dxgiFactory.GetAddressOf())));
    //    ComPtr<IDXGIFactory2> dxgiFactory2;
    //    if (SUCCEEDED(dxgiFactory.As(&dxgiFactory2)))
    //    {
    //        // DirectX 11.1 or later
    //        // Create a descriptor for the swap chain.
    //        DXGI_SWAP_CHAIN_DESC1 swapChainDesc = { 0 };
    //        swapChainDesc.Width = backBufferWidth;
    //        swapChainDesc.Height = backBufferHeight;
    //        swapChainDesc.Format = backBufferFormat;
    //        swapChainDesc.SampleDesc.Count = 1;
    //        swapChainDesc.SampleDesc.Quality = 0;
    //        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    //        swapChainDesc.BufferCount = backBufferCount;
    //        DXGI_SWAP_CHAIN_FULLSCREEN_DESC fsSwapChainDesc = { 0 };
    //        fsSwapChainDesc.Windowed = TRUE;
    //        // Create a SwapChain from a Win32 window.
    //        DX::ThrowIfFailed(dxgiFactory2->CreateSwapChainForHwnd(
    //            m_d3dDevice.Get(),
    //            m_window,
    //            &swapChainDesc,
    //            &fsSwapChainDesc,
    //            nullptr,
    //            m_swapChain1.ReleaseAndGetAddressOf()
    //            ));
    //        DX::ThrowIfFailed(m_swapChain1.As(&m_swapChain));
    //    }
    //    else
    //    {
    //        DXGI_SWAP_CHAIN_DESC swapChainDesc = { 0 };
    //        swapChainDesc.BufferCount = backBufferCount;
    //        swapChainDesc.BufferDesc.Width = backBufferWidth;
    //        swapChainDesc.BufferDesc.Height = backBufferHeight;
    //        swapChainDesc.BufferDesc.Format = backBufferFormat;
    //        swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    //        swapChainDesc.OutputWindow = m_window;
    //        swapChainDesc.SampleDesc.Count = 1;
    //        swapChainDesc.SampleDesc.Quality = 0;
    //        swapChainDesc.Windowed = TRUE;
    //        DX::ThrowIfFailed(dxgiFactory->CreateSwapChain(m_d3dDevice.Get(), &swapChainDesc, m_swapChain.ReleaseAndGetAddressOf()));
    //    }
    //    // This template does not support exclusive fullscreen mode and prevents DXGI from responding to the ALT+ENTER shortcut.
    //    DX::ThrowIfFailed(dxgiFactory->MakeWindowAssociation(m_window, DXGI_MWA_NO_ALT_ENTER));
    //}
    //// Obtain the backbuffer for this window which will be the final 3D rendertarget.
    //ComPtr<ID3D11Texture2D> backBuffer;
    //DX::ThrowIfFailed(m_swapChain->GetBuffer(0, IID_PPV_ARGS(backBuffer.GetAddressOf())));
    //// Create a view interface on the rendertarget to use on bind.
    //DX::ThrowIfFailed(m_d3dDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, m_renderTargetView.ReleaseAndGetAddressOf()));
    //// Allocate a 2-D surface as the depth/stencil buffer and
    //// create a DepthStencil view on this surface to use on bind.
    //CD3D11_TEXTURE2D_DESC depthStencilDesc(depthBufferFormat, backBufferWidth, backBufferHeight, 1, 1, D3D11_BIND_DEPTH_STENCIL);
    //ComPtr<ID3D11Texture2D> depthStencil;
    //DX::ThrowIfFailed(m_d3dDevice->CreateTexture2D(&depthStencilDesc, nullptr, depthStencil.GetAddressOf()));
    //CD3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc(D3D11_DSV_DIMENSION_TEXTURE2D);
    //DX::ThrowIfFailed(m_d3dDevice->CreateDepthStencilView(depthStencil.Get(), &depthStencilViewDesc, m_depthStencilView.ReleaseAndGetAddressOf()));
    //// TODO: Initialize windows-size dependent objects here.
//}

//void Game::OnDeviceLost()
//{
    //// TODO: Add Direct3D resource cleanup here.
    //m_depthStencilView.Reset();
    //m_renderTargetView.Reset();
    //m_swapChain1.Reset();
    //m_swapChain.Reset();
    //m_d3dContext1.Reset();
    //m_d3dContext.Reset();
    //m_d3dDevice1.Reset();
    //m_d3dDevice.Reset();
    //CreateDevice();
    //CreateResources();
//}