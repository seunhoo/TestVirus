#include "stdafx.h"
#include "Player.h"
#include"Line.h"
#include"MakeSquare.h"
#include"LineMgr.h"
Player::Player()
	: m_State(MoveState::NONE)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	int randomx = rand() % 2 + 1;
	int randomy = rand() % 2 + 1;
	int randomX = 0, randomY = 0;
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
	else if(randomx ==2)
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
	else if(randomy ==2)
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

	m_Line = new LineMgr();
	m_Line->Init(2, 1);
	m_Line->SetColor(D3DCOLOR_ARGB(255, 0, 0, 0));

	m_PlayerPos[0].x =randomX;
	m_PlayerPos[0].y =randomY;
}

void Player::Update(float deltatime, float time)
{
	m_Length++;
	if (INPUT->GetKey(VK_UP) == KeyState::PRESS )
	{
	
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_Move = 1;
			printf("%d \n", m_Move);
			m_PlayerPos[i] = m_Position;
			m_State = MoveState::UP;
			i++;
		}
		if (m_Position.y >= 10)
		{
			m_Position.y -= 10;

		}
	}

	else if (INPUT->GetKey(VK_DOWN) == KeyState::PRESS )
	{
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_Move = 2;
			printf("%d \n", m_Move);
			m_PlayerPos[i] = m_Position;
			m_State = MoveState::DOWN;
			i++;
		}

		if (m_Position.y <= 1070)
		{
			m_Position.y += 10;

		}
	}

	else if (INPUT->GetKey(VK_LEFT) == KeyState::PRESS )
	{

		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_Move = 3;
			printf("%d \n", m_Move);
			m_PlayerPos[i] = m_Position;
			m_State = MoveState::LEFT;
			i++;
		}
		if (m_Position.x >= 9)
		{
			m_Position.x -= 10;

		}
	}

	else if (INPUT->GetKey(VK_RIGHT) == KeyState::PRESS )
	{
	
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_Move = 4;
			printf("%d \n", m_Move);
			m_PlayerPos[i] = m_Position;
			m_State = MoveState::RIGHT;
			i++;
		}
		if (m_Position.x <= 1910)
		{
			m_Position.x += 10;

		}

	}

	Line();
	MakeLine();

}

void Player::Line()
{
}

void Player::MakeLine()
{
}

void Player::Render()
{
	m_Player->Render();
	m_Line->DrawLine(m_PlayerPos, m_Length);
}

void Player::OnCollision(Object* obj, std::string tag)
{
}
