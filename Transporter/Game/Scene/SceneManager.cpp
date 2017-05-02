//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   SceneManager.cpp
//!
//! @brief  シーン管理クラスのソースファイル
//!
//! @date   2017/04/18		
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#include "SceneManager.h"

//メンバ関数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝

//----------------------------------------------------------------------
//! @brief コンストラクタ
//!
//! @param[in] 初期シーンの番号
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
//! @brief デストラクタ
//----------------------------------------------------------------------
SceneManager::~SceneManager()
{
	delete m_base;
}

//----------------------------------------------------------------------
//! @brief シーンマネージャの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void SceneManager::Update()
{
	//現在のシーンを更新(nullチェック)
	if (m_base != nullptr) {
		m_NextScene = m_base->GetScene();
	}

	//もし現在のシーンと前のシーンが違うなら
	if (m_NextScene != m_scene){
		//現在のシーンを破棄
		delete m_base;

		//シーンを変更
		m_scene = m_NextScene;	
		m_init	= 0;

		//シーンの呼び出し
		switch (m_scene){
		case GameBase::LOGO:		m_base = new Logo(m_rendering_resource_manager);	break;
		case GameBase::TITLE:		m_base = new Title(m_rendering_resource_manager);	break;
		case GameBase::PLAY:		m_base = new Play(m_rendering_resource_manager);	break;
		case GameBase::CLEAR:		m_base = new Clear(m_rendering_resource_manager);	break;
		case GameBase::OVER:		m_base = new Over(m_rendering_resource_manager);	break;
		}
	}

	//シーンの更新
	m_base->Update();
}

//----------------------------------------------------------------------
//! @brief シーンの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void SceneManager::Render()
{
	m_base->Render();
}