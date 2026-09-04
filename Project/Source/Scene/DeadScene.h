#pragma once
#include "SceneBase.h"

class DeadScene : public SceneBase
{
public:
	DeadScene();
	~DeadScene();

public:
	void Init() override;
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;
};


