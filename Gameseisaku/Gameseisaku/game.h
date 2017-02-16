#pragma once
#include "Player.h"
#include "ground.h"
#include "goal.h"
#include "Sky.h"
#include "Map.h"
#include "Physics.h"
#include "bloom.h"

class Game
{
public:
	Game();
	~Game();
	void Start();
	void Update();
	void Render();

	Camera GetCamera(){

		return camera;
	}
	
	//�������[���h�̎擾
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
private:
	Player player;//�v���C���[
	Camera camera;//�J����
	Goal goal;
	ground ground;
	Sky    sky;//�X�J�C�{�b�N�X
	Map    map;//�}�b�v
	PhysicsWorld  physicsWorld;//�t�B�W�b�N�X���[���h
	Bloom bloom;//�u���[��

};
extern Game* game;