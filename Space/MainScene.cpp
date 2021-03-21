#include "stdafx.h"
#include "MainScene.h"
#include"Player.h"

MainScene::MainScene()
{
	m_BackGround = Sprite::Create(L"Painting/Stage1-1.png");

	m_BackGround->SetPosition(1920 / 2, 1080 / 2);
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


}

void MainScene::Render()
{
	m_BackGround->Render();

	//Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
}
