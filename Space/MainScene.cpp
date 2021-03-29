#include "stdafx.h"
#include "MainScene.h"
#include"Player.h"
#include"Square.h"
#include"Monster.h"
MainScene::MainScene()
	:m_Timer(180)
{
	m_BackGround = Sprite::Create(L"Painting/BG.png");
//
	m_BackGround->SetPosition(1920 / 2, 1080 / 2);

	m_Text = new TextMgr();
	m_Text->Init(45, "±¼¸²Ã¼");
	m_Text->SetColor(255, 255, 255, 255);

	m_Square = new Square();
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	
	ObjMgr->AddObject(new Player(), "Player");

	ObjMgr->AddObject(new Monster(1), "SpeedMonster");
	ObjMgr->AddObject(new Monster(2), "BigMonster");
	ObjMgr->AddObject(new Monster(3), "FlashMonster");
	ObjMgr->AddObject(new Monster(4), "BossMonster");

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

	m_Text->print("Time : " + std::to_string(int(m_Timer)), 1920/2 - 100, 10);
	m_Text->print("Cure   : " + std::to_string((ObjMgr->GetCure())), 1920/2 - 100, 1030);
	
	Renderer::GetInst()->GetSprite()->End();

}
