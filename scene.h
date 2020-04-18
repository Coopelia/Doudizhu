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
	Menu menu_setting, menu_exit;//���á��˳��Ի���
	Music bgm;
	Button bt_setting, bt_exit;//���ð�ť���˳���ť
	Sprite sBackground;
	Texture tBackground;
	bool isRunning;//�Ƿ��ڵ�ǰ����
	bool isExit;//�Ƿ��뿪��ǰ����
	StartScene();
private:
	Button bt_Enter, bt_RankList;//
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