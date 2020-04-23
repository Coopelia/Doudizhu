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
	Button bt_setting, bt_exit;//���ð�ť���˳�
	Sprite sBackground;
	Sprite sBack_menu;
	Texture tBackground1, tBackground2, tBackground3;
	Texture tBack_menu;
	Font font;
	bool isRunning;//�Ƿ��ڵ�ǰ����
	bool isExit;//�Ƿ��뿪��ǰ����
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
	PukeManager puke_manager;//�˿˹�����
	Player human;//���
	AI ai_1, ai_2;//AI
	Sprite sOver;
	Texture tOver[2];
	MyClock clock_showCall;//���Ƶ���ʱ
	bool isDealing;//�Ƿ����ڷ���
	bool isDealDizhu;//�Ƿ����ڽе����׶�
	bool isPlaying;
	bool isGameover;//����������ȫ���������Ϸ����
	GameScene();
	void Initial(RenderWindow* app);
	void Start();//��������ǰִ��һ��
	void Update();//��������ʱÿִ֡��һ��
	void Draw();//����
	void player_turn_input(Event& e);//����������ƺͽе���
	void Input(Event& e);//����
	void SceneClose();//�����ر�
private:
	RenderWindow* app;
};