#pragma once
#include <d3d9.h>
#include <d3dx9effect.h>
#include <d3dx9math.h>
#include <d3dx9mesh.h>
#include <d3dx9anim.h>
#pragma warning( disable : 4996 ) 
#include <strsafe.h>
#pragma warning( default : 4996 )
#include<cstdlib>
#include <memory>
#include <vector>
#include <map>
#include <list>
#include "System.h"

#include "Camera.h"
#include "GameCamera.h"
#include "SkinModel.h"
#include "SkinModelData.h"
#include "Animation.h"
#include "Light.h"
#include "btBulletDynamicsCommon.h"
#include "BulletCollision\CollisionDispatch\btGhostObject.h"
#include "RenderTarget.h"
#include"game.h"

extern RenderTarget* mainRenderTarget;	//!<18-2 メインレンダリングターゲット。
extern void DrawQuadPrimitive();