#include "stdafx.h"
#include "Camera.h"
#include "Player.h"


Camera camera;
Player player;
//初期化処理。
void Init()
{
	////カメラ初期化。
	//camera.Init();
	//camera.SetEyept(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	//camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	//camera.Update();

	player.Init();
	camera.Init();
}
//描画処理。
VOID Render()
{
	

  //画面をクリア
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
  //シーンの描画開始。
	g_pd3dDevice->BeginScene();

	//Player描画
	player.Render();

  // シーンの描画終了。
	g_pd3dDevice->EndScene();
  // バックバッファとフロントバッファを入れ替える。
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
 
}
//更新処理。
void Update()
{
	player.Update();
	camera.Update();
	
}
//ゲームが終了したときに呼ばれる処理。
void Terminate()
{
	
	g_pd3dDevice->Release();
	g_pD3D->Release();
}