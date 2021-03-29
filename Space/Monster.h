#pragma once
class Player;
class Monster : public Object
{
public:

	Sprite* m_Monster;

	Player* m_bPlayer;

	Monster(int version);
	Monster(int version, Vec2 pos);

	int m_Version;

	int x, y, t;


	float m_Speed;
	float m_MoveCount;
	float m_ResetCount;

	float dist, disc, didr, disk;
	float a, b, c, d, e, f, g, h, j, k, l, m, n;

	int x1, x2, x3, x4, x5, x6, x7, x8;
	int y1, y2, y3, y4, y5, y6, y7, y8;

	bool m_CollideCheck;
	float m_CollideTime;

	bool m_MoveCheck;
	bool m_BossCheck;

	void Update(float deltatime, float time);
	void Boss();
	void Move();
	void Render();

	void OnCollision(Object* obj, std::string tag);
};

