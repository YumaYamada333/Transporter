//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.h
//!
//! @brief  �I���V�[���̃w�b�_�t�@�C��
//!
//! @date   2016/12/12
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"

class Over :public GameBase
{
private:

public:
	Over(RenderingResourceManager* rrm);
	~Over();
	void Update();
	void Render();
};