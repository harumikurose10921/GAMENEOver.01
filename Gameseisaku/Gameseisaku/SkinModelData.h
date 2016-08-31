#pragma once

struct D3DXFRAME_DERIVED : public D3DXFRAME{
	D3DXMATRIXA16	CombinedTransformationMatrix;	//�����ςݍs��B
};
struct D3DXMESHCONTAINER_DERIVED : public D3DXMESHCONTAINER {
	LPDIRECT3DTEXTURE9* ppTextures;
	LPD3DXMESH pOrigMesh;
	LPD3DXATTRIBUTERANGE pAttributeTable;
	DWORD NumAttributeGroups;
	DWORD NumInfl;
	LPD3DXBUFFER pBoneCombinationBuf;
	D3DXMATRIX** ppBoneMatrixPtrs;
	D3DXMATRIX* pBoneOffsetMatrices;
	DWORD NumPaletteEntries;
	bool UseSoftwareVP;
	DWORD iAttributeSW;
};
class SkinModelData
{
public:
	SkinModelData();
	~SkinModelData();
	void LoadModelData(const char* filePath);
	void Release();
		LPD3DXFRAME GetFrameRoot()
	{
			return frameRoot;
	}
	ID3DXAnimationController* GetAnimationController()
	{
			return pAnimController;
	}
	void UpdateBoneMatrix(const D3DXMATRIX& matWorld);
private:
	LPD3DXFRAME					frameRoot;		//�t���[�����[�g�B
	ID3DXAnimationController*   pAnimController;
};