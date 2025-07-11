#pragma once

// DirectXのライブラリを使用できるようにする
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

// Direct3Dの型、クラス・関数を呼べるようにする
#include <d3d11.h>
#include <d3dcompiler.h>

// DirectXMath(数学ライブラリ)を使えるようにする
#include <DirectXMath.h>

// DirectXテクスチャライブラリを使用できるようにする
#include <DirectXTex.h>

// ComPtrを使用できるようにする
#include <wrl/client.h>
using Microsoft::WRL::ComPtr;

// 自作のDirectX関係のヘッダーをインクルード
#include "Direct3D.h"
#include "Texture.h"