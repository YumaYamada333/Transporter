//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  �v���C�V�[���̃w�b�_�t�@�C��
//!
//! @date   2016/12/12
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"
#include <d3d11.h>
#include <SimpleMath.h>

//class Cube;
//class GridFloor;
//class DebugCamera;

//�N���X
class Play:public GameBase
{
private:
	DirectX::SimpleMath::Matrix m_view;	// �r���[�s��
	DirectX::SimpleMath::Matrix m_proj;	// �ˉe�s��		
	DirectX::SimpleMath::Matrix m_world;	//���[���h�s��
	//GridFloor* m_grid_floor;		//�O���b�h��
	//DebugCamera* m_debug_camera;	//�f�o�b�O�J����
	//Cube* cube;

public:
	Play(RenderingResourceManager* rrm);
	~Play();
	void Update();
	void Render();
};
