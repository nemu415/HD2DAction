#pragma once
#include "SceneBase.h"

class StayScene : public SceneBase
{
public:
	StayScene();
	~StayScene();

public:
	void Init() override;
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;
};
