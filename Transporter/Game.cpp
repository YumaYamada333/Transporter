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
