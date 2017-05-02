//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameOver.h
//!
//! @brief  終了シーンのヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author 山田唯真
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