#include "stdafx.h"
#include "MakeSquare.h"
#include"Regeneration.h"
MakeSquare::MakeSquare()
{
	i = 0;
	memset(m_ArrPos, 0, sizeof(m_ArrPos));
}

void MakeSquare::GetPos(float posx, float posy)
{
	m_Posx = posx;
	m_Posy = posy;

	m_ArrPos[i].x = posx;
	m_ArrPos[i].y = posy;
	i++;
}


void MakeSquare::Update(float deltatime, float time)
{

}

void MakeSquare::Sort()
{
	for (int iter = 0; iter < i; iter++)
	{
		for (int jter = 0; jter < i; jter++)
		{
			if (m_ArrPos[iter].x <= m_ArrPos[jter+1].x)
			{
				float temp;
				temp = m_ArrPos[iter].x;
				m_ArrPos[iter].x = m_ArrPos[jter].x;
				m_ArrPos[jter].x = temp;

			}
		}
	}
	for (int iter = 0; iter < i; iter++)
	{
		for (int jter = 0; jter < i; jter++)
		{
			if (m_ArrPos[iter].y <= m_ArrPos[jter+1].y)
			{
				float temp;
				temp = m_ArrPos[iter].y;
				m_ArrPos[iter].y = m_ArrPos[jter].y;
				m_ArrPos[jter].y = temp;
			}
		}
	}
}

void MakeSquare::Square()
{

		printf("¤Ñ¤Ñ%d \n", i);
		printf("==S X = %f B X = %f \n", m_ArrPos[0].x, m_ArrPos[i - 1].x);
		printf("--S Y = %f B Y = %f \n", m_ArrPos[0].y, m_ArrPos[i - 1].y);

		float x = (m_ArrPos[0].x + m_ArrPos[i - 1].x) / 2;
		float y = (m_ArrPos[0].y + m_ArrPos[i - 1].y) / 2;
		
		ObjMgr->AddObject(new Regeneration(x, y, m_ArrPos[0], m_ArrPos[i - 1]), "Reg");
		i = 0;
		m_Count = 0;
	
}

void MakeSquare::Render()
{
}

void MakeSquare::OnCollision(Object* obj, std::string tag)
{
}
