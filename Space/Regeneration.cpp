#include "stdafx.h"
#include "Regeneration.h"

Regeneration::Regeneration(float posx, float posy,Vec2 pos,Vec2 pos2)
{
	m_Posx = posx;
	m_Posy = posy;

	m_Pos = pos;
	m_Pos2 = pos2;

	m_Reg = Sprite::Create(L"Painting/Line2.png");
	m_Reg->SetParent(this);

	//m_Reg->m_Rect.top = m_Pos.y;
	//m_Reg->m_Rect.bottom = m_Pos2.y;

	//m_Reg->m_Rect.right = m_Pos.x;
	//m_Reg->m_Rect.left = m_Pos2.x;

	
	SetPosition(posx, posy);

	printf("%f %f \n", m_Position.x, m_Position.y);
	printf("top %d  bottom %d \n", m_Reg->m_Rect.top, m_Reg->m_Rect.bottom);
	printf("right %d  left %d \n", m_Reg->m_Rect.right, m_Reg->m_Rect.left);
}

void Regeneration::Update(float deltatime, float time)
{
}

void Regeneration::Render()
{
	m_Reg->Render();
	

}

void Regeneration::OnCollision(Object* obj, std::string tag)
{
}
