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
	camera.Init();
	camera.SetEyept(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	camera.Update();
	player.Init();
	ground.Init();
	
	
}

void Game::Update()
{
	camera.Update();
	player.Update();
	ground.Updeate();

}
void Game::Render()
{
	player.Render();
	ground.Render();
}
