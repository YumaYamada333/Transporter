//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.h
//!
//! @brief  プレイシーンのヘッダファイル
//!
//! @date   2016/12/12
//!
//! @author 山田唯真
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

#pragma once
#include "..\Base_virtual\GameBase.h"
#include <d3d11.h>
#include <SimpleMath.h>

//class Cube;
//class GridFloor;
//class DebugCamera;

//クラス
class Play:public GameBase
{
private:
	DirectX::SimpleMath::Matrix m_view;	// ビュー行列
	DirectX::SimpleMath::Matrix m_proj;	// 射影行列		
	DirectX::SimpleMath::Matrix m_world;	//ワールド行列
	//GridFloor* m_grid_floor;		//グリッド床
	//DebugCamera* m_debug_camera;	//デバッグカメラ
	//Cube* cube;

public:
	Play(RenderingResourceManager* rrm);
	~Play();
	void Update();
	void Render();
};
