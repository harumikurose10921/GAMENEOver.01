#include "stdafx.h"
#include "Model.h"

 Model::Model()
{
	 mesh = NULL;
	 textures = NULL;
	 numMaterial = NULL;
	 effect = NULL;
}

 Model::~Model()
 {
	 Release();
 }

 void Model::Init(LPDIRECT3DDEVICE9 pd3dDevice, const char* fileName)
 {
	 Release();
	 //X�t�@�C�������[�h
	 LPD3DXBUFFER pD3DXMtrlBuffer;
	 D3DXLoadMeshFromX(fileName, D3DXMESH_SYSTEMMEM, pd3dDevice, NULL,
		 &pD3DXMtrlBuffer, NULL, &numMaterial, &mesh);
	 //�@�������݂��邩���ׂ�B
	 if ((mesh->GetFVF()&D3DFVF_NORMAL) == 0){
		 //�@�����Ȃ��̂ō쐬����B
		 ID3DXMesh* pTempMesh = NULL;

		 mesh->CloneMeshFVF(mesh->GetOptions(),
			 mesh->GetFVF() | D3DFVF_NORMAL, g_pd3dDevice, &pTempMesh);

		 D3DXComputeNormals(pTempMesh, NULL);
		 mesh->Release();
		 mesh = pTempMesh;
	 }
	 
	 //�}�e���A���o�b�t�@���擾�B
	 D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();

	 //�e�N�X�`�������[�h
	 textures = new LPDIRECT3DTEXTURE9[numMaterial];
	 for (DWORD i = 0; i < numMaterial; i++)
	 {
		 textures[i] = NULL;
		 //�e�N�X�`�����쐬����B
		 D3DXCreateTextureFromFileA(pd3dDevice,
			 d3dxMaterials[i].pTextureFilename,
			 &textures[i]);
	 }
	 //�}�e���A���o�b�t�@�����
	 pD3DXMtrlBuffer->Release();

	 //�V�F�[�_�[���R���p�C��
	 LPD3DXBUFFER compileErrorBuffer = NULL;
	 //�V�F�[�_�[���R���p�C��
	 HRESULT hr = D3DXCreateEffectFromFile(
		 pd3dDevice,
		 "basic.fx",
		 NULL,
		 NULL,
		 D3DXSHADER_SKIPVALIDATION,
		 NULL,
		 &effect,
		 &compileErrorBuffer);
	 if (hr != S_OK){
		 MessageBox(NULL, (char*)(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
		 std::abort();
	 }
 }
 //�`��
 void Model::Render(
	 LPDIRECT3DDEVICE9 pd3dDevice,
	 D3DXMATRIX worldMatrix,
	 D3DXMATRIX rotationMatrix,
	 D3DXMATRIX viewMatrix,
	 D3DXMATRIX projMatrix,
	 D3DXVECTOR4* diffuseLightDirection,
	 D3DXVECTOR4* diffuseLightColor,
	 D3DXVECTOR4	 ambientLight,
	 int numDiffuseLight
	 )
 {
	 effect->SetTechnique("SkinModel");
	 effect->Begin(NULL, D3DXFX_DONOTSAVESHADERSTATE);
	 effect->BeginPass(0);

	 //�萔���W�X�^�ɐݒ肷��J���[
	 D3DXVECTOR4 color( 1.0f,0.0f, 0.0f,1.0f);
	 //���[���h�s��̓]��
	 effect->SetMatrix("g_woldMatrix", &worldMatrix);
	 //�r���[�s��̓]��
	 effect->SetMatrix("g_viewMatrix", &viewMatrix);

	 effect->SetMatrix("g_projctionMatrix", &projMatrix);

	 effect->SetMatrix("g_rotationMatrix", &rotationMatrix);

	 effect->SetVectorArray("g_diffuseLightDirection", diffuseLightDirection, numDiffuseLight);

	 effect->CommitChanges();

	 for (DWORD i = 0; i < numMaterial; i++)
	 {
		 effect->SetTexture("g_diffuseTexture", textures[i]);
		 mesh->DrawSubset(i);
	 }
	 effect->EndPass();
	 effect->End();
 }
 //�J��
 void Model::Release()
 {
	 //���b�V�����J��
	 if (mesh != NULL){
		 mesh->Release();
		 mesh = NULL;
	 }
	 //�e�N�X�`�����J��
	 if (effect != NULL){
		 effect->Release();
		 effect = NULL;
	 }
 }