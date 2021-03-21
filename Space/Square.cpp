#include "stdafx.h"
#include "Square.h"

Square::Square(Vec2 pos, Vec2 scale)
{
	m_Square = Sprite::Create(L"Painting/square.png");
	m_Square->SetParent(this);
	SetPosition(pos);
	SetScale(scale.x ,scale.y);
	
}

void Square::Update(float deltatime, float time)
{
}

void Square::Render()
{
	m_Square->Render();
}
