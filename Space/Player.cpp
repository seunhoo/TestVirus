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
	,m_PlayerHp(5)
{
	srand(time(NULL));
	m_Player = Sprite::Create(L"Painting/Player.png");
	m_Player->SetParent(this);
	int randomx = (rand() % 2) + 1;
	int randomy = (rand() % 2) + 1;
	int randomX = 0, randomY = 0;

	if (randomx == 1)
	{
		randomX = rand() % 1850 + 70;
		randomY = 70;

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
		randomX = rand() % 1850 + 70;
		randomY = 1010;

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
		randomX = 70;
		randomY = rand() % 1020 + 70;

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
		randomX = 1850;
		randomY = rand() % 1020 + 70;

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

	SetPosition(randomX, randomY);

	m_Line = new LineMgr();
	m_Line->Init(3, 1);
	m_Line->SetColor(D3DCOLOR_ARGB(255, 255, 0, 0));

	m_Text = new TextMgr();
	m_Text->Init(45, "±¼¸²Ã¼");
	m_Text->SetColor(255,255,0,0);

	memset(m_PlayerPos, 0, sizeof(m_PlayerPos));
	m_PlayerPos[0].x =randomX;
	m_PlayerPos[0].y =randomY;

	m_Length++;
}

void Player::Update(float deltatime, float time)
{




	if (INPUT->GetKey(VK_UP) == KeyState::PRESS )
	{
		m_PlayerPos[i] = m_Position;
		if (m_State != MoveState::UP && m_State != MoveState::DOWN)
		{
			m_PlayerPos[i] = m_Position;
			m_Length++;
			m_Move = 1;
			m_State = MoveState::UP;
			printf("U i%d \n", i);
			printf("U Length i%d \n", m_Length);
			i++;
		}
		if (m_Position.y >= 80)
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
			m_Length++;
			m_Move = 2;

			m_State = MoveState::DOWN;
			printf("D i%d \n", i);
			printf("D Length i%d \n", m_Length);
			i++;
		}

		if (m_Position.y <= 1000)
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
			m_Length++;
			m_Move = 3;

			m_State = MoveState::LEFT;
			printf("L i%d \n", i);
			printf("L Length i%d \n", m_Length);
			i++;
		}
		if (m_Position.x >= 80)
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
			m_Length++;
			m_Move = 4;

			m_State = MoveState::RIGHT;
			printf("R i%d \n", i);
			printf("R Length i%d \n", m_Length);
			i++;
		}
		if (m_Position.x <= 1840)
		{
			m_Position.x += 10;

		}

	}
	if (i >= 4 && m_Length >= 5 && (
		//(dist == 0 && disk == 0) ||
		//(dist == 0 && disc == 0) ||
		(dist == 0 && didr == 0) 
		//(disc == 0 && didr == 0) ||
		//(disc == 0 && disk == 0) ||
		//(disk == 0 && didr == 0)
		))
	{
		x1 = m_PlayerPos[0].x < m_PlayerPos[1].x ? m_PlayerPos[0].x : m_PlayerPos[1].x;
		y1 = m_PlayerPos[0].y < m_PlayerPos[1].y ? m_PlayerPos[0].y : m_PlayerPos[1].y;
		x2 = m_PlayerPos[0].x > m_PlayerPos[1].x ? m_PlayerPos[0].x : m_PlayerPos[1].x;
		y2 = m_PlayerPos[0].y > m_PlayerPos[1].y ? m_PlayerPos[0].y : m_PlayerPos[1].y;
		
		//x3 = m_PlayerPos[1].x < m_PlayerPos[2].x ? m_PlayerPos[1].x : m_PlayerPos[2].x;
		//y3 = m_PlayerPos[1].y < m_PlayerPos[2].y ? m_PlayerPos[1].y : m_PlayerPos[2].y;
		//x4 = m_PlayerPos[1].x > m_PlayerPos[2].x ? m_PlayerPos[1].x : m_PlayerPos[2].x;
		//y4 = m_PlayerPos[1].y > m_PlayerPos[2].y ? m_PlayerPos[1].y : m_PlayerPos[2].y;

		//x5 = m_PlayerPos[2].x < m_PlayerPos[3].x ? m_PlayerPos[2].x : m_PlayerPos[3].x;
		//y5 = m_PlayerPos[2].y < m_PlayerPos[3].y ? m_PlayerPos[2].y : m_PlayerPos[3].y;
		//x6 = m_PlayerPos[2].x > m_PlayerPos[3].x ? m_PlayerPos[2].x : m_PlayerPos[3].x;
		//y6 = m_PlayerPos[2].y > m_PlayerPos[3].y ? m_PlayerPos[2].y : m_PlayerPos[3].y;

		//x7 = m_PlayerPos[3].x < m_PlayerPos[4].x ? m_PlayerPos[3].x : m_PlayerPos[4].x;
		//y7 = m_PlayerPos[3].y < m_PlayerPos[4].y ? m_PlayerPos[3].y : m_PlayerPos[4].y;
		//x8 = m_PlayerPos[3].x > m_PlayerPos[4].x ? m_PlayerPos[3].x : m_PlayerPos[4].x;
		//y8 = m_PlayerPos[3].y > m_PlayerPos[4].y ? m_PlayerPos[3].y : m_PlayerPos[4].y;

		if (dist < 10 && m_Position.x >= x1 - 10 && m_Position.x <= x2 + 10 && m_Position.y >= y1 - 10 && m_Position.y <= y2 + 10)
		{
			m_PlayerPos[0] = m_PlayerPos[4];
			m_Square = true;
		}
		//else if (disc < 10 && m_Position.x >= x3 - 10 && m_Position.x <= x4 + 10 && m_Position.y >= y3 - 10 && m_Position.y <= y4 + 10)
		//{
		//	m_PlayerPos[0] = m_PlayerPos[4];
		//	m_Square = true;
		//}
		//else if (disk < 10 && m_Position.x >= x5 - 10 && m_Position.x <= x6 + 10 && m_Position.y >= y5 - 10 && m_Position.y <= y6 + 10)
		//{
		//	m_PlayerPos[0] = m_PlayerPos[4];
		//	m_Square = true;
		//}
		//else if (didr < 10 && m_Position.x >= x7 - 10 && m_Position.x <= x8 + 10 && m_Position.y >= y7 - 10 && m_Position.y <= y8 + 10)
		//{
		//	m_PlayerPos[0] = m_PlayerPos[4];
		//	m_Square = true;
		//}
		else
		{
			m_Square = false;
		}
	}

	if (m_Square == true)
	{

		printf("Q 0 %f %f \n", m_PlayerPos[0].x, m_PlayerPos[0].y);
		printf("Q 1 %f %f \n", m_PlayerPos[1].x, m_PlayerPos[1].y);
		printf("Q 2 %f %f \n", m_PlayerPos[2].x, m_PlayerPos[2].y);
		printf("Q 3 %f %f \n", m_PlayerPos[3].x, m_PlayerPos[3].y);
		printf("Q 4 %f %f \n", m_PlayerPos[4].x, m_PlayerPos[4].y);

		
		if (m_CollideSquare == true)
		{
			
				if (m_PlayerPos[0] == m_PlayerPos[1])
				{
					float posx = (m_PlayerPos[0].x + m_PlayerPos[3].x) / 2;
					float posy = (m_PlayerPos[0].y + m_PlayerPos[3].y) / 2;

					float scalex = std::abs((m_PlayerPos[3].x - m_PlayerPos[0].x)) / 10;
					float scaley = std::abs((m_PlayerPos[3].y - m_PlayerPos[0].y)) / 10;


					ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(std::abs(scalex), std::abs(scaley))), "Square");

				}
				else
				{
					float posx = (m_PlayerPos[0].x + m_PlayerPos[2].x) / 2;
					float posy = (m_PlayerPos[0].y + m_PlayerPos[2].y) / 2;


					float scalex = std::abs((m_PlayerPos[2].x - m_PlayerPos[0].x)) / 10;
					float scaley = std::abs((m_PlayerPos[2].y - m_PlayerPos[0].y)) / 10;


					ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(std::abs(scalex), std::abs(scaley))), "Square");

				}

			i = 1;
			m_Length = 2;
			m_PlayerPos[0] = m_Position;
			m_CollideSquare = false;
		}
		else
		{
			float posx = (m_PlayerPos[0].x + m_PlayerPos[2].x) / 2;
			float posy = (m_PlayerPos[0].y + m_PlayerPos[2].y) / 2;
			float scalex = std::abs((m_PlayerPos[2].x - m_PlayerPos[0].x)) / 10;
			float scaley = std::abs((m_PlayerPos[2].y - m_PlayerPos[0].y)) / 10;


			ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(std::abs(scalex), std::abs(scaley))), "Square");

			i = 1;
			m_Length = 2;
			m_PlayerPos[1] = m_Position;
		}
		m_Square = false;
	}
	//if (m_CollideSquare == true)
	//{
	//	if (m_PlayerPos[3].x > m_PlayerPos[2].x)
	//	{
	//		m_PlayerPos[2].x = m_PlayerPos[3].x;
	//	}
	//	else if (m_PlayerPos[0].y < m_PlayerPos[3].y)
	//	{
	//		m_PlayerPos[0].y = m_PlayerPos[3].y;
	//	}
	//	else if (m_PlayerPos[0].x > m_PlayerPos[3].x)
	//	{
	//		m_PlayerPos[0].x = m_PlayerPos[3].x;
	//	}
	//	float posx = (m_PlayerPos[0].x + m_PlayerPos[2].x) / 2;
	//	float posy = (m_PlayerPos[0].y + m_PlayerPos[2].y) / 2;
	//	float scalex = (m_PlayerPos[2].x - m_PlayerPos[0].x) / 10;
	//	float scaley = (m_PlayerPos[2].y - m_PlayerPos[0].y) / 10;

	//	ObjMgr->AddObject(new Square(Vec2(posx, posy), Vec2(std::abs(scalex), std::abs(scaley))), "Square");
	//	printf("Box i%d \n", i);
	//	i = 1;
	//	m_Length = 2;
	//	m_PlayerPos[0] = m_Position;
	//	m_CollideSquare = false;
	//}
	Line();
}
void Player::Line()
{
	a = m_PlayerPos[0].y - m_PlayerPos[1].y;
	b = m_PlayerPos[1].x - m_PlayerPos[0].x;
	c = m_PlayerPos[0].x * m_PlayerPos[1].y - m_PlayerPos[1].x * m_PlayerPos[0].y;
	dist = (float)std::abs(a * m_Position.x + b * m_Position.y + c) / (float)std::sqrt(a * a + b * b);

	//d = m_PlayerPos[1].y - m_PlayerPos[2].y;
	//e = m_PlayerPos[2].x - m_PlayerPos[1].x;
	//f = m_PlayerPos[1].x * m_PlayerPos[2].y - m_PlayerPos[2].x * m_PlayerPos[1].y;
	//disk = (float)std::abs(d * m_Position.x + e * m_Position.y + f) / (float)std::sqrt(d * d+ e * e);

	//g = m_PlayerPos[2].y - m_PlayerPos[3].y;
	//h = m_PlayerPos[3].x - m_PlayerPos[2].x;
	//j = m_PlayerPos[2].x * m_PlayerPos[3].y - m_PlayerPos[3].x * m_PlayerPos[2].y;
	//disc = (float)std::abs(g * m_Position.x + h * m_Position.y + j) / (float)std::sqrt(g * g + h * h);

	k = m_PlayerPos[3].y - m_PlayerPos[4].y;
	l = m_PlayerPos[4].x - m_PlayerPos[3].x;
	m = m_PlayerPos[3].x * m_PlayerPos[4].y - m_PlayerPos[4].x * m_PlayerPos[3].y;
	didr = (float)std::abs(k * m_Position.x + l * m_Position.y + m) / (float)std::sqrt(k * k + l * l);


}
void Player::Render()
{
	m_Player->Render();
	m_Line->DrawLine(m_PlayerPos, m_Length);

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print("Hp : " + std::to_string(m_PlayerHp), 1600, 50);
	Renderer::GetInst()->GetSprite()->End();

}

void Player::OnCollision(Object* obj, std::string tag)
{
	if (tag == "Square")
	{

		//if (i >= 3 && m_Length >=4)
		//{
		//	//m_PlayerPos[4] = m_Position;
		//	printf("0 %f %f \n", m_PlayerPos[0].x, m_PlayerPos[0].y);
		//	printf("1 %f %f \n", m_PlayerPos[1].x, m_PlayerPos[1].y);
		//	printf("2 %f %f \n", m_PlayerPos[2].x, m_PlayerPos[2].y);
		//	printf("3 %f %f \n", m_PlayerPos[3].x, m_PlayerPos[3].y);
		//	printf("4 %f %f \n ____________________ \n", m_PlayerPos[4].x, m_PlayerPos[4].y);
		//	

		//	m_CollideSquare = true;

		//	//i = 1;
		//	//m_Length = 0;
		//	m_State = MoveState::NONE;
		//}


		if (i >= 3 && m_Length >= 4)
		{
			printf("C 0 %f %f \n", m_PlayerPos[0].x, m_PlayerPos[0].y);
			printf("C 1 %f %f \n", m_PlayerPos[1].x, m_PlayerPos[1].y);
			printf("C 2 %f %f \n", m_PlayerPos[2].x, m_PlayerPos[2].y);
			printf("C 3 %f %f \n", m_PlayerPos[3].x, m_PlayerPos[3].y);
			printf("C 4 %f %f \n", m_PlayerPos[4].x, m_PlayerPos[4].y);
			//m_PlayerPos[0] = m_PlayerPos[4];
			//m_PlayerPos[4] = m_Position;
			m_Square = true;
			m_CollideSquare = true;
		}

	}
}
