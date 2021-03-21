#pragma once
class Square : public Object
{
public:

	Sprite* m_Square;

	Square(Vec2 pos, Vec2 scale);
	
	void Update(float deltatime, float time);

	void Render();
};

