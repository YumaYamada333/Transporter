//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GamePlay.cpp
//!
//! @brief  �Q�[���v���C�����̃\�[�X�t�@�C��
//!
//! @date   2016/11/04		
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "..\..\Game.h"
#include "GamePlay.h"

using namespace DirectX::SimpleMath;
using namespace DirectX;

//�O���[�o���ϐ��������������������������������������������������������������|
int g_count;

//�֐��̒�`�����������������������������������������������������������������|
//----------------------------------------------------------------------
//! @brief �v���C�R���X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Play::Play(RenderingResourceManager* rrm)
	:GameBase(GameBase::PLAY, rrm)
{
	/*m_debug_camera = DebugCamera::Create(SCREEN_WIDTH, SCREEN_HEIGHT);
	m_grid_floor = GridFloor::Create(20.0f, 20);
	cube = Cube::Create(0, 0.5f, 0, 1);*/
	m_view = Matrix::Identity;	// �r���[�s����쐬����
	m_proj = Matrix::Identity;	// �ˉe�s����쐬����
	m_world = Matrix::Identity;
}

//----------------------------------------------------------------------
//! @brief �v���C�f�X�g���N�^
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
Play::~Play()
{
	/*delete m_grid_floor;
	delete m_debug_camera;
	delete cube;*/
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::Update()
{
	//�f�o�b�O�J�����̍X�V
	/*m_debug_camera->Update();*/

	//�V�[���̍ŏ��Ɉ�񂾂��s������������
	if (GetInit() == false){
		ChangeInit();

		g_count = 0;
	}	



	//���͌n����/////////////////////////// //
	// if(g_keyTracker->pressed.Space)//�g���K�[����
	// if(g_key.Right)//��������
	// ttp://directxtk.codeplex.com/wikipage?title=Keyboard�@���Q�l
	

	//�N���A����

	//�I������
}

//----------------------------------------------------------------------
//! @brief �Q�[���v���C�`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void Play::Render()
{

	// �r���[�s����쐬����
	//m_view = m_debug_camera->GetCameraMatrix();

	// �ˉe�s����쐬����
	//m_proj = Matrix::CreatePerspectiveFieldOfView(XMConvertToRadians(45.0f), SCREEN_WIDTH / (float)SCREEN_HEIGHT, 1.0f, 100.0f);

	//���[���h�s��
	//m_world = Matrix::Identity;


	// �O���b�h���̕\��
	//m_grid_floor->Render(m_view, m_proj);

	//�u�����h�X�e�[�g�̐ݒ�
	//g_pImmediateContext->OMSetBlendState(g_pCommonStates->Opaque(), nullptr, 0XFFFFFFFF);
	
	//�[�x�E�X�e���V���̐ݒ�
	//g_pImmediateContext->OMSetDepthStencilState(g_pCommonStates->DepthDefault(), 0);

	//�J�����O�̐ݒ�(����͂��Ȃ�)
	//g_pImmediateContext->RSSetState(g_pCommonStates->CullNone());
	
	//���̕\��
	//cube->Render(m_view, m_proj, m_world);

	//DrawString(100, 100, L"Play");
	
}
