#include "stdafx.h"
#include "Camera.h"
#include "Player.h"

const int				LIGHT_NUM = 4;
D3DXVECTOR4 			g_diffuseLightDirection[LIGHT_NUM];	//���C�g�̕����B
D3DXVECTOR4				g_diffuseLightColor[LIGHT_NUM];		//���C�g�̐F�B
D3DXVECTOR4				g_ambientLight;	//����

Camera camera;
Player player;
//���C�g���X�V
void UpdateLight()
{
	g_diffuseLightDirection[0] = D3DXVECTOR4(1.0f, 0.0f, 0.0f, 1.0f);
	g_diffuseLightDirection[1] = D3DXVECTOR4(0.0f, 0.0f, 1.0f, 1.0f);
	g_diffuseLightDirection[2] = D3DXVECTOR4(0.0f, -1.0f, 0.0f, 1.0f);
	g_diffuseLightDirection[3] = D3DXVECTOR4(-1.0f, 0.0f, 0.0f, 1.0f);

	//�f�B�t���[�Y���C�g�B
	g_diffuseLightColor[0] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
	g_diffuseLightColor[1] = D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f);
	g_diffuseLightColor[2] = D3DXVECTOR4(0.5f, 0.4f, 0.6f, 1.0f);
	g_diffuseLightColor[3] = D3DXVECTOR4(0.2f, 0.2f, 0.2f, 1.0f);

	//�����B
	g_ambientLight = D3DXVECTOR4(1.0f, 1.0f, 1.0f, 1.0f);
}
//�����������B
void Init()
{
	player.Init(g_pd3dDevice);
	camera.Init();
}
//�`�揈���B
VOID Render()
{
  //��ʂ��N���A
	g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
  //�V�[���̕`��J�n�B
	g_pd3dDevice->BeginScene();
  // �V�[���̕`��I���B
	g_pd3dDevice->EndScene();
  // �o�b�N�o�b�t�@�ƃt�����g�o�b�t�@�����ւ���B
	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
  //Player�`��
	player.Render(g_pd3dDevice,
		camera.GetviewMatrix(),
		camera.GetprojectionMatrix(),
		g_diffuseLightDirection,
		g_diffuseLightColor,
		g_ambientLight,
		LIGHT_NUM);
}
//�X�V�����B
void Update()
{
	player.Update();
	camera.Update();
	UpdateLight();
}
//�Q�[�����I�������Ƃ��ɌĂ΂�鏈���B
void Terminate()
{
	/*player.Rerase();*/
	g_pd3dDevice->Release();
	g_pD3D->Release();
}