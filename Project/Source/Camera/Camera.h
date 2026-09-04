#pragma once
#include "DxLib.h"
#include "CameraBase.h"
#include "../Player/Player.h"

class Camera : public CameraBase
{
public:
    Camera();
    virtual ~Camera();

public:
    void Init() override;
    void Load() override;
    void Start() override;
    void Step() override;
    void Update() override;
    void Draw() override;
    void Fin() override;

    void SetTargetPlayer(Player* player) { m_Player = player; }

private:
    Player* m_Player;

    float m_Distance;
    float m_Height;
};
