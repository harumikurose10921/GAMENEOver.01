#pragma once
//パーティクルの発生機。
#ifndef  _PARTICLEEMITTER_H_
#define	 _PARICLEEMITTER_H_


class Particle;
//パーティクル生成パラメーター
struct SParicleEmitParameter {
	//初期化
	void Init()
	{
		memset(this, 0, sizeof(SParicleEmitParameter));
	}
	const char* texturePath; //テクスチャのファイルパス。
	float w;//パーティクルの幅。
	float h;//パーティクルの高さ。
	float intervalTime;//パーティクルの発生間隔。
	D3DXVECTOR3 initSpeed;//初速度
};

class ParticleEmiter 
{
public:
//コンストラクタ
	ParticleEmiter();
	//デストラクタ
	~ParticleEmiter();
	//初期化
	//param[in]	camera	パーティクルの描画で使用するかめら
	//param[in]	param
	void Init(const SParicleEmitParameter&param);//パラメータ。
	void Updeate();
	void Render(const D3DXMATRIX&viewMaatrix, const D3DXMATRIX&projMatrix);
private:
	SParicleEmitParameter param;          //パラメータ。
	std::list<Particle*> particleList;
	float timer;                          //タイマー
};
#endif // ! _PARTICLEEMITTER_H_
