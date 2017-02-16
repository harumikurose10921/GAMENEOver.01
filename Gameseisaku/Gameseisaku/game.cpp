#include "stdafx.h"
#include "game.h"



Game::Game()
{

}

Game::~Game()
{

}

void Game::Start()
{
	//カメラ初期化。
	//physicsWorld = new PhysicsWorld();
	physicsWorld.Start();
	camera.Init(&player);
	camera.SetPosition(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	camera.Update();//カメラ
	player.Init();//プレイヤー
	ground.Init();//地面(仮)
	goal.Init();//ゴール
	sky.Start();//スカイボックス
	map.Start();//マップ
	goal.SetPlayer(&player);
}

void Game::Update()
{
	camera.Update();//カメラのアップデート
	player.Update();//プレイヤーのアップデート
	ground.Updeate();//地面(仮)
	goal.Updeate();//ゴール
	sky.Update();//スカイボックス
	map.Update();//マップ
}
void Game::Render()
{
	player.Render();//プレイヤー
	ground.Render();//地面(仮)
	goal.Render();//ゴール
	sky.Render();//スカイボックス
	map.Render();//マップ
	bloom.Render();//ブルーム
}
