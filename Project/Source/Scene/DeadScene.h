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

private:
	int m_Background;
	int m_TitleFont;
	int m_PressFont;
};


