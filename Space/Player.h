#pragma once
enum class MoveState
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	NONE

};
class Player : public Object	
{
public:

	MoveState m_State;

	Sprite* m_Player;

	float m_LineCount;

	bool m_Right;
	bool m_Left;
	bool m_Up;
	bool m_Down;


	Player();

	void Update(float deltatime, float time);
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

