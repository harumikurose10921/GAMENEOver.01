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
private:
	D3DXVECTOR3 position;
	D3DXMATRIX*  mWorld;//���[���h�s��
	D3DXMATRIX  mRotation;
	SkinModel model;
	SkinModelData modeldata;
	Light light;
	//MeshCollider meshcollider;//���b�V���R���C�_�[
	bool					Ongoal;
	bool					goalflag;
	Player player;

};