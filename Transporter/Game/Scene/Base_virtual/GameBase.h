//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameBase.h
//!
//! @brief  シーンの基本のヘッダファイル
//!
//! @date   2016/12/16
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once
#include "..\..\Render\RenderingResourceManager.h"

class GameBase
{
public:
	enum SCENE		//シーン管理用
	{
		NONE,
		LOGO,
		TITLE,
		PLAY,
		CLEAR,
		OVER
	};

private:
	SCENE						m_scene;					//現在のシーン
	bool						m_init;						//シーン初めのフラグ

protected:
	RenderingResourceManager*	m_render_resource_manager;	//レンダリングマネージャ―

public:
	//コンストラクタ(シーンを渡して初期化)
	GameBase(SCENE scene, RenderingResourceManager* rrm) : 
		m_scene(scene), m_init(false), m_render_resource_manager(rrm) {};	

	//現在のシーンを取得
	SCENE GetScene() {
		return m_scene;
	};

	//シーン初めのフラグを取得
	bool GetInit() {
		return m_init;
	};

	//現在のシーンを変更
	void SetScene(SCENE scene){
		m_scene = scene;
	};

	//シーン初めのフラグを変更(ON or OFF)
	void ChangeInit() {
		m_init = m_init ? false : true;
	};

	//仮想関数
	virtual ~GameBase() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
	
};
