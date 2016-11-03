#pragma once
#include "MeshCollider.h"
#include "RigidBody.h"




struct SMapChipLocInfo{
	const char* modelName;		//���f��
	D3DXVECTOR3 pos;			//���W
	D3DXQUATERNION rotation;	//��]
};

class MapChip{
public:
	MapChip();
	~MapChip();
	void Init(const char* name);
	void Start();
	void Update();
	void Render();
	void SetPos(D3DXVECTOR3 pos);
private:
	SkinModelData					skinmodelData;
	SkinModel						skinModel;
	D3DXVECTOR3						Scale;
	D3DXVECTOR3						position;
	Light							light;
	//D3DXMATRIX					worldMatrixBuffer;	//���[���h�s��̃o�b�t�@
	MeshCollider					meshCollider;		//���b�V���R���C�_�[�B
	RigidBody						rigidBody;			//���́B
	D3DXMATRIX*                     rootBoneMatrix;
	
};