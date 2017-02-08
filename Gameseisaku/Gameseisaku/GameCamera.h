#pragma once
class Player;
class Camera;
class GameCamera{
public:
	GameCamera();
	~GameCamera();
	void Init(Player* player);
	void Update();
	void Render();

	void SetPosition(D3DXVECTOR3 pos)
	{
		position = pos;
	}
	D3DXVECTOR3 GetPosition()
	{
		return  position;
	}
	void SetLookatPt(D3DXVECTOR3 pt);
	D3DXVECTOR3 GetLookatPt();
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
	D3DXVECTOR3             position;
	D3DXVECTOR3				vLookatPt;
	D3DXVECTOR3				toPosition;//注視点からのベクトル
	D3DXVECTOR3             toPos;
	bool					Ongoal;
	bool					goalflag;
};