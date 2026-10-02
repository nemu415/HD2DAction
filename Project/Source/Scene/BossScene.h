#pragma once
#include "SceneBase.h"

class BossScene : public SceneBase
{
public:
	BossScene();
	~BossScene();

public:
	void Init() override;
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;

public:
	static int m_StageLevel;
private:
	int m_GoldIcon;
	int m_Background;
	int m_PressFont;
};


