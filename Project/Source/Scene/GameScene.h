#pragma once
#include "SceneBase.h"

class GameScene : public SceneBase
{
public:
	GameScene();
	~GameScene();

public:
	void Init() override;
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;
};


