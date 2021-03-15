#include "stdafx.h"
#include "Line.h"
#include"MakeSquare.h"
Line::Line(float posx, float posy)
{
	m_Line = Sprite::Create(L"Painting/Line.png");
	m_Line->SetParent(this);

	SetPosition(posx, posy);
}

void Line::Update(float deltatime, float time)
{
	if (m_Tag != "UpLine" && m_Tag != "DownLine")
	{
		ObjMgr->CollisionCheak(this, "UpLine");
		//ObjMgr->CollisionCheak(this, "DownLine");
	}
	else if (m_Tag != "LeftLine" && m_Tag != "RightLine")
	{
		//ObjMgr->CollisionCheak(this, "LeftLine");
		//ObjMgr->CollisionCheak(this, "RightLine");
	}
	MakeSquare::GetInst()->Sort();
}

void Line::Render()
{
	m_Line->Render();
}

void Line::OnCollision(Object* obj, std::string tag)
{
	if (obj->m_Tag == "UpLine" || obj->m_Tag == "DownLine" || obj->m_Tag == "LeftLine" || obj->m_Tag == "RightLine")
	{

		MakeSquare::GetInst()->Square();
			ObjMgr->DeleteObject("UpLine");
			ObjMgr->DeleteObject("LeftLine");
			ObjMgr->DeleteObject("RightLine");
			ObjMgr->DeleteObject("DownLine");

	}
}
