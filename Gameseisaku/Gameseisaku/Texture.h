#pragma once
class Texture{
public:
	Texture();
	~Texture();
	void SetTextureDX(LPDIRECT3DTEXTURE9 tex)
	{
		m_tex = tex;
		ComputeTexSize();
	}
	LPDIRECT3DTEXTURE9 GetTextureDx()const
	{
		return m_tex;
	}
	void Release()
	{
		if (m_tex){
			m_tex->Release();
			m_tex = nullptr;
		}
	}
	//テクスチャの高さを取得。
	int GetHeight()const
	{
		return m_texH;
	}
	//テクスチャの幅を取得。
	int GetWidth()const
	{
		return m_texW;
	}

	bool Load(const char* filName);
private:
	//テクスチャのサイズの計算
	void ComputeTexSize()
	{
		D3DSURFACE_DESC desc;
		m_tex->GetLevelDesc(0, &desc);
		m_texW = desc.Width;
		m_texH = desc.Height;

	}
	LPDIRECT3DTEXTURE9 m_tex = nullptr;
 	int m_texW = 0;   //テクスチャの横幅。
	int m_texH = 0;   //テクスチャの縦幅。
};