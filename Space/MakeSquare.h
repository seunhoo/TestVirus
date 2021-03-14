#pragma once
class MakeSquare  : public Singleton<MakeSquare>
{
public:

	float m_Posx;
	float m_Posy;



	int i = 0;
	int j = 0;

	Vec2 m_ArrPos[1000];

	float m_Count;


	MakeSquare();


	void GetPos(float posx, float posy);

	
	void Update(float deltatime, float time);
	void Sort();
	void Square();
	void Render();
	void OnCollision(Object* obj, std::string tag);
};

