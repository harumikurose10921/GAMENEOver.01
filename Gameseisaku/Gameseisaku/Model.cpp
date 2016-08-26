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
	 //Xファイルをロード
	 LPD3DXBUFFER pD3DXMtrlBuffer;
	 D3DXLoadMeshFromX(fileName, D3DXMESH_SYSTEMMEM, pd3dDevice, NULL,
		 &pD3DXMtrlBuffer, NULL, &numMaterial, &mesh);
	 //法線が存在するか調べる。
	 if ((mesh->GetFVF()&D3DFVF_NORMAL) == 0){
		 //法線がないので作成する。
		 ID3DXMesh* pTempMesh = NULL;

		 mesh->CloneMeshFVF(mesh->GetOptions(),
			 mesh->GetFVF() | D3DFVF_NORMAL, g_pd3dDevice, &pTempMesh);

		 D3DXComputeNormals(pTempMesh, NULL);
		 mesh->Release();
		 mesh = pTempMesh;
	 }
	 
	 //マテリアルバッファを取得。
	 D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();

	 //テクスチャをロード
	 textures = new LPDIRECT3DTEXTURE9[numMaterial];
	 for (DWORD i = 0; i < numMaterial; i++)
	 {
		 textures[i] = NULL;
		 //テクスチャを作成する。
		 D3DXCreateTextureFromFileA(pd3dDevice,
			 d3dxMaterials[i].pTextureFilename,
			 &textures[i]);
	 }
	 //マテリアルバッファを解放
	 pD3DXMtrlBuffer->Release();

	 //シェーダーをコンパイル
	 LPD3DXBUFFER compileErrorBuffer = NULL;
	 //シェーダーをコンパイル
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
 //描画
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

	 //定数レジスタに設定するカラー
	 D3DXVECTOR4 color( 1.0f,0.0f, 0.0f,1.0f);
	 //ワールド行列の転送
	 effect->SetMatrix("g_woldMatrix", &worldMatrix);
	 //ビュー行列の転送
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
 //開放
 void Model::Release()
 {
	 //メッシュを開放
	 if (mesh != NULL){
		 mesh->Release();
		 mesh = NULL;
	 }
	 //テクスチャを開放
	 if (effect != NULL){
		 effect->Release();
		 effect = NULL;
	 }
 }