#pragma once
class Square : public Object
{
public:

	Sprite* m_Square;

	float m_Percent;
	Vec2 m_pScale;

	bool m_CollideCheck;
	float m_CollideTime;

	RECT m_Minus;
	Vec2 m_Minusx;
	Vec2 m_MinusScale;

	bool m_MinusCheck;
	bool m_bMinusCheck;


	float m_cScale;
	float m_pPercent;
	float m_pMinusScale;

	Square(Vec2 pos, Vec2 scale);

	Square();
	
	void Update(float deltatime, float time);

	void Render();

	void OnCollision(Object* obj, std::string tag);
};

