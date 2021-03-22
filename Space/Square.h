#pragma once
class Square : public Object
{
public:

	Sprite* m_Square;

	float m_Percent;
	Vec2 m_pScale;

	bool m_CollideCheck;
	float m_CollideTime;

	Square(Vec2 pos, Vec2 scale);
	
	void Update(float deltatime, float time);

	void Render();

	void OnCollision(Object* obj, std::string tag);
};

