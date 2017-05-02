//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.h
//!
//! @brief  ���S�V�[���̃w�b�_�t�@�C��
//!
//! @date   2016/12/12
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"

class Logo :public GameBase
{
private:
	static const int CHANGE_SCENE_TIME = 120;	//���̃V�[���ֈڍs����܂ł̎���

private:
	int m_time;

public:
	Logo(RenderingResourceManager* rrm);
	~Logo();
	void Update();
	void Render();
};
