//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameTitle.h
//!
//! @brief  タイトルシーンのヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"

class Title:public GameBase
{
private:

public:
	Title(RenderingResourceManager* rrm);
	~Title();
	void Update();
	void Render();

};



