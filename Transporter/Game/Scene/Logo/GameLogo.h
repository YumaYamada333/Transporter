//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLogo.h
//!
//! @brief  ロゴシーンのヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"

class Logo :public GameBase
{
private:
	static const int CHANGE_SCENE_TIME = 120;	//次のシーンへ移行するまでの時間

private:
	int m_time;

public:
	Logo(RenderingResourceManager* rrm);
	~Logo();
	void Update();
	void Render();
};
