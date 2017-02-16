//パーティクル生成機

#include "stdafx.h"
#include "ParticleEmitter.h"
#include "Particle.h"

extern LPDIRECT3DDEVICE9 g_pd3dDevice;

using namespace std;
ParticleEmiter::ParticleEmiter()
{

}
ParticleEmiter::~ParticleEmiter()
{

}
void ParticleEmiter::Init(const SParicleEmitParameter&param)
{
	this->param = param;
	timer = 0.0f;
}