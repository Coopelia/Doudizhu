#pragma once
#include"Def.h"

class Button
{
	friend class Game;
	friend class StartScene;
	friend class GameScene;
	friend class Menu;
	friend class Mail;
	friend class Player;
public:
	Button();
	bool PreBehRel;   //防止鼠标在按钮外面按住然后移到按钮上松开触发点击事件
	void setTextrue(String s);
	void setPosition(int x, int y);
	void setScale(float x, float y);
	void show();
	bool onClick(Event& e);
	Sprite s;
	Sound fx;
	SoundBuffer sbfx;
private:
	Texture t;
	RenderWindow* app;
};