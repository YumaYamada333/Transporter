//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   SceneManager.cpp
//!
//! @brief  �V�[���Ǘ��N���X�̃\�[�X�t�@�C��
//!
//! @date   2017/04/18		
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#include "SceneManager.h"

//�����o�֐�������������������������������������������������������������������

//----------------------------------------------------------------------
//! @brief �R���X�g���N�^
//!
//! @param[in] �����V�[���̔ԍ�
//----------------------------------------------------------------------
SceneManager::SceneManager(int scene_num, RenderingResourceManager* rrm)
	:m_NextScene(scene_num)
	,m_scene(GameBase::NONE)
	,m_init(0)
	,m_base(nullptr)
	,m_rendering_resource_manager(rrm)
{
	
}

//----------------------------------------------------------------------
//! @brief �f�X�g���N�^
//----------------------------------------------------------------------
SceneManager::~SceneManager()
{
	delete m_base;
}

//----------------------------------------------------------------------
//! @brief �V�[���}�l�[�W���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void SceneManager::Update()
{
	//���݂̃V�[�����X�V(null�`�F�b�N)
	if (m_base != nullptr) {
		m_NextScene = m_base->GetScene();
	}

	//�������݂̃V�[���ƑO�̃V�[�����Ⴄ�Ȃ�
	if (m_NextScene != m_scene){
		//���݂̃V�[����j��
		delete m_base;

		//�V�[����ύX
		m_scene = m_NextScene;	
		m_init	= 0;

		//�V�[���̌Ăяo��
		switch (m_scene){
		case GameBase::LOGO:		m_base = new Logo(m_rendering_resource_manager);	break;
		case GameBase::TITLE:		m_base = new Title(m_rendering_resource_manager);	break;
		case GameBase::PLAY:		m_base = new Play(m_rendering_resource_manager);	break;
		case GameBase::CLEAR:		m_base = new Clear(m_rendering_resource_manager);	break;
		case GameBase::OVER:		m_base = new Over(m_rendering_resource_manager);	break;
		}
	}

	//�V�[���̍X�V
	m_base->Update();
}

//----------------------------------------------------------------------
//! @brief �V�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void SceneManager::Render()
{
	m_base->Render();
}