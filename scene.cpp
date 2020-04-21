#include"scene.h"

StartScene::StartScene()
{
	this->app = NULL;
	isRunning = false;
	isExit = false;
	tBackground.loadFromFile("assets/image/game/背景/背景1.jpg");
	sBackground.setTexture(tBackground);
	tBack_menu.loadFromFile("assets/image/game/大厅/菜单-底.png");
	sBack_menu.setTexture(tBack_menu);
	tMeinv.loadFromFile("assets/image/game/大幅/角色.png");
	sMeinv.setTexture(tMeinv);
	tBackUser.loadFromFile("assets/image/game/大厅/用户栏-底.png");
	sBackUser.setTexture(tBackUser);
	tUserHead.loadFromFile("assets/image/game/大厅/用户栏-默认头像.png");
	sUserHead.setTexture(tUserHead);
	tJf.loadFromFile("assets/image/game/大厅/用户栏-金币.png");
	sJf.setTexture(tJf);
	tRankList.loadFromFile("assets/image/game/大厅/排行榜.png");
	sRankList.setTexture(tRankList);
	bt_Enter.setTextrue("assets/image/game/大厅/房间入口-斗地主.png");
	bt_creat.setTextrue("assets/image/game/大厅/房间入口-创建.png");
	bt_join.setTextrue("assets/image/game/大厅/房间入口-加入.png");
	bt_setting.setTextrue("assets/image/game/大厅/菜单-设置.png");
	bt_exit.setTextrue("assets/image/game/大厅/leave_btn0.png");
	bt_fankui.setTextrue("assets/image/game/大厅/菜单-反馈.png");
	bt_mail.setTextrue("assets/image/game/大厅/菜单-邮件.png");
	bt_store.setTextrue("assets/image/game/大厅/菜单-商城.png");
	bt_wanfa.setTextrue("assets/image/game/大厅/菜单-玩法.png");
	bt_zhanji.setTextrue("assets/image/game/大厅/菜单-战绩.png");
	bgm.openFromFile("assets/Sound/MusicEx/MusicEx_Welcome.ogg");
	bgm.setLoop(true);
}

void StartScene::Initial(RenderWindow* app)
{
	this->app = app;
	this->bt_Enter.app = app;
	this->bt_creat.app = app;
	this->bt_join.app = app;
	this->bt_exit.app = app;
	this->bt_fankui.app = app;
	this->bt_mail.app = app;
	this->bt_setting.app = app;
	this->bt_store.app = app;
	this->bt_wanfa.app = app;
	this->bt_zhanji.app = app;
}

void StartScene::Start()
{
	bgm.setVolume(vol);
	bgm.play();
	isRunning = true;
}

void StartScene::Update()
{
	this->bgm.setVolume(vol);
}

void StartScene::Draw()
{
	sBackground.setPosition(0, 0);
	sBack_menu.setPosition(25, 675);
	sMeinv.setPosition(450, 80);
	sBackUser.setPosition(0, 0);
	sUserHead.setPosition(5,5);
	sJf.setPosition(100, 25);
	sRankList.setPosition(50, 100);
	(*app).draw(sBackground);
	(*app).draw(sMeinv);
	(*app).draw(sBackUser);
	(*app).draw(sUserHead);
	(*app).draw(sJf);
	(*app).draw(sRankList);
	(*app).draw(sBack_menu);
	bt_Enter.setPosition(865, 100);
	bt_join.setPosition(820, 243);
	bt_creat.setPosition(820, 400);
	bt_store.setPosition(130, 610);
	bt_setting.setPosition(320, 622);
	bt_mail.setPosition(480, 630);
	bt_wanfa.setPosition(640, 625);
	bt_fankui.setPosition(800, 627);
	bt_zhanji.setPosition(960, 623);
	bt_exit.setPosition(1120, 640);
	bt_Enter.show();
	bt_creat.show();
	bt_join.show();
	bt_exit.show();
	bt_fankui.show();
	bt_mail.show();
	bt_setting.show();
	bt_store.show();
	bt_wanfa.show();
	bt_zhanji.show();
	//menu_setting.show();
	//menu_exit.show();
}

void StartScene::Input(Event& e)
{
	if (bt_Enter.onClick(e))
		this->isExit = true;
}

void StartScene::SceneClose()
{
	bgm.stop();
	isRunning = false;
}

GameScene::GameScene()
{
	this->app = NULL;
	isRunning = false;
	isExit = false;
	isDealing = false;
	isDealDizhu = false;
	isPlaying = false;
	isGameover = false;
	puke_manager.human = &this->human;
	puke_manager.ai_1 = &this->ai_1;
	puke_manager.ai_2 = &this->ai_2;
	tBackground.loadFromFile("assets/image/game/房间/room_bg.png");
	sBackground.setTexture(tBackground);
	tOver[0].loadFromFile("assets/image/game/斗地主结算/切图/你赢了.png");
	tOver[1].loadFromFile("assets/image/game/斗地主结算/切图/你输了.png");
	sOver.setPosition(363, 267);
	bgm.openFromFile("assets/Sound/MusicEx/MusicEx_Normal.ogg");
	bgm.setLoop(true);
}

void GameScene::Initial(RenderWindow* app)
{
	this->app = app;
	this->human.Initial(app);
	this->ai_1.Initial(app);
	this->ai_2.Initial(app);
}

void GameScene::Start()
{
	bgm.setVolume(vol);
	bgm.play();
	isRunning = true;
	isDealing = true;
	isDealDizhu = false;
}

void GameScene::Update()
{
	this->bgm.setVolume(vol);
	puke_manager.update();
	human.update();
	ai_1.update();
	ai_2.update();
	if (isDealing)
	{
		if (puke_manager.clock_deal.isRun==false)
		{
			puke_manager.clearAll();
			puke_manager.clock_deal.start();
		}
		puke_manager.clock_deal.update();
		if (puke_manager.num_temp > 3)
		{
			if (puke_manager.clock_deal.minTime >= 300)
			{
				puke_manager.deal();
				puke_manager.clock_deal.restart();
			}
		}
		else
		{
			puke_manager.clock_deal.stop();
			isDealing = false;
			isDealDizhu = true;
			human.isCallingDizhu = true;
		}
	}
	if (isPlaying)
	{
		if (human.num_card == 0 || ai_1.num_card == 0 || ai_2.num_card == 0)
			isGameover = true;
	}
	if (isGameover)
	{
		if (human.sid==DIZHU)
		{
			if (human.num_card == 0)
			{
				sOver.setTexture(tOver[0]);
				human.isWin = true;
				ai_1.isWin = false;
				ai_2.isWin = false;
			}
			else
			{
				sOver.setTexture(tOver[1]);
				human.isWin = false;
				ai_1.isWin = true;
				ai_2.isWin = true;
			}
		}
		else
		{
			if (ai_1.sid == DIZHU)
			{
				if (ai_1.num_card == 0)
				{
					sOver.setTexture(tOver[1]);
					human.isWin = false;
					ai_1.isWin = true;
					ai_2.isWin = false;
				}
				else
				{
					sOver.setTexture(tOver[0]);
					human.isWin = true;
					ai_1.isWin = false;
					ai_2.isWin = true;
				}
			}
			else
			{
				if (ai_2.num_card == 0)
				{
					sOver.setTexture(tOver[1]);
					human.isWin = false;
					ai_1.isWin = false;
					ai_2.isWin = true;
				}
				else
				{
					sOver.setTexture(tOver[0]);
					human.isWin = true;
					ai_1.isWin = true;
					ai_2.isWin = false;
				}
			}
		}
	}
}

void GameScene::Draw()
{
	sBackground.setPosition(0, 0);
	human.setPosition(34, 625);
	human.tNum_rest.setPosition(110, 645);
	ai_1.setPosition(1120, 200);
	ai_2.setPosition(85, 200);
	(*app).draw(sBackground);
	human.show();
	(*app).draw(human.tNum_rest);
	ai_1.show();
	ai_2.show();
	puke_manager.puke.Back.setPosition(182, 150);
	puke_manager.puke.Back.setScale(0.4, 0.4);
	ai_1.tNum_rest.setPosition(1038, 290);
	(*app).draw(puke_manager.puke.Back);
	(*app).draw(ai_1.tNum_rest);
	puke_manager.puke.Back.setPosition(1010, 150);
	puke_manager.puke.Back.setScale(0.4, 0.4);
	ai_2.tNum_rest.setPosition(210, 290);
	(*app).draw(puke_manager.puke.Back);
	(*app).draw(ai_2.tNum_rest);
	if (isDealDizhu)
	{
		human.sCall.setPosition(610, 430);
		human.sCall.setScale(1.5, 1.5);
		ai_1.sCall.setPosition(905, 150);
		ai_1.sCall.setScale(1.5, 1.5);
		ai_2.sCall.setPosition(300, 150);
		ai_2.sCall.setScale(1.5, 1.5);
		(*app).draw(human.sCall);
		(*app).draw(ai_1.sCall);
		(*app).draw(ai_2.sCall);
	}
	//绘制玩家扑克牌
	for (int i = 0; i < human.num_card; i++)
	{
		int k = human.hand_card[i] / 4;
		int l = human.hand_card[i] % 4;
		puke_manager.puke.c[k][l].sprite.setScale(0.7, 0.7);
		(*app).draw(puke_manager.puke.c[k][l].sprite);
	}
	//绘制出牌区
	for (int i = 0; i < puke_manager.num_desk; i++)
	{
		int k = puke_manager.deskCard[i] / 4;
		int l = puke_manager.deskCard[i] % 4;
		puke_manager.puke.c[k][l].sprite.setScale(0.6, 0.6);
		(*app).draw(puke_manager.puke.c[k][l].sprite);
	}
	//过
	if (human.dec == PASS)
	{
		human.sNoCard.setPosition(610, 430);
		(*app).draw(human.sNoCard);
	}
	if (ai_1.dec == PASS)
	{
		ai_1.sNoCard.setPosition(905, 150);
		(*app).draw(ai_1.sNoCard);
	}
	if (ai_2.dec == PASS)
	{
		ai_2.sNoCard.setPosition(300, 150);
		(*app).draw(ai_2.sNoCard);
	}
	//画倒计时
	if (human.isMyTime)
	{
		human.sClock.setPosition(615, 370);
		human.tDaojishi.setPosition(649, 402);
		(*app).draw(human.sClock);
		(*app).draw(human.tDaojishi);
	}
	if (ai_1.isMyTime)
	{
		ai_1.sClock.setPosition(897, 165);
		ai_1.tDaojishi.setPosition(930, 197);
		(*app).draw(ai_1.sClock);
		(*app).draw(ai_1.tDaojishi);
	}
	if (ai_2.isMyTime)
	{
		ai_2.sClock.setPosition(275, 165);
		ai_2.tDaojishi.setPosition(309, 197);
		(*app).draw(ai_2.sClock);
		(*app).draw(ai_2.tDaojishi);
	}
	//画地主牌
	if (isDealDizhu)
	{
		puke_manager.puke.Back.setPosition(550, 10);
		puke_manager.puke.Back.setScale(0.3, 0.3);
		(*app).draw(puke_manager.puke.Back);
		puke_manager.puke.Back.setPosition(615, 10);
		puke_manager.puke.Back.setScale(0.3, 0.3);
		(*app).draw(puke_manager.puke.Back);
		puke_manager.puke.Back.setPosition(680, 10);
		puke_manager.puke.Back.setScale(0.3, 0.3);
		(*app).draw(puke_manager.puke.Back);
	}
	else if(!isDealDizhu&&!isDealing)
	{
		puke_manager.sDizhuCard[0].sprite.setPosition(550, 10);
		puke_manager.sDizhuCard[0].sprite.setScale(0.5, 0.5);
		puke_manager.sDizhuCard[1].sprite.setPosition(615, 10);
		puke_manager.sDizhuCard[1].sprite.setScale(0.5, 0.5);
		puke_manager.sDizhuCard[2].sprite.setPosition(680, 10);
		puke_manager.sDizhuCard[2].sprite.setScale(0.5, 0.5);
		(*app).draw(puke_manager.sDizhuCard[0].sprite);
		(*app).draw(puke_manager.sDizhuCard[1].sprite);
		(*app).draw(puke_manager.sDizhuCard[2].sprite);
	}
	if (isGameover)
		(*app).draw(sOver);
}

void GameScene::player_turn_input(Event& e)
{
	//叫地主阶段
	if (isDealDizhu)
	{
		if(human.isCallingDizhu&&human.s_call==-1)
			human.callDizhu(e);
		if (human.s_call != -1)
			ai_1.isCallingDizhu = true;
		if (ai_1.isCallingDizhu&&ai_1.s_call==-1)
			ai_1.callDizhu();
		if (ai_1.s_call != -1)
			ai_2.isCallingDizhu = true;
		if (ai_2.isCallingDizhu&&ai_2.s_call==-1)
			ai_2.callDizhu();
		if (human.s_call != -1 && ai_1.s_call != -1 && ai_2.s_call != -1)
		{
			if (human.s_call == 0 && ai_1.s_call == 0 && ai_2.s_call == 0)
			{
				isDealing = true;
				isDealDizhu = false;
				human.s_call = -1;
				ai_1.s_call = -1;
				ai_2.s_call = -1;
			}
			else
			{
				if (human.s_call >= ai_1.s_call && human.s_call >= ai_2.s_call)
				{
					human.sid = DIZHU;
					ai_1.sid = NONM;
					ai_2.sid = NONM;
				}
				else if (ai_1.s_call >= human.s_call && ai_1.s_call >= ai_2.s_call)
				{
					ai_1.sid = DIZHU;
					human.sid = NONM;
					ai_2.sid = NONM;
				}
				else if (ai_2.s_call >= human.s_call && ai_2.s_call >= ai_1.s_call)
				{
					ai_2.sid = DIZHU;
					human.sid = NONM;
					ai_1.sid = NONM;
				}
				if (!clock_showCall.isRun)
					clock_showCall.start();
				clock_showCall.update();
				if (clock_showCall.second >= 1)
				{
					clock_showCall.stop();
					isDealDizhu = false;
					isPlaying = true;
					puke_manager.deal_dizhuCard();
				}
			}
		}
	}
	//出牌阶段
	if (human.isMyTime)
	{
		if (!human.clock_daojishi.isRun)
			human.clock_daojishi.start();
		human.clock_daojishi.update();
		human.tDaojishi.setString(std::to_string(30 - human.clock_daojishi.second));
		human.dec = NOT;
		if (human.bt_chupai.onClick(e))
		{
			for (int i = 0; i < 14; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (puke_manager.puke.c[i][j].isSeleted)
					{
						puke_manager.addToJudge(i, j);
					}
				}
			}
			puke_manager.JudgeCard(human);
			if (human.dec != NOT)
			{
				ai_1.isMyTime = true;
				human.clock_daojishi.stop();
			}
		}
		else if (human.bt_pass.onClick(e))
		{
			human.dec = PASS;
			human.isMyTime = false;
			ai_1.isMyTime = true;
			human.clock_daojishi.stop();
		}
	}
	else if (ai_1.isMyTime)
	{
		puke_manager.autoSeleteCard(&ai_1);
		if(!ai_1.isMyTime)
			ai_2.isMyTime = true;
	}
	else if (ai_2.isMyTime)
	{
		puke_manager.autoSeleteCard(&ai_2);
		if(!ai_2.isMyTime)
			human.isMyTime = true;
	}
}

void GameScene::Input(Event& e)
{
	if (!isGameover)
	{
		if (e.type == Event::MouseButtonPressed && e.key.code == Mouse::Left)
		{
			mouseRect.isMousePressed = true;
			px1 = Mouse::getPosition(*app).x;
			py1 = Mouse::getPosition(*app).y;
		}
		if (mouseRect.isMousePressed)
		{
			px2 = Mouse::getPosition(*app).x;
			py2 = Mouse::getPosition(*app).y;
		}
		if (e.type == Event::MouseButtonReleased && e.key.code == Mouse::Left)
			mouseRect.isMousePressed = false;
		for (int i = 0; i < 14; i++)
			for (int j = 0; j < 4; j++)
				puke_manager.puke.c[i][j].onClick(e);
		player_turn_input(e);
	}
}

void GameScene::SceneClose()
{
	bgm.stop();
	isRunning = false;
}