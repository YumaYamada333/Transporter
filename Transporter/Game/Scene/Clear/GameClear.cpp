//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameClear.cpp
//!
//! @brief  ゲームクリア処理のソースファイル
//!
//! @date   2016/11/04		
//!
//! @author 山田唯真	
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "..\..\Game.h"
#include "GameClear.h"
using namespace DirectX::SimpleMath;
using namespace DirectX;

//----------------------------------------------------------------------
//! @brief ゲームクリアコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Clear::Clear(RenderingResourceManager* rrm)
	:GameBase(GameBase::CLEAR, rrm)
{

}

//----------------------------------------------------------------------
//! @brief ゲームクリアデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Clear::~Clear()
{
}

//----------------------------------------------------------------------
//! @brief ゲームクリア処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Clear::Update()
{
	if (GetInit() == false)
	{
		ChangeInit();
		
		
	}


	//if (g_mouse.leftButton)
	//{ 
	//	//g_NextScene = TITLE;
	//	SetScene(GameBase::TITLE);
	//}
}

//----------------------------------------------------------------------
//! @brief ゲームクリア描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Clear::Render()
{
	/*wchar_t buf[256];

	swprintf_s(buf, 256, L"CLEAR");
	g_spriteFont->DrawString(g_spriteBatch.get(), buf, Vector2(100, 0));*/
}
