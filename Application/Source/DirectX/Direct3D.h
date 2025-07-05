#pragma once

#include "DirectX.h";

//==========================================================
// Direct3D�N���X
//==========================================================
class Direct3D
{
	// D3D.�֐����Ŏg��
public:

	// Direct3D�f�o�C�X
	ComPtr<ID3D11Device> m_device;

	// Direct3D�f�o�C�X�R���e�L�X�g
	ComPtr<ID3D11DeviceContext> m_deviceContext;

	// �X���b�v�`�F�C��
	ComPtr<IDXGISwapChain> m_swapChain;

	// �o�b�N�o�b�t�@�[��RT�r���[
	ComPtr<ID3D11RenderTargetView> m_backBufferView;

	//--------------------------------------------
	// Direct3D�����������A�g�p�ł���悤�ɂ���֐�
	// hWnd		: �E�B���h�E�n���h��
	// width	: ��ʂ̕�
	// height	: ��ʂ̍���
	//--------------------------------------------
	bool Initialize(HWND hWnd, int width, int height);

	// 2D�`��p�̃V�F�[�_�[
	ComPtr<ID3D11VertexShader> m_spriteVS = nullptr;	// ���_�V�F�[�_�[
	ComPtr<ID3D11PixelShader> m_spritePS = nullptr;		// �s�N�Z���V�F�[�_�[
	ComPtr<ID3D11InputLayout> m_spriteInputLayout = nullptr;	// ���̓��C�A�E�g

//=========================================
// ���񂱂̃N���X�́A�ǂ�����ł��A�N�Z�X�ł���悤��
// �V���O���g���p�^�[���ɂ��܂�(�C���X�^���X��1���������ł��Ȃ�+�ǂ�����ł��g�p�ł���)
// Direct3D::�֐����Ŏg��
// �������ȉ��A�V���O���g���p�^�[���̃R�[�h
//=========================================
private:
	// �B��̃C���X�^���X�p�̃|�C���^
	static inline Direct3D *s_instance;
	// �R���X�g���N�^��private
	Direct3D(){}

public:
	// �C���X�^���X�쐬
	static void CreateInstance() {
		DeleteInstance();
		s_instance = new Direct3D();
	}

	// �C���X�^���X�폜
	static void DeleteInstance() {
		if (s_instance != nullptr) {
			delete s_instance; // ���������
			s_instance = nullptr;
		}
	}

	// �C���X�^���X�擾(&�����ĎQ�Ƃ�Ԃ��Ă���B�܂�A���̂�Ԃ����ǁA�l�n������Ȃ��ĎQ�Ɠn���ł�����Ă���)
	static Direct3D& GetInstance() {
		return *s_instance;
	}

	// Direct3D�̗B��̃C���X�^���X���ȒP�Ɏ擾���邽�߂̃}�N��
#define D3D Direct3D::GetInstance()
};