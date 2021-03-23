#include "stdafx.h"
#include "MainScene.h"
#include"Player.h"

MainScene::MainScene()
	:m_Timer(180)
{
	m_BackGround = Sprite::Create(L"Painting/Stage1-1.png");

	m_BackGround->SetPosition(1920 / 2, 1080 / 2);

	m_Text = new TextMgr();
	m_Text->Init(45, "±¼¸²Ã¼");
	m_Text->SetColor(255, 255, 255, 255);
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	
	ObjMgr->AddObject(new Player(), "Player");

}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	m_Timer-= dt;

}

void MainScene::Render()
{
	m_BackGround->Render();

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

	m_Text->print("Time : " + std::to_string(int(m_Timer)), 1920/2, 100);

	Renderer::GetInst()->GetSprite()->End();

	//Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}
