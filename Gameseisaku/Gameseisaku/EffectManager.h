#pragma once

class Effect;

class EffectManager
{
public:
	EffectManager();
	~EffectManager();
	ID3DXEffect* LoadEffect(const char* filePath);
	void Release();
private:
	std::map<int, ID3DXEffect*>		effectDictinary;

};