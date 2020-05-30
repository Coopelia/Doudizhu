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
	Sprite sBackground; //����
	Sprite sBack_menu;//�˵�����
	Texture tBackground1, tBackground2, tBackground3;
	Texture tBack_menu;
	Font font;//����
	bool isRunning;//�Ƿ��ڵ�ǰ����
	bool isExit;//�Ƿ��뿪��ǰ����
	StartScene();
	//���ò˵�
	bool isOnSetting;
	Sprite sBack_setting, sBackMini;
	Texture tBack_setting;
	Button bt_setting_ok, bt_bgm_left, bt_bgm_right, bt_sound_left, bt_sound_right, bt_bg_left, bt_bg_right, bt_rhythm_left, bt_rhythm_right;
	Text text_bgm, text_sound, text_rhythm;
	//�˳��Ի���
	bool isOnExit;
	Sprite sBack_exit;
	Texture tBack_exit;
	Button bt_exit_ok, bt_exit_cancel;
	//��Ӧ������ͻ��ƺ���
	void Input_setting(Event& e);
	void draw_setting(RenderWindow* app);
	void draw_exit(RenderWindow* app);
private:
	Button bt_Enter, bt_join, bt_creat, bt_fankui, bt_store, bt_wanfa, bt_mail, bt_zhanji;
	Sprite sMeinv, sBackUser, sUserHead, sJf, sRankList;
	Texture tMeinv, tBackUser, tUserHead, tJf, tRankList;
	Text text_jb;
	//�ʼ��˵�
	bool isOnMail;
	int num_mail;
	Sprite sBack_mail, sRedPoint;
	Texture tBack_mail, tRedPoint;
	Button bt_mail_close;
	Mail mail;
	//�淨�˵�
	bool isOnWanfa;
	Sprite sBack_wanfa;
	Texture tBack_wanfa;
	Button bt_wanfa_ok;
	//�����˵�
	bool isOnFankui;
	Sprite sBack_fankui;
	Texture tBack_fankui;
	Button bt_fankui_close;
	//ս���˵�
	bool isOnZhanji;
	Sprite sBack_zhanji;
	Texture tBack_zhanji;
	Button bt_zhanji_close;
	//�̵�˵�
	bool isOnStore;
	Sprite sBack_store;
	Texture tBack_store;
	Button bt_store_close;

	RenderWindow* app;//�����
	int value_bg;//������������
	void Initial(RenderWindow* app);//�󶨻����
	void Start();//���볡��ʱִ��һ��
	void Update();//���볡����ûִ֡��һ��
	void Input(Event& e);//����������
	void Input_scene(Event& e);//�ڳ�������
	void Input_mail(Event& e);//���ʼ�����
	void Input_wanfa(Event& e);//���淨����
	void Input_fankui(Event& e);//�ڷ�������
	void Input_zhanji(Event& e);//��ս������
	void Input_store(Event& e);//���̵�����
	void Input_exit(Event& e);//���˳��Ի�������
	void draw_mail();//�����ʼ�
	void draw_wanfa();//�����淨
	void draw_fankui();//���Ʒ���
	void draw_zhanji();//����ս��
	void draw_store();//�����̵�
	void Draw();//����������
	void SceneClose();//�رճ���
};

class GameScene: public StartScene //��������Ϸ������
{
	friend class Game;
public:
	PukeManager puke_manager;//�˿˹�����
	Player human;//���
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
	MyClock clock_showCall;//���Ƶ���ʱ
	Clock clock_shoot;
	bool isPlayed_sd;
	bool isDealing;//�Ƿ����ڷ���
	bool isDealDizhu;//�Ƿ����ڽе����׶�
	bool isPlaying;
	bool isGameover;//����������ȫ���������Ϸ����
	bool isShowOver;
	bool isShooted;
	GameScene();
	void Initial(RenderWindow* app);
	void Start();//��������ǰִ��һ��
	void Update();//��������ʱÿִ֡��һ��
	void Draw();//����
	void player_turn_input(Event& e);//����������ƺͽе���
	void input_rhythm(Event& e); //����ģʽ����
	void Input(Event& e);//����
	void SceneClose();//�����ر�
	void Input_exit(Event& e);//�˳���������
private:
	RenderWindow* app;
};