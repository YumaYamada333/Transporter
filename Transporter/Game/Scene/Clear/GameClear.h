//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.h
//!
//! @brief  クリアシーンのヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"

class Clear : public GameBase 
{
private:

public:
	Clear(RenderingResourceManager* rrm);
	~Clear();
	void Update();
	void Render();
};
