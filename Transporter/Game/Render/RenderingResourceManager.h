//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   RenderingManager.h
//!
//! @brief �`��Ɏg�p����e�v�f�̊Ǘ��N���X�̃\�[�X�t�@�C��
//!
//! @date   2017/04/24		
//!
//! @author �R�c�B�^
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
#pragma once

//�C���N���[�h===============================================================
#include <Windows.h>
#include <d3d11.h>
#include <d3d11_1.h>
#include <SimpleMath.h>
#include <Algorithm>
#include <wrl.h>
#include "..\..\StepTimer.h"

//�N���X������������������������������������������������������������������
class RenderingResourceManager
{
private:
	HWND                                            m_window;				//�E�B���h�E
	int                                             m_outputWidth;			//��ʕ�
	int                                             m_outputHeight;			//��ʍ���

	D3D_FEATURE_LEVEL                               m_featureLevel;			//�@�\���x��
	Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;			//�f�o�C�X
	Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
	Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;			//�R���e�L�X�g
	Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

	Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;			//�X���b�v�`�F�[��
	Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
	Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;		//�����_�[�^�[�Q�b�g�r���[
	Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;		//�[�x�X�e���V���r���[

public:
	RenderingResourceManager(HWND window, int width, int height);
	~RenderingResourceManager();
	void OnWindowSizeChanged(int width, int height);

	void Clear();
	void Present();

	ID3D11Device*				GetDevice();			
	ID3D11DeviceContext*		GetContext();

private:
	void CreateDevice();		//�f�o�C�X�̍쐬
	void CreateResources();	

	void OnDeviceLost();
};
