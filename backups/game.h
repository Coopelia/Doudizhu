#pragma once
#include"Def.h"
#include"scene.h"

class Game
{
public:
	RenderWindow* app;
	StartScene start_scene;//��ʼ����
	GameScene game_scene;//��Ϸ����
	bool OnStartScene;//�ڿ�ʼ����
	bool OnPlayScene;//����Ϸ����
	bool isOvered;//��Ϸ�ѽ����������˳�
	int gameOver;//0δ���㣬1ʤ����2ʧ��
	Game();
	~Game();
	void Update();//ÿִ֡��һ��
	void GameOver();//��Ϸ����
	void Run();//��Ϸ����
};