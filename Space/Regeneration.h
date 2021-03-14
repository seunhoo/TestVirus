#pragma once
class Regeneration : public Object
{
public:

	Sprite* m_Reg;

	float m_Posx, m_Posy;

	Vec2 m_Pos, m_Pos2;


	Regeneration(float posx, float posy, Vec2 pos,Vec2 pos2);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

