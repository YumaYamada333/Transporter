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
//! @brief �R���X�g���N�^
//!
//! @param[in] �Ȃ�
//----------------------------------------------------------------------
Game::Game()
{
	srand((unsigned int)time(nullptr));
}


//----------------------------------------------------------------------
//! @brief Initialize the Direct3D resources required to run.(Direct3D�̓���ɕK�v�ȗv�f�̏�����)
//!
//! @param[in] �E�B���h�E�A��ʕ��A��ʍ���
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Initialize(HWND window, int width, int height)
{
	//�����_�����O�}�l�[�W���̎��̉�
	m_rendering_manager = std::make_unique<RenderingResourceManager>(window, width, height);

	//�V�[���̎��̉�
	m_scene_manager = std::make_unique<SceneManager>(GameBase::TITLE, m_rendering_manager.get());

    // TODO: Change the timer settings if you want something other than the default variable timestep mode.
	//�i�^�C�}�[�̏����ݒ��ύX�������ꍇ�����ɏ����������j
    // e.g. for 60 FPS fixed timestep update logic, call:
    /*
    m_timer.SetFixedTimeStep(true);
    m_timer.SetTargetElapsedSeconds(1.0 / 60);
    */
}

//----------------------------------------------------------------------
//! @brief Executes the basic game loop.(��{�̃Q�[�����[�v�̎��s)
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
//! @brief Updates the world.(�Q�[���̍X�V)
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Update(DX::StepTimer const& timer)
{
    float elapsedTime = float(timer.GetElapsedSeconds());

    // TODO: Add your game logic here.
	// (�������牺�ɍX�V������ǉ�)
    elapsedTime;

	//�V�[���̍X�V
	m_scene_manager->Update();
}

//----------------------------------------------------------------------
//! @brief Draws the scene.(�Q�[���̕`��)
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Game::Render()
{
    // Don't try to render anything before the first Update.
	// (�ŏ��̍X�V�̑O�ɂ͕`�揈�����s��Ȃ�)
    if (m_timer.GetFrameCount() == 0)
    {
        return;
    }

    m_rendering_manager->Clear();

    // TODO: Add your rendering code here.
	// (�������牺�ɕ`�揈����ǉ�)

	//�V�[���̕`��
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
//! @brief ������ʃT�C�Y���擾
//!
//! @param[in] �������ϐ�(�Q��)
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
// Properties
void Game::GetDefaultSize(int& width, int& height) const
{
    // TODO: Change to desired default window size (note minimum size is 320x200).
    width  = SCREEN_WIDTH;
    height = SCREEN_HEIGHT;
}
