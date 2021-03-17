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
	LineMgr* m_Line;
	Sprite* m_Player;

	float m_LineCount;

	bool m_Right;
	bool m_Left;
	bool m_Up;
	bool m_Down;

	int i;
	int m_Length;

	int m_Move;

	Vec2 m_PlayerPos[3000];

	Player();

	void Update(float deltatime, float time);
	void Line();
	void MakeLine();
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

