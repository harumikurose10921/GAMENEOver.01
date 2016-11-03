#pragma once
#include "Player.h"
#include "ground.h"
#include "Sky.h"
#include "Map.h"
#include "Physics.h"


class Game
{
public:
	Game();
	~Game();
	void Start();
	void Update();
	void Render();
	Camera GetCamera()
	{
		return camera;
	};
	//物理ワールドの取得
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
private:
	Player player;
	Camera camera;
	ground ground;
	Sky    sky;
	Map    map;
	PhysicsWorld  physicsWorld;

};
extern Game* game;