#pragma once
#include "Player.h"
#include "ground.h"
#include "Sky.h"
#include "Map.h"

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
private:
	Player player;
	Camera camera;
	ground ground;
	Sky    sky;
	Map    map;
};
extern Game* game;