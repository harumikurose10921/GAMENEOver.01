#pragma once
//パーティクル
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "Primitive.h"
struct SParticleEmitParameter;

//パーティクル。
class Particle {
public:

private:
	Primitive primitive;//プリミティブ。
	LPDIRECT3DTEXTURE9 texture;//テクスチャ。
	ID3DXEffect* shaderEffect;//シェーダーエフェクト。
	D3DXVECTOR3 moveSpeed;//速度。
	D3DXVECTOR3 position;//座標。
public:
	Particle();
	~Particle();
	void Init(const SParicleEmitParameter& param);
	void Updeate();
	void Render(const D3DXMATRIX& viewMatrix, const D3DXMATRIX& projMatrix);
};
#endif //_PARTICLE_H_
