#pragma once

class Camera
{
public:
	Camera();
	~Camera();
	//上方向の設定
	void SetUpvec(D3DXVECTOR3 up);
	//上方向の取得
	D3DXVECTOR3 GetUpVec();
	//ビュー行列
	void SetviewMatrix(D3DXMATRIX mview);
	//ビュー行列の取得
	D3DXMATRIX GetviewMatrix();
	//プロジェクション行列の設定
	void SetprojectionMatrix(D3DXMATRIX proj);
	//プロジェクション行列の取得
	D3DXMATRIX GetprojectionMatrix();
	//アスペクト比を設定
	void SetAspect(float _aspect);
	//アスペクト比を取得
	float GetAspect();
	//ファーえお設定
	void SetFar(float _far);
	//ファーを取得
	float GetFar();
	//ニアを設定
	void SetNear(float _Near);
	//ニアを取得
	float GetNear();
	//視点を設定
	void SetEyept(D3DXVECTOR3 pt);
	//視点を取得
	D3DXVECTOR3 GetEyept();
	//注視点を設定
	void SetLookatPt(D3DXVECTOR3 pt);
	//注視点えお取得
	D3DXVECTOR3 GetLookatPt();

	void Init();
	void Update();
private:
	D3DXMATRIX				viewMatrix;			//!<ビュー行列。
	D3DXMATRIX				projectionMatrix;	//!<プロジェクション行列。
	D3DXVECTOR3				vEyePt;				//!カメラの視点。
	D3DXVECTOR3				vLookatPt;			//!カメラの注視点。どこを見ているかという情報。
	D3DXVECTOR3				vUpVec;				//!カメラの上方向。
	float					Far;				//!<遠平面。
	float					Near;				//!<近平面。
	float					aspect;				//!<アスペクト比
};