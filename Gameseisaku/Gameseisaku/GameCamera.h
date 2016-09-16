#pragma once
class Player;
class Camera;
class GameCamera{
public:
	GameCamera();
	~GameCamera();
	void Init();
	void Update();
	void Render();
	void SetPlayer(Player* player)
	{
		this->player = player;
	}
	const Camera& GetCamera()const
	{
		return camera;
	}
private:
	Camera camera;
	Player* player;
	D3DXVECTOR3 toPosition;//注視点からのベクトル
};