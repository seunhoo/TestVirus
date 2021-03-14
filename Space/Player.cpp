#include "stdafx.h"
#include "Player.h"
#include"Line.h"
#include"MakeSquare.h"
Player::Player()
	: m_State(MoveState::NONE)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	int randomx = rand() % 2 + 1;
	int randomy = rand() % 2 + 1;
	int randomX, randomY;
	if (randomx == 1)
	{
		randomX = rand() % 1920 + 0;
		randomY = 0;

		if (randomX % 10 != 0)
		{
			for (; randomX % 10 != 0;)
			{
				randomX--;
			}
		}
	}
	else
	{
		randomX = rand() % 1920 + 0;
		randomY = 1080;

		if (randomX % 10 != 0)
		{
			for (; randomX % 10 != 0;)
			{
				randomX--;
			}
		}
	}
	if (randomy == 1)
	{
		randomX = 0;
		randomY = rand() % 1080 + 0;

		if (randomY % 10 != 0)
		{
			for (; randomY % 10 != 0;)
			{
				randomY--;
			}
		}
	}
	else
	{
		randomX = 1920;
		randomY = rand() % 1080 + 0;

		if (randomY % 10 != 0)
		{
			for (; randomY % 10 != 0;)
			{
				randomY--;
			}
		}


	}
	m_Layer = 100;
	SetPosition(randomX, randomY);
}

void Player::Update(float deltatime, float time)
{
	MakeSquare::GetInst()->Update(deltatime, time);
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS )
	{
		if (m_Position.y >= 10)
		{
			m_Position.y -= 10;	
			MakeSquare::GetInst()->GetPos(m_Position.x,m_Position.y);
			ObjMgr->AddObject(new Line(m_Position.x, m_Position.y), "UpLine");
		}
			
	}

	else if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS )
	{
		if (m_Position.y <= 1070)
		{
			m_Position.y += 10;
			MakeSquare::GetInst()->GetPos(m_Position.x, m_Position.y);
			ObjMgr->AddObject(new Line(m_Position.x, m_Position.y), "DownLine");
		}
	}

	else if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS )
	{
		if (m_Position.x >= 9)
		{
			m_Position.x -= 10;
			MakeSquare::GetInst()->GetPos(m_Position.x, m_Position.y);
			ObjMgr->AddObject(new Line(m_Position.x, m_Position.y), "LeftLine");
		}
	}

	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS )
	{
		if (m_Position.x <= 1910)
		{
			m_Position.x += 10;
			MakeSquare::GetInst()->GetPos(m_Position.x, m_Position.y);
			ObjMgr->AddObject(new Line(m_Position.x, m_Position.y), "RightLine");
		}

	}

	if (INPUT->GetKey(VK_F1) == KeyState::DOWN)
	{

	}
	if (INPUT->GetKey(VK_F2) == KeyState::DOWN)
	{

	}
	if (INPUT->GetKey(VK_F3) == KeyState::DOWN)
	{

	}

}

void Player::Render()
{
	m_Player->Render();
}

void Player::OnCollision(Object* obj, std::string tag)
{
}
