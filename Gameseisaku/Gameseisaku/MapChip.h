#pragma once
#include "MeshCollider.h"
#include "RigidBody.h"




struct SMapChipLocInfo{
	const char* modelName;		//モデル
	D3DXVECTOR3 pos;			//座標
	D3DXQUATERNION rotation;	//回転
};

class MapChip{
public:
	MapChip();
	~MapChip();
	void Init(const char* name ,D3DXVECTOR3 pos,D3DXQUATERNION rot);
	void Start();
	void Update();
	void Render();
	void SetPos(D3DXVECTOR3 pos);
private:
	SkinModelData					skinmodelData;
	SkinModel						skinModel;
	D3DXVECTOR3						Scale;
	D3DXVECTOR3						position;
	D3DXQUATERNION					rotation;
	Light							light;
	//D3DXMATRIX					worldMatrixBuffer;	//ワールド行列のバッファ
	MeshCollider					meshCollider;		//メッシュコライダー。
	RigidBody						rigidBody;			//剛体。
	D3DXMATRIX*                     rootBoneMatrix;
	
};