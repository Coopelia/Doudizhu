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
	bool isSeleted; //�Ƿ�ѡ��
	bool isOnTop;//������
	bool isPressed;//�Ƿ񱻰���
	bool isOnDesk;//�Ƿ��ڳ�����
	bool isDeleted;//�Ƿ��ѱ�����
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

