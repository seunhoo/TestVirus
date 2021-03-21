#include "stdafx.h"
#include "Player.h"
#include"Line.h"
#include"MakeSquare.h"
#include"LineMgr.h"
#include"Square.h"
Player::Player()
	: m_State(MoveState::NONE)
	,m_Length(0)
	,i(0)
{
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	int randomx = rand() % 2 + 1;
	int randomy = rand() % 2  + 1;
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
	else if(randomx == 2)
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
		randomY = rand() % 1080 + 0;

		if (randomY % 10 != 0)
		{
			for (; randomY % 10 != 0;)
			{
				randomY--;
			}
		}
	}
	else if(randomy == 2)
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
	printf("%d %d %d %d \n", randomx, randomy, randomX, randomY);
	m_Layer = 100;
	//SetPosition(randomX, randomY);
	SetPosition(randomX, randomY);

	m_Line = new LineMgr();
	m_Line->Init(3, 1);
	m_Line->SetColor(D3DCOLOR_ARGB(255, 255, 0, 0));
	memset(m_PlayerPos, 0, sizeof(m_PlayerPos));
	m_PlayerPos[0].x =randomX;
	m_PlayerPos[0].y =randomY;
	m_CurPos[0].x = randomX;
	m_CurPos[0].y = randomY;
	m_Length++;
}

void Player::Update(float deltatime, float time)
{
	//printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");
	//printf("%f %f \n", m_PlayerPos[0].x, m_PlayerPos[0].y);
	//printf("%f %f \n", m_PlayerPos[1].x, m_PlayerPos[1].y);
	//printf("%f %f \n", m_PlayerPos[2].x, m_PlayerPos[2].y);
	//printf("%f %f \n", m_PlayerPos[3].x, m_PlayerPos[3].y);
	//printf("�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�\n");



	if (INPUT->GetKey(VK_UP) == KeyState::PRESS )
	{
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_PlayerPos[i] = m_Position;
			//m_CurPos[i] = m_Position;
			m_Length++;
			m_Move = 1;
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
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_PlayerPos[i] = m_Position;
			//m_CurPos[i] = m_Position;
			m_Length++;
			m_Move = 2;

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
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_PlayerPos[i] = m_Position;
			//m_CurPos[i] = m_Position;
			m_Length++;
			m_Move = 3;

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
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::RIGHT && m_State != MoveState::LEFT)
		{
			m_PlayerPos[i] = m_Position;
			//m_CurPos[i] = m_Position;
			m_Length++;
			m_Move = 4;

			m_State = MoveState::RIGHT;
			i++;
		}
		if (m_Position.x <= 1910)
		{
			m_Position.x += 10;

		}

	}
	if (i >= 4 && m_Length >= 5 && (
		(dist == 0 && disk == 0) ||
		(dist == 0 && disc == 0) ||
		(dist == 0 && didr == 0) ||
		(disc == 0 && didr == 0) ||
		(disc == 0 && disk == 0) ||
		(disk == 0 && didr == 0)))
	{
		int x1 = m_PlayerPos[0].x < m_PlayerPos[1].x ? m_PlayerPos[0].x : m_PlayerPos[1].x;
		int y1 = m_PlayerPos[0].y < m_PlayerPos[1].y ? m_PlayerPos[0].y : m_PlayerPos[1].y;
		int x2 = m_PlayerPos[0].x > m_PlayerPos[1].x ? m_PlayerPos[0].x : m_PlayerPos[1].x;
		int y2 = m_PlayerPos[0].y > m_PlayerPos[1].y ? m_PlayerPos[0].y : m_PlayerPos[1].y;

		int x3 = m_PlayerPos[1].x < m_PlayerPos[2].x ? m_PlayerPos[1].x : m_PlayerPos[2].x;
		int y3 = m_PlayerPos[1].y < m_PlayerPos[2].y ? m_PlayerPos[1].y : m_PlayerPos[2].y;
		int x4 = m_PlayerPos[1].x > m_PlayerPos[2].x ? m_PlayerPos[1].x : m_PlayerPos[2].x;
		int y4 = m_PlayerPos[1].y > m_PlayerPos[2].y ? m_PlayerPos[1].y : m_PlayerPos[2].y;

		int x5 = m_PlayerPos[2].x < m_PlayerPos[3].x ? m_PlayerPos[2].x : m_PlayerPos[3].x;
		int y5 = m_PlayerPos[2].y < m_PlayerPos[3].y ? m_PlayerPos[2].y : m_PlayerPos[3].y;
		int x6 = m_PlayerPos[2].x > m_PlayerPos[3].x ? m_PlayerPos[2].x : m_PlayerPos[3].x;
		int y6 = m_PlayerPos[2].y > m_PlayerPos[3].y ? m_PlayerPos[2].y : m_PlayerPos[3].y;

		int x7 = m_PlayerPos[3].x < m_PlayerPos[4].x ? m_PlayerPos[3].x : m_PlayerPos[4].x;
		int y7 = m_PlayerPos[3].y < m_PlayerPos[4].y ? m_PlayerPos[3].y : m_PlayerPos[4].y;
		int x8 = m_PlayerPos[3].x > m_PlayerPos[4].x ? m_PlayerPos[3].x : m_PlayerPos[4].x;
		int y8 = m_PlayerPos[3].y > m_PlayerPos[4].y ? m_PlayerPos[3].y : m_PlayerPos[4].y;


		printf("%f %f \n", m_Position.x, m_Position.y);

		printf("\n %d %d %d %d %d %d %d %d \n",x1,x2,x3,x4,x5,x6,x7,x8 );
		printf("\n %d %d %d %d %d %d %d %d \n",y1,y2,y3,y4,y5,y6,y7,y8 );

		printf("%f \n", dist);
		printf("%f \n", disk);
		printf("%f \n", disc);
		printf("%f \n", didr);

		if (dist < 10 && m_Position.x >= x1 - 10 && m_Position.x <= x2 + 10 && m_Position.y >= y1 - 10 && m_Position.y <= y2 + 10)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else if (disc < 10 && m_Position.x >= x3 - 10 && m_Position.x <= x4 + 10 && m_Position.y >= y3 - 10 && m_Position.y <= y4 + 10)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else if (disk < 10 && m_Position.x >= x5 - 10 && m_Position.x <= x6 + 10 && m_Position.y >= y5 - 10 && m_Position.y <= y6 + 10)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else if (didr < 10 && m_Position.x >= x7 - 10 && m_Position.x <= x8 + 10 && m_Position.y >= y7 - 10 && m_Position.y <= y8 + 10)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		else
		{
			m_Square = false;
		}
		
		
	}

	Line();
	MakeLine();

	if (INPUT->GetKey('P') == KeyState::DOWN)
		m_Square = false;

	//if (i >= 5)
	//{
	//	//m_Length = 1;
	//	i = 0;
	//}


}

void Player::Line()
{
	a = m_PlayerPos[0].y - m_PlayerPos[1].y;
	b = m_PlayerPos[1].x - m_PlayerPos[0].x;
	c = m_PlayerPos[0].x * m_PlayerPos[1].y - m_PlayerPos[1].x * m_PlayerPos[0].y;
	dist = (float)std::abs(a * m_Position.x + b * m_Position.y + c) / (float)std::sqrt(a * a + b * b);

	d = m_PlayerPos[1].y - m_PlayerPos[2].y;
	e = m_PlayerPos[2].x - m_PlayerPos[1].x;
	f = m_PlayerPos[1].x * m_PlayerPos[2].y - m_PlayerPos[2].x * m_PlayerPos[1].y;
	disk = (float)std::abs(d * m_Position.x + e * m_Position.y + f) / (float)std::sqrt(d * d+ e * e);

	g = m_PlayerPos[2].y - m_PlayerPos[3].y;
	h = m_PlayerPos[3].x - m_PlayerPos[2].x;
	j = m_PlayerPos[2].x * m_PlayerPos[3].y - m_PlayerPos[3].x * m_PlayerPos[2].y;
	disc = (float)std::abs(g * m_Position.x + h * m_Position.y + j) / (float)std::sqrt(g * g + h * h);

	k = m_PlayerPos[3].y - m_PlayerPos[4].y;
	l = m_PlayerPos[4].x - m_PlayerPos[3].x;
	m = m_PlayerPos[3].x * m_PlayerPos[4].y - m_PlayerPos[4].x * m_PlayerPos[3].y;
	didr = (float)std::abs(k * m_Position.x + l * m_Position.y + m) / (float)std::sqrt(k * k + l * l);





	//printf("%d %d \n", m_Length, i);
}

void Player::MakeLine()
{
}

void Player::Render()
{
	m_Player->Render();
	m_Line->DrawLine(m_PlayerPos, m_Length);

	if (m_Square == true)
	{
		//Renderer::GetInst()->GetSprite()->End();
		//Renderer::GetInst()->GetDevice()->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
		//Vertex  v[4] = {
		//	{m_PlayerPos[0].x, m_PlayerPos[0].y, 1, 1, D3DCOLOR_ARGB(255,255,255,255)}, //��
		//	{m_PlayerPos[1].x, m_PlayerPos[1].y, 1, 1, D3DCOLOR_ARGB(255,0,0,0)},		//��
		//	{m_PlayerPos[3].x, m_PlayerPos[3].y, 1, 1, D3DCOLOR_ARGB(255,0,255,0)},		//��
		//	{m_PlayerPos[2].x, m_PlayerPos[2].y, 1, 1, D3DCOLOR_ARGB(255,255,0,0)},		//��
		//};
		//Renderer::GetInst()->GetDevice()->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, v, sizeof(Vertex));
		//Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	
		float posx = (m_PlayerPos[0].x + m_PlayerPos[2].x) / 2;
		float posy = (m_PlayerPos[0].y + m_PlayerPos[2].y) / 2;
		float scalex = (m_PlayerPos[2].x - m_PlayerPos[0].x) / 10;
		float scaley = (m_PlayerPos[2].y - m_PlayerPos[0].y) / 10;
		ObjMgr->AddObject(new Square(Vec2(posx,posy),Vec2(scalex,scaley)), "Square");

		i = 0;
		m_Length = 1;
		m_Square = false;

	}

	//if (m_Square)
	//{

}

void Player::OnCollision(Object* obj, std::string tag)
{
}
