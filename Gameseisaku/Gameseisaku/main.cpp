#include "stdafx.h"
#include "Camera.h"
#include "game.h"


Game* game;
Camera camera;

//初期化処理。
void Init()
{
	game = new Game;
	game->Start();
	
}
//描画処理。
VOID Render()
{
	

  //画面をクリア
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
  //シーンの描画開始。
	g_pd3dDevice->BeginScene();

	game->Render();

  // シーンの描画終了。
	g_pd3dDevice->EndScene();
  // バックバッファとフロントバッファを入れ替える。
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
 
}
//更新処理。
void Update()
{
	game->Update();
}
//ゲームが終了したときに呼ばれる処理。
void Terminate()
{
	delete game;
	delete g_effectManager;
	g_pd3dDevice->Release();
	g_pD3D->Release();
}