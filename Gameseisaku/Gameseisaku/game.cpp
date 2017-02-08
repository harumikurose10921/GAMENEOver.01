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
	//physicsWorld = new PhysicsWorld();
	physicsWorld.Start();
	camera.Init(&player);
	camera.SetPosition(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	camera.Update();
	player.Init();
	ground.Init();
	goal.Init();
	sky.Start();
	map.Start();
}

void Game::Update()
{
	camera.Update();
	player.Update();
	ground.Updeate();
	goal.Updeate();
	sky.Update();
	map.Update();
}
void Game::Render()
{
	player.Render();
	ground.Render();
	goal.Render();
	sky.Render();
	map.Render();
	bloom.Render();
}
