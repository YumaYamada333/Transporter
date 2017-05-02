//
// Game.h
//

#pragma once

//�C���N���[�h===============================================================
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
	//�萔
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 600;

private:

	DX::StepTimer                                   m_timer;				// Rendering loop timer.(�t���[���Ǘ��H)

	std::unique_ptr<SceneManager>					m_scene_manager;		//�V�[���Ǘ��I�u�W�F�N�g
	std::unique_ptr<RenderingResourceManager>		m_rendering_manager;	//�`��Ǘ��I�u�W�F�N�g

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
};