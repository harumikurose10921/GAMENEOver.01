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
	
	//物理ワールドの取得
	PhysicsWorld* GetPhysicsWorld()
	{
		return &physicsWorld;
	}
private:
	Player player;//プレイヤー
	Camera camera;//カメラ
	Goal goal;
	ground ground;
	Sky    sky;//スカイボックス
	Map    map;//マップ
	PhysicsWorld  physicsWorld;//フィジックスワールド
	Bloom bloom;//ブルーム

};
extern Game* game;