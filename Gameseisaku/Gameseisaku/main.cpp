#include "stdafx.h"
#include "Camera.h"
#include "Player.h"

const int				LIGHT_NUM = 4;
D3DXVECTOR4 			g_diffuseLightDirection[LIGHT_NUM];	//ライトの方向。
D3DXVECTOR4				g_diffuseLightColor[LIGHT_NUM];		//ライトの色。
D3DXVECTOR4				g_ambientLight;	//環境光

Camera camera;
Player player;
//ライトを更新
void UpdateLight()
{
	g_diffuseLightDirection[0] = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	g_diffuseLightDirection[1] = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	g_diffuseLightDirection[2] = D3DXVECTOR4(0.0f, -1.0f, 0.0f, 1.0f);
	g_diffuseLightDirection[3] = D3DXVECTOR4(-1.0f, 0.0f, 0.0f, 1.0f);

	//ディフューズライト。
	g_diffuseLightColor[0] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
	g_diffuseLightColor[1] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
	g_diffuseLightColor[2] = D3DXVECTOR4(0.5f, 0.4f, 0.6f, 1.0f);
	g_diffuseLightColor[3] = D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f);

	//環境光。
	g_ambientLight = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
}
//初期化処理。
void Init()
{
	player.Init(g_pd3dDevice);
	camera.Init();
}
//描画処理。
VOID Render()
{
  //画面をクリア
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
  //シーンの描画開始。
	g_pd3dDevice->BeginScene();
  // シーンの描画終了。
	g_pd3dDevice->EndScene();
  // バックバッファとフロントバッファを入れ替える。
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
  //Player描画
	player.Render(g_pd3dDevice,
		camera.GetviewMatrix(),
		camera.GetprojectionMatrix(),
		g_diffuseLightDirection,
		g_diffuseLightColor,
		g_ambientLight,
		LIGHT_NUM);
}
//更新処理。
void Update()
{
	player.Update();
	camera.Update();
	UpdateLight();
}
//ゲームが終了したときに呼ばれる処理。
void Terminate()
{
	/*player.Rerase();*/
	g_pd3dDevice->Release();
	g_pD3D->Release();
}