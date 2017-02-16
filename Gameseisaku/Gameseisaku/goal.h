#pragma once
#include"MeshCollider.h"

class Goal 
{
public:
	Goal();
	~Goal();
	void Init();
	void Updeate();
	void Render();
	void SetPosition(D3DXVECTOR3 pos) 
	{
		pos = position;
	}
	bool GetGoal()
	{
		return goalflag;
	}
	//void IsIntersect(const D3DXVECTOR3& pos, const D3DXVECTOR3& ray, int& bHit, float& len);
	void SetGoal();
	void SetPlayer(Player *p)
	{
		player = p;
	}

private:
	D3DXVECTOR3 position;
	D3DXMATRIX*  mWorld;//ÉèÅ[ÉãÉhçsóÒ
	D3DXMATRIX  mRotation;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
	bool					Ongoal = false;
	bool					goalflag = false;
	Player *player;

};