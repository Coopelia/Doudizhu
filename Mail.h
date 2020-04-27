#pragma once
#include"Def.h"
#include"Button.h"

class Mail
{
public:
	RenderWindow* app;
	Sprite sBack;
	Texture tBack;
	Button bt_ok;
	Text tittle, mes;
	Font font;
	bool isOpened;
	int posX, posY;
	Mail();
	void initial(RenderWindow* app, int x, int y);
	void setText(String tittle, String mes);
	void show();
};