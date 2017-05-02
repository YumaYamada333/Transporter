//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   SceneManager.h
//!
//! @brief  シーン管理クラスのヘッダファイル
//!
//! @date   2017/04/18		
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

//ヘッダ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
#include "Base_virtual\GameBase.h"
#include "Clear\GameClear.h"
#include "Logo\GameLogo.h"
#include "Play\GamePlay.h"
#include "Over\GameOver.h"
#include "Title\GameTitle.h"

#include "..\Render\RenderingResourceManager.h"

//定数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
class GameBase;

//クラス＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝
class SceneManager
{
private:
	GameBase*					m_base;							//シーン
	RenderingResourceManager*	m_rendering_resource_manager;	//レンダリングマネージャのポインタ
	int							m_scene;						//シーン管理
	int							m_NextScene;					//次のシーン
	int							m_init;							//初期化管理

public:
	SceneManager(int scene, RenderingResourceManager* rrm);	//コンストラクタ
	~SceneManager();										//デストラクタ
	void Update();											//更新
	void Render();											//描画
};