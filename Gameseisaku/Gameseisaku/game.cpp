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
	//ƒJƒƒ‰‰Šú‰»B
	camera.Init(&player);
	camera.SetEyept(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	camera.Update();
	player.Init();
	ground.Init();
	sky.Start();
	map.Start();
	
	
}

void Game::Update()
{
	camera.Update();
	player.Update();
	ground.Updeate();
	sky.Update();
	map.Update();

}
void Game::Render()
{
	player.Render();
	ground.Render();
	sky.Render();
	map.Render();
}
