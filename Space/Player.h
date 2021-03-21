#pragma once
struct Vertex
{
	float x, y, z, w;
	D3DCOLOR color;
};
#define COLORKEY_GREEN D3DCOLOR_ARGB(255,0,133,0)
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

	float a, b, c,d,e,f,g,h,j,k,l,m, dist,disk,disc, didr;

	bool m_Right;
	bool m_Left;
	bool m_Up;
	bool m_Down;

	bool m_Square;

	int i;
	int m_Length;

	int m_Move;

	Vec2 m_PlayerPos[3000];
	Vec2 m_CurPos[3000];

	Player();

	void Update(float deltatime, float time);
	void Line();
	void MakeLine();
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

