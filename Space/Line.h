#pragma once
class Line : public Object
{
public:

	Sprite* m_Line;

	int m_V;

	float m_Count;

	Line(float posx, float posy);

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

