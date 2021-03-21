#pragma once
class MainScene : public Scene
{
public:

	Sprite* m_BackGround;

	MainScene();
	~MainScene();

	void Init();
	void Release();

	void Update(float deltaTime,float time);
	void Render();

public:


};

