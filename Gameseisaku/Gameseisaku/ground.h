#pragma once
#include"MeshCollider.h"

class ground
{
public:
	ground();
	~ground(); 
	void Init();
	void Updeate();
	void Render();
	//地面とのあたり判定。
	//pos  レイの始点。
	//ray	レイ方向。
	//bHit	レイと地面が衝突したら1が設定される。
	//len	レイの始点から交点までの距離。
	void IsIntersect(const D3DXVECTOR3& pos, const D3DXVECTOR3& ray, int& bHit, float& len);
	void Setposition(D3DXVECTOR3 pos){
		position = pos;
	}
private:
	D3DXVECTOR3 position;
	D3DXMATRIX*  mWorld;//ワールド行列
	D3DXMATRIX  mRotation;
	SkinModel model;		//スキンモデル
	SkinModelData modeldata;
	Light light;
	MeshCollider meshcollider;//メッシュコライダー
	

};