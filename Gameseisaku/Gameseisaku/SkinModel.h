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
	D3DXMATRIX			worldMatrix;	//!<ワールド行列。
	D3DXMATRIX			rotationMatrix;	//!<回転行列。
	SkinModelData*		skinModelData;	//!<スキンモデルデータ。
	ID3DXEffect*		pEffect;		//!<エフェクト。
	Light*				light;			//!<ライト。
};