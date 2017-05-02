//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   SceneManager.h
//!
//! @brief  �V�[���Ǘ��N���X�̃w�b�_�t�@�C��
//!
//! @date   2017/04/18		
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

//�w�b�_��������������������������������������������������������������������
#include "Base_virtual\GameBase.h"
#include "Clear\GameClear.h"
#include "Logo\GameLogo.h"
#include "Play\GamePlay.h"
#include "Over\GameOver.h"
#include "Title\GameTitle.h"

#include "..\Render\RenderingResourceManager.h"

//�萔������������������������������������������������������������������
class GameBase;

//�N���X������������������������������������������������������������������
class SceneManager
{
private:
	GameBase*					m_base;							//�V�[��
	RenderingResourceManager*	m_rendering_resource_manager;	//�����_�����O�}�l�[�W���̃|�C���^
	int							m_scene;						//�V�[���Ǘ�
	int							m_NextScene;					//���̃V�[��
	int							m_init;							//�������Ǘ�

public:
	SceneManager(int scene, RenderingResourceManager* rrm);	//�R���X�g���N�^
	~SceneManager();										//�f�X�g���N�^
	void Update();											//�X�V
	void Render();											//�`��
};