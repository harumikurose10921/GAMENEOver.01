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
	
	//•¨—ƒ[ƒ‹ƒh‚Ìæ“¾
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
private:
	Player player;
	Camera camera;
	Goal goal;
	//GameCamera Gcamera;
	ground ground;
	Sky    sky;
	Map    map;
	PhysicsWorld  physicsWorld;
	Bloom bloom;

};
extern Game* game;