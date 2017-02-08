#pragma once
/*!
*@brief レンタリングターゲット。
*/
class RenderTarget {
public:
	/*!
	*@brief コンストラクタ。
	*/
	RenderTarget()
	{
		m_depthSurface = NULL;
		m_textrue = NULL;
		m_surface = NULL;
		m_textrue = NULL;
	}
	/*!
	*@brief デストラクタ。
	*/
	~RenderTarget() 
	{
		Release();
	}
	/*!
	*@drief 解放。
	*/
	void Release() 
	{
		if (m_textrue != nullptr) {
			m_textrue->Release();
			m_textrue = NULL;
		}
		if (m_depthSurface != nullptr) {
			m_depthSurface->Release();
			m_depthSurface = NULL;
		}
		if (m_surface != nullptr) {
			m_surface->Release();
			m_surface = NULL;
		}
	}
	/*!
	*@brief レンタリングターゲットの作成。
	*@param[in] w					レンタリングターゲットの幅。
	*@param[in] h					レンタリングターゲットの高さ。
	*@param[in] mipLevel			ミップマップのレベル。
	*@param[in] clorFormat			カラーバッファのフォーマット。
	*@param[in] depthStencilFormat	デプスステンシルバッファのフォーマット。
	*@param[in] multiSampleType		マルチサンプリングの種類。
	*@param[in]multiSampleQuality	マルチサンプリングの品質。
	*/
	void Create(
		int w,
		int h,
		int mipLevel,
		D3DFORMAT colorFormat,
		D3DFORMAT depthStencilFormat,
		D3DMULTISAMPLE_TYPE multiSampleType,
		int muitiSampleQuality)
	{
		//デプスステンシルバッファの作成。
		HRESULT hr = g_pd3dDevice->CreateDepthStencilSurface(
			w,
			h,
			static_cast<D3DFORMAT>(depthStencilFormat),
			static_cast<D3DMULTISAMPLE_TYPE>(multiSampleType),
			muitiSampleQuality,
			TRUE,
			&m_depthSurface,
			NULL
		);
		//カラーバッファを作成。
		hr = g_pd3dDevice->CreateTexture(
			w,
			h,
			mipLevel,
			D3DUSAGE_RENDERTARGET,
			static_cast<D3DFORMAT>(colorFormat),
			D3DPOOL_DEFAULT,
			&m_textrue,
			NULL
		);
		m_textrue->GetSurfaceLevel(0, &m_surface);
		m_width = w;
		m_height = h;
	}
	/*!
	*@brief レンダリングターゲットを取得。
	*/
	LPDIRECT3DSURFACE9 GetRenderTarget()
	{
		return m_surface;
	}
	/*!
	*@brief デプスステンシルバッファを取得。
	*/
	LPDIRECT3DSURFACE9 GetDepthStencilBuffer()
	{
		return m_depthSurface;
	}
	/*!
	*@brief　テクスチャを取得。
	*/
	LPDIRECT3DTEXTURE9 GetTexture()
	{
		return m_textrue;
	}
	/*!
	*@brief	幅を取得。
	*/
	int GetWidth() const
	{
		return m_width;
	}
	/*!
	*@brief	高さを取得。
	*/
	int GetHeight() const
	{
		return m_height;
	}
private:
	LPDIRECT3DSURFACE9 m_depthSurface;	//震度バッファ用のサーフェイス
	LPDIRECT3DTEXTURE9 m_textrue;		//書き込み先のテクスチャ。
	LPDIRECT3DSURFACE9 m_surface;		//サーフェイス
	int				   m_width = 0;		//幅
	int				   m_height = 0;	//高さ
};