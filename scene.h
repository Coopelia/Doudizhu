#pragma once
#include"Def.h"
#include"Button.h"
#include"Menu.h"
#include"MyClock.h"
#include"PukeManager.h"

class StartScene
{
	friend class Game;
public:
	Music bgm;
	Button bt_setting, bt_exit;//设置按钮，退出
	Sprite sBackground;
	Sprite sBack_menu;
	Texture tBackground;
	Texture tBack_menu;
	bool isRunning;//是否在当前场景
	bool isExit;//是否离开当前场景
	StartScene();
private:
	Button bt_Enter, bt_join, bt_creat, bt_fankui, bt_store, bt_wanfa, bt_mail, bt_zhanji;
	Sprite sMeinv, sBackUser, sUserHead, sJf, sRankList;
	Texture tMeinv, tBackUser, tUserHead, tJf, tRankList;
	RenderWindow* app;
	void Initial(RenderWindow* app);
	void Start();
	void Update();
	void Draw();
	void Input(Event& e);
	void SceneClose();
};

class GameScene: public StartScene
{
	friend class Game;
public:
	PukeManager puke_manager;//扑克管理器
	Player human;//玩家
	AI ai_1, ai_2;//AI
	Sprite sOver;
	Texture tOver[2];
	MyClock clock_showCall;//出牌倒计时
	bool isDealing;//是否正在发牌
	bool isDealDizhu;//是否正在叫地主阶段
	bool isPlaying;
	bool isGameover;//有人手牌已全部打出，游戏结束
	GameScene();
	void Initial(RenderWindow* app);
	void Start();//场景运行前执行一次
	void Update();//场景运行时每帧执行一次
	void Draw();//绘制
	void player_turn_input(Event& e);//玩家轮流出牌和叫地主
	void Input(Event& e);//输入
	void SceneClose();//场景关闭
private:
	RenderWindow* app;
};