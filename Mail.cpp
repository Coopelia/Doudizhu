#include "Mail.h"

Mail::Mail()
{
	font.loadFromFile("assets/fonts/fSimpleRound.ttf");
	tBack.loadFromFile("assets/image/game/大幅/大厅弹窗/邮件/mail_base.png");
	sBack.setTexture(tBack);
	bt_ok.setTextrue("assets/image/game/大厅弹框/#按钮/确定.png");
}

void Mail::initial(RenderWindow* app, int x, int y)
{
	this->app = app;
	bt_ok.app = app;
	isOpened = false;
	posX = x, posY = y;
	bt_ok.setScale(0.7, 0.7);
	bt_ok.setPosition(posX + 650, posY + 128);
	this->sBack.setPosition(posX, posY);
	this->tittle.setPosition(posX + 100, posY + 10);
	this->mes.setPosition(posX + 12, posY + 60);
}

void Mail::setText(String tittle, String mes)
{
	this->tittle.setString(tittle);
	this->tittle.setCharacterSize(36);
	this->tittle.setFillColor(Color::Blue);
	this->tittle.setFont(font);
	this->mes.setString(mes);
	this->mes.setCharacterSize(42);
	this->mes.setFillColor(Color::Black);
	this->mes.setFont(font);
}

void Mail::show()
{
	(*app).draw(sBack);
	(*app).draw(tittle);
	(*app).draw(mes);
	bt_ok.show();
}