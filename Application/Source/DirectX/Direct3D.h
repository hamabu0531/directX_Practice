#pragma once

#include "DirectX.h";

//==========================================================
// Direct3Dクラス
//==========================================================
class Direct3D
{
	// D3D.関数名で使う
public:

	// Direct3Dデバイス
	ComPtr<ID3D11Device> m_device;

	// Direct3Dデバイスコンテキスト
	ComPtr<ID3D11DeviceContext> m_deviceContext;

	// スワップチェイン
	ComPtr<IDXGISwapChain> m_swapChain;

	// バックバッファーのRTビュー
	ComPtr<ID3D11RenderTargetView> m_backBufferView;

	//--------------------------------------------
	// Direct3Dを初期化し、使用できるようにする関数
	// hWnd		: ウィンドウハンドル
	// width	: 画面の幅
	// height	: 画面の高さ
	//--------------------------------------------
	bool Initialize(HWND hWnd, int width, int height);

	// 2D描画用のシェーダー
	ComPtr<ID3D11VertexShader> m_spriteVS = nullptr;	// 頂点シェーダー
	ComPtr<ID3D11PixelShader> m_spritePS = nullptr;		// ピクセルシェーダー
	ComPtr<ID3D11InputLayout> m_spriteInputLayout = nullptr;	// 入力レイアウト

//=========================================
// 今回このクラスは、どこからでもアクセスできるように
// シングルトンパターンにします(インスタンスを1つしか生成できない+どこからでも使用できる)
// Direct3D::関数名で使う
// ↓↓↓以下、シングルトンパターンのコード
//=========================================
private:
	// 唯一のインスタンス用のポインタ
	static inline Direct3D *s_instance;
	// コンストラクタはprivate
	Direct3D(){}

public:
	// インスタンス作成
	static void CreateInstance() {
		DeleteInstance();
		s_instance = new Direct3D();
	}

	// インスタンス削除
	static void DeleteInstance() {
		if (s_instance != nullptr) {
			delete s_instance; // メモリ解放
			s_instance = nullptr;
		}
	}

	// インスタンス取得(&をつけて参照を返している。つまり、実体を返すけど、値渡しじゃなくて参照渡しできるってこと)
	static Direct3D& GetInstance() {
		return *s_instance;
	}

	// Direct3Dの唯一のインスタンスを簡単に取得するためのマクロ
#define D3D Direct3D::GetInstance()
};