#include "stdafx.h"
#include "Camera.h"

Camera* g_gameCamera;

Camera::Camera()
{
}


Camera::~Camera()
{
}
void Camera::Start()
{
	//斜め上から見下ろす感じのカメラにする
	m_camera.SetPosition({ 0.0f, 0.0f, 16.0f });
	m_camera.SetTarget({ 0.0f, 0.0f, 0.0f });
}
void Camera::Update()
{
	m_camera.Update();
}