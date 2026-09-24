#pragma once
#include "SceneBase.h"

class ShopScene : public SceneBase
{
public:
	ShopScene();
	~ShopScene();

public:
	void Init() override;
	void Load() override;
	void Start() override;
	void Step() override;
	void Update() override;
	void Draw() override;
	void Fin() override;

	void BuySkill(int index);
private:
	int m_GoldIcon;
	int m_SkillImage[5];
	int m_SkillPrice[5] = { 150, 100, 50, 50, 50 };
	int m_SelectIndex;


};
