#pragma once
#include "SkinModelData.h"

class SkinModelData;
class Light;
class Game;
//class Camera;
//Camera*				camera;
class SkinModel{
public:
	SkinModel();
	~SkinModel();
	void Init(SkinModelData* modelData);
	void Draw(D3DXMATRIX* viewMatrix, D3DXMATRIX* projMatrix);
	void UpdateWorldMatrix(const D3DXVECTOR3& trans, const D3DXQUATERNION& rot, const D3DXVECTOR3& scale);
	void SetLight(Light* light)
	{
		this->light = light;
	}
	//�擪�̃��b�V�����擾�B
	LPD3DXMESH GetOrgMeshFirst() const
	{
		return skinModelData->GetOrgMeshFirst();
	}

	D3DXMATRIX* FindBoneWorldMatrix(const char* boneName)
	{
		return skinModelData->FindBoneWorldMatrix(boneName);
	}

private:
	D3DXMATRIX			worldMatrix;	//!<���[���h�s��B
	D3DXMATRIX			rotationMatrix;	//!<��]�s��B
	SkinModelData*		skinModelData;	//!<�X�L�����f���f�[�^�B
	ID3DXEffect*		pEffect;		//!<�G�t�F�N�g�B
	Light*				light;			//!<���C�g�B
	
};