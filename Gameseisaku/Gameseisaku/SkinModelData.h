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
class Animation;
class SkinModelData
{
public:
	SkinModelData();
	~SkinModelData();
	void LoadModelData(const char* filePath,Animation* anim);
	void Release();
		LPD3DXFRAME GetFrameRoot()
	{
			return frameRoot;
	}
	ID3DXAnimationController* GetAnimationController()
	{
			return pAnimController;
	}


	D3DXMATRIX* GetRootBoneMatrix()
	{
		D3DXFRAME_DERIVED* frameDer = (D3DXFRAME_DERIVED*)frameRoot;
		return &frameDer->CombinedTransformationMatrix;
	}
	void UpdateBoneMatrix(const D3DXMATRIX& matWorld);
	//�擪�̃��b�V�����擾
	LPD3DXMESH GetOrgMeshFirst() const;
	//���̃��[���h�s�������
	//�p�ɂɌĂԂƏd���Ȃ�̂Œ���
	D3DXMATRIX* FindBoneWorldMatrix(const char* boneName);
private:
	D3DXMATRIX* FindBoneWorldMatrix(const char* boneName, LPD3DXFRAME frame);
	LPD3DXMESH GetOrgMesh(LPD3DXFRAME frame) const;
	LPD3DXFRAME					frameRoot;		//�t���[�����[�g�B
	ID3DXAnimationController*   pAnimController;
};