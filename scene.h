#pragma once
#include"Def.h"
#include"Button.h"
#include"MyClock.h"
#include"PukeManager.h"
#include"Mail.h"

class StartScene
{
	friend class Game;
public:
	Music bgm;
	Button bt_setting, bt_exit;//设置按钮，退出
	Sprite sBackground;
	Sprite sBack_menu;
	Texture tBackground1, tBackground2, tBackground3;
	Texture tBack_menu;
	Font font;
	bool isRunning;//是否在当前场景
	bool isExit;//是否离开当前场景
	StartScene();
private:
	Button bt_Enter, bt_join, bt_creat, bt_fankui, bt_store, bt_wanfa, bt_mail, bt_zhanji;
	Sprite sMeinv, sBackUser, sUserHead, sJf, sRankList;
	Texture tMeinv, tBackUser, tUserHead, tJf, tRankList;
	Text text_jb;

	bool isOnSetting;
	Sprite sBack_setting, sBackMini;
	Texture tBack_setting;
	Button bt_setting_ok, bt_bgm_left, bt_bgm_right, bt_sound_left, bt_sound_right, bt_bg_left, bt_bg_right;
	Text text_bgm, text_sound;

	bool isOnMail;
	int num_mail;
	Sprite sBack_mail, sRedPoint;
	Texture tBack_mail, tRedPoint;
	Button bt_mail_ok;
	Mail mail;

	RenderWindow* app;
	int value_bg;
	void Initial(RenderWindow* app);
	void Start();
	void Update();
	void Input(Event& e);
	void Input_scene(Event& e);
	void Input_setting(Event& e);
	void Input_mail(Event& e);
	void draw_setting();
	void draw_mail();
	void Draw();
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