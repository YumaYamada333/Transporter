//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameBase.h
//!
//! @brief  �V�[���̊�{�̃w�b�_�t�@�C��
//!
//! @date   2016/12/16
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "..\..\Render\RenderingResourceManager.h"

class GameBase
{
public:
	enum SCENE		//�V�[���Ǘ��p
	{
		NONE,
		LOGO,
		TITLE,
		PLAY,
		CLEAR,
		OVER
	};

private:
	SCENE						m_scene;					//���݂̃V�[��
	bool						m_init;						//�V�[�����߂̃t���O

protected:
	RenderingResourceManager*	m_render_resource_manager;	//�����_�����O�}�l�[�W���\

public:
	//�R���X�g���N�^(�V�[����n���ď�����)
	GameBase(SCENE scene, RenderingResourceManager* rrm) : 
		m_scene(scene), m_init(false), m_render_resource_manager(rrm) {};	

	//���݂̃V�[�����擾
	SCENE GetScene() {
		return m_scene;
	};

	//�V�[�����߂̃t���O���擾
	bool GetInit() {
		return m_init;
	};

	//���݂̃V�[����ύX
	void SetScene(SCENE scene){
		m_scene = scene;
	};

	//�V�[�����߂̃t���O��ύX(ON or OFF)
	void ChangeInit() {
		m_init = m_init ? false : true;
	};

	//���z�֐�
	virtual ~GameBase() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
	
};
