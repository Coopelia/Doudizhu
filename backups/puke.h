#include"Def.h"
#include"MouseRectIn.h"
#pragma once

class Card
{
public:
	Card();
	RenderWindow* app;
	Sprite sprite;
	int dt_e;
	bool isSeleted; //是否被选中
	bool isOnTop;//最大的牌
	bool isPressed;//是否被按下
	bool isOnDesk;//是否在出牌区
	bool isDeleted;//是否已被出掉
	void onClick(Event& e);
};

class Puke
{
public:
	bool isMousePressed;
	int px1, py1, px2, py2;
	int size_x;
	int size_y;
	float scale;
	Sprite Back;
	Card c[14][4];
	Puke();
private:
	Texture t[14][4];
	Texture tBack;
};

