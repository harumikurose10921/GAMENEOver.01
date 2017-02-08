#include "stdafx.h"
#include "Texture.h"

Texture::Texture()
{

}
Texture::~Texture()
{

}

bool Texture::Load(const char* fileName)
{
	LPDIRECT3DDEVICE9 device = g_pd3dDevice;
	if (FAILED(D3DXCreateTextureFromFile(
		device,
		fileName,
		&m_tex))){
		return false;
	}
	ComputeTexSize();
	return true;
}