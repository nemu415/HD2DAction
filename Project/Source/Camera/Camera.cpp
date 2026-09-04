#include "DxLib.h"
#include "Camera.h"
#include <math.h>

#define CAMERA_NEAR_CLIP 0.01f
#define CAMERA_FAR_CLIP 1000.0f

#define PLAYER_DISTANCE -7.0f
#define ROTATION_SPEED 0.025f

#define X_ROTATION_MAX (DX_PI_F * 0.49f)

Camera::Camera() : CameraBase()
{
}

Camera::~Camera()
{
	Fin();
}

void Camera::Init()
{
}

void Camera::Load()
{
}

void Camera::Start()
{
	// ニア、ファークリップの設定
	SetCameraNearFar(CAMERA_NEAR_CLIP, CAMERA_FAR_CLIP);

	m_Pos = VGet(0.0f, 2.0f, -10.0f);

	m_Target = VGet(0.0f, 0.0f, 0.0f);

	m_UpVec = VGet(0.0f, 1.0f, 0.0f);
}

void Camera::Step()
{
}

void Camera::Update()
{
	if (m_Player == nullptr)
		        return;
		
	VECTOR p = m_Player->GetPos();
		
	//プレイヤーの背後方向
	VECTOR back = VGet(sinf(m_Rot.y), 0.0f, cosf(m_Rot.y));
		
	//カメラ位置
	m_Pos = VAdd(p, VAdd(VScale(back, -10.0f), VGet(0, 4.0f, 0)));
		
	//プレイヤーの少し下を見る
	m_Target = VAdd(p, VGet(0, -1, 0));

	SetCameraPositionAndTargetAndUpVec(m_Pos, m_Target, m_UpVec);
}

void Camera::Draw()
{
}

void Camera::Fin()
{

}
