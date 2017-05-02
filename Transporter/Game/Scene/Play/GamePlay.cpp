//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  ゲームプレイ処理のソースファイル
//!
//! @date   2016/11/04		
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "..\..\Game.h"
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//グローバル変数＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝－
int g_count;

//関数の定義＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝－
//----------------------------------------------------------------------
//! @brief プレイコンストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Play::Play(RenderingResourceManager* rrm)
	:GameBase(GameBase::PLAY, rrm)
{
	/*m_debug_camera = DebugCamera::Create(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_grid_floor = GridFloor::Create(20.0f, 20);
	cube = Cube::Create(0, 0.5f, 0, 1);*/
	m_view = Matrix::Identity;	// ビュー行列を作成する
	m_proj = Matrix::Identity;	// 射影行列を作成する
	m_world = Matrix::Identity;
}

//----------------------------------------------------------------------
//! @brief プレイデストラクタ
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
Play::~Play()
{
	/*delete m_grid_floor;
	delete m_debug_camera;
	delete cube;*/
}

//----------------------------------------------------------------------
//! @brief ゲームプレイ処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Play::Update()
{
	//デバッグカメラの更新
	/*m_debug_camera->Update();*/

	//シーンの最初に一回だけ行う初期化処理
	if (GetInit() == false){
		ChangeInit();

		g_count = 0;
	}	



	//入力系処理/////////////////////////// //
	// if(g_keyTracker->pressed.Space)//トリガー処理
	// if(g_key.Right)//おしっぱ
	// ttp://directxtk.codeplex.com/wikipage?title=Keyboard　を参考
	

	//クリア判定

	//終了判定
}

//----------------------------------------------------------------------
//! @brief ゲームプレイ描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void Play::Render()
{

	// ビュー行列を作成する
	//m_view = m_debug_camera->GetCameraMatrix();

	// 射影行列を作成する
	//m_proj = Matrix::CreatePerspectiveFieldOfView(XMConvertToRadians(45.0f), SCREEN_WIDTH / (float)SCREEN_HEIGHT, 1.0f, 100.0f);

	//ワールド行列
	//m_world = Matrix::Identity;


	// グリッド床の表示
	//m_grid_floor->Render(m_view, m_proj);

	//ブレンドステートの設定
	//g_pImmediateContext->OMSetBlendState(g_pCommonStates->Opaque(), nullptr, 0XFFFFFFFF);
	
	//深度・ステンシルの設定
	//g_pImmediateContext->OMSetDepthStencilState(g_pCommonStates->DepthDefault(), 0);

	//カリングの設定(今回はしない)
	//g_pImmediateContext->RSSetState(g_pCommonStates->CullNone());
	
	//箱の表示
	//cube->Render(m_view, m_proj, m_world);

	//DrawString(100, 100, L"Play");
	
}
