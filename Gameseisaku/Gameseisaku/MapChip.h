#pragma once
struct SMapChipLocInfo{
	const char* modelName;		//ÉÇÉfÉã
	D3DXVECTOR3 pos;			//ç¿ïW
	D3DXQUATERNION rotation;	//âÒì]
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
	SkinModelData skinmodelData;
	SkinModel skinModel;
	D3DXVECTOR3 Scale;
	D3DXVECTOR3 position;
	Light light;

};