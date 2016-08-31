#include "stdafx.h"
#include"EffectManager.h"

namespace{
	/*!
	* @brief	�����񂩂�32bit�̃n�b�V���l���쐬�B
	*/
	int MakeHash(const char* string)
	{
		int hash = 0;
		int l = (int)strlen(string);
		for (int i = 0; i < l; i++){
			hash = hash * 37 + string[i];
		}
		return hash;
	}
}

EffectManager::EffectManager()
{
}

EffectManager::~EffectManager()
{
	Release();
}
LPD3DXEFFECT EffectManager::LoadEffect(const char* filePath)
{

	LPD3DXEFFECT effect = nullptr;
	int hash = MakeHash(filePath);

	auto it = effectDictinary.find(hash);
	if (it == effectDictinary.end()) {
		//�V�K�B
		LPD3DXBUFFER  compileErrorBuffer = nullptr;
		HRESULT hr = D3DXCreateEffectFromFile(
			g_pd3dDevice,
			filePath,
			NULL,
			NULL,
#ifdef _DEBUG
			D3DXSHADER_DEBUG,
#else
			D3DXSHADER_SKIPVALIDATION,
#endif
			NULL,
			&effect,
			&compileErrorBuffer
			);
		if (FAILED(hr)) {
			MessageBox(nullptr, reinterpret_cast<char*>(compileErrorBuffer->GetBufferPointer()), "error", MB_OK);
			//�ǂݍ��ݎ��s�B
			std::abort();
		}

		std::pair<int, LPD3DXEFFECT> node(hash, effect);
		effectDictinary.insert(node);
	}
	else {
		//�o�^�ς݁B
		effect = it->second;
	}
	return effect;
}
void EffectManager::Release()
{
	for (auto p : effectDictinary) {
		p.second->Release();;
	}
	effectDictinary.clear();
}