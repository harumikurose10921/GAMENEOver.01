#include "stdafx.h"
#include "Camera.h"
#include "Player.h"


Camera camera;
Player player;

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
	
}
//�X�V�����B
void Update()
{
	player.Update();
	camera.Update();
	
}
//�Q�[�����I�������Ƃ��ɌĂ΂�鏈���B
void Terminate()
{
	/*player.Rerase();*/
	g_pd3dDevice->Release();
	g_pD3D->Release();
}