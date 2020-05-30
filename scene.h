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
	Sprite sBackground; //背景
	Sprite sBack_menu;//菜单背景
	Texture tBackground1, tBackground2, tBackground3;
	Texture tBack_menu;
	Font font;//字体
	bool isRunning;//是否在当前场景
	bool isExit;//是否离开当前场景
	StartScene();
	//设置菜单
	bool isOnSetting;
	Sprite sBack_setting, sBackMini;
	Texture tBack_setting;
	Button bt_setting_ok, bt_bgm_left, bt_bgm_right, bt_sound_left, bt_sound_right, bt_bg_left, bt_bg_right, bt_rhythm_left, bt_rhythm_right;
	Text text_bgm, text_sound, text_rhythm;
	//退出对话框
	bool isOnExit;
	Sprite sBack_exit;
	Texture tBack_exit;
	Button bt_exit_ok, bt_exit_cancel;
	//对应的输入和绘制函数
	void Input_setting(Event& e);
	void draw_setting(RenderWindow* app);
	void draw_exit(RenderWindow* app);
private:
	Button bt_Enter, bt_join, bt_creat, bt_fankui, bt_store, bt_wanfa, bt_mail, bt_zhanji;
	Sprite sMeinv, sBackUser, sUserHead, sJf, sRankList;
	Texture tMeinv, tBackUser, tUserHead, tJf, tRankList;
	Text text_jb;
	//邮件菜单
	bool isOnMail;
	int num_mail;
	Sprite sBack_mail, sRedPoint;
	Texture tBack_mail, tRedPoint;
	Button bt_mail_close;
	Mail mail;
	//玩法菜单
	bool isOnWanfa;
	Sprite sBack_wanfa;
	Texture tBack_wanfa;
	Button bt_wanfa_ok;
	//反馈菜单
	bool isOnFankui;
	Sprite sBack_fankui;
	Texture tBack_fankui;
	Button bt_fankui_close;
	//战绩菜单
	bool isOnZhanji;
	Sprite sBack_zhanji;
	Texture tBack_zhanji;
	Button bt_zhanji_close;
	//商店菜单
	bool isOnStore;
	Sprite sBack_store;
	Texture tBack_store;
	Button bt_store_close;

	RenderWindow* app;//活动窗口
	int value_bg;//背景音乐音量
	void Initial(RenderWindow* app);//绑定活动窗口
	void Start();//载入场景时执行一次
	void Update();//载入场景后没帧执行一次
	void Input(Event& e);//输入主函数
	void Input_scene(Event& e);//在场景输入
	void Input_mail(Event& e);//在邮件输入
	void Input_wanfa(Event& e);//在玩法输入
	void Input_fankui(Event& e);//在反馈输入
	void Input_zhanji(Event& e);//在战绩输入
	void Input_store(Event& e);//在商店输入
	void Input_exit(Event& e);//在退出对话框输入
	void draw_mail();//绘制邮件
	void draw_wanfa();//绘制玩法
	void draw_fankui();//绘制反馈
	void draw_zhanji();//绘制战绩
	void draw_store();//绘制商店
	void Draw();//绘制主函数
	void SceneClose();//关闭场景
};

class GameScene: public StartScene //派生出游戏场景类
{
	friend class Game;
public:
	PukeManager puke_manager;//扑克管理器
	Player human;//玩家
	AI ai_1, ai_2;//AI
	Sprite sOver, sShoot, sDealBg, sF, sG, sH, sJ;
	Texture tOver[2], tShoot, tDealBg, tF, tG, tH, tJ;
	Text text_score, text_jb, text_over, text_shoot;
	Button bt_over_back, bt_over_restart;
	Sound sound_get;
	SoundBuffer sb_get;
	int score;
	int elapsTime_shoot;
	int totalTime_shoot;
	Music mu_over;
	MyClock clock_showCall;//出牌倒计时
	Clock clock_shoot;
	bool isPlayed_sd;
	bool isDealing;//是否正在发牌
	bool isDealDizhu;//是否正在叫地主阶段
	bool isPlaying;
	bool isGameover;//有人手牌已全部打出，游戏结束
	bool isShowOver;
	bool isShooted;
	GameScene();
	void Initial(RenderWindow* app);
	void Start();//场景运行前执行一次
	void Update();//场景运行时每帧执行一次
	void Draw();//绘制
	void player_turn_input(Event& e);//玩家轮流出牌和叫地主
	void input_rhythm(Event& e); //节奏模式输入
	void Input(Event& e);//输入
	void SceneClose();//场景关闭
	void Input_exit(Event& e);//退出界面输入
private:
	RenderWindow* app;
};