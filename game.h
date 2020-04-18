#pragma once
#include"Def.h"
#include"scene.h"

class Game
{
public:
	RenderWindow* app;
	StartScene start_scene;//开始场景
	GameScene game_scene;//游戏场景
	bool OnStartScene;//在开始场景
	bool OnPlayScene;//在游戏场景
	bool isOvered;//游戏已结束，即将退出
	int gameOver;//0未结算，1胜利，2失败
	Game();
	~Game();
	void Update();//每帧执行一次
	void GameOver();//游戏结束
	void Run();//游戏运行
};