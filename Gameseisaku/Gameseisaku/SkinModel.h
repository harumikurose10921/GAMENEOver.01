#pragma once

class SkinModelData;
class Light;

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
private:
	D3DXMATRIX			worldMatrix;	//!<���[���h�s��B
	D3DXMATRIX			rotationMatrix;	//!<��]�s��B
	SkinModelData*		skinModelData;	//!<�X�L�����f���f�[�^�B
	ID3DXEffect*		pEffect;		//!<�G�t�F�N�g�B
	Light*				light;			//!<���C�g�B
};