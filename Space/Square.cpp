#include "stdafx.h"
#include "Square.h"
#include"Player.h"
Square::Square(Vec2 pos, Vec2 scale)
{
	m_pScale = scale;

	m_Square = Sprite::Create(L"Painting/square.png");
	m_Square->SetParent(this);
	SetPosition(pos);
	SetScale(scale.x ,scale.y);

	m_Square->A = 50;

	m_Square->m_Layer = 0;

}

void Square::Update(float deltatime, float time)
{
	ObjMgr->CollisionCheak(this, "Player");
	
	ObjMgr->CollisionCheak(this, "Square");

	if (m_MinusCheck == true && m_bMinusCheck == true)
	{

		m_Minus = ObjMgr->rc;


		m_cScale = (std::abs(m_pScale.x) * std::abs(m_pScale.y));

		m_Minusx.x = m_Minus.right - m_Minus.left;
		m_Minusx.y = m_Minus.bottom - m_Minus.top;
		m_pMinusScale = ((std::abs(m_Minusx.x) * std::abs(m_Minusx.y)) / (1850 * 1010)) * 100;


		m_pPercent = ((m_cScale) / (1920 * 1080)) * 100;
		float m_Percent = std::abs(m_pPercent - m_pMinusScale);
		printf("m_Minus %d %d %d %d \n", m_Minus.top, m_Minus.bottom, m_Minus.left, m_Minus.right);
		printf("percent %f \n", m_Percent);
		ObjMgr->AddCure(std::abs(m_Percent));
		m_bMinusCheck = false;

	}

	if (ObjMgr->GetCure() >= 80)
	{
		//ObjMgr->RemoveObject(this);
		//ObjMgr->ReSetCure();
	}
}

void Square::Render()
{
	

	m_Square->Render();


}

Square::Square()
{
}

void Square::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Player")
	{
	}
	if (tag == "Square" && m_MinusCheck == false && m_bMinusCheck == false)
	{
		m_Minus = ObjMgr->rc;
		m_MinusCheck = true;
		m_bMinusCheck = true;
	}
}
