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
	//�J�����������B
	//physicsWorld = new PhysicsWorld();
	physicsWorld.Start();
	camera.Init(&player);
	camera.SetPosition(D3DXVECTOR3(0.0f, 1.0f, 2.0f));
	camera.SetLookatPt(D3DXVECTOR3(0.0f, 0.5f, 0.0f));
	camera.Update();//�J����
	player.Init();//�v���C���[
	ground.Init();//�n��(��)
	goal.Init();//�S�[��
	sky.Start();//�X�J�C�{�b�N�X
	map.Start();//�}�b�v
	goal.SetPlayer(&player);
}

void Game::Update()
{
	camera.Update();//�J�����̃A�b�v�f�[�g
	player.Update();//�v���C���[�̃A�b�v�f�[�g
	ground.Updeate();//�n��(��)
	goal.Updeate();//�S�[��
	sky.Update();//�X�J�C�{�b�N�X
	map.Update();//�}�b�v
}
void Game::Render()
{
	player.Render();//�v���C���[
	ground.Render();//�n��(��)
	goal.Render();//�S�[��
	sky.Render();//�X�J�C�{�b�N�X
	map.Render();//�}�b�v
	bloom.Render();//�u���[��
}
