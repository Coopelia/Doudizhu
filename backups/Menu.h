#pragma once
#include"Button.h"

class Menu
{
public:
	int posX, posY;
	int num_button;
	int num_text;
	int num_sprite;
	bool isOpen;
	Button button[20];
	Text text[20];
	Sprite sprite[20];
	Texture texture[20];
	Sprite sBack;
	Texture tBack;
	Font font;
	RenderWindow* app;
	Menu();
	void setPosition(int x, int y);
	void setBack(String s);
	void addButton(String s, int posX, int posY, float scaleX, float scaleY);
	void addText(String s, int posX, int posY, int size, Color color);
	void addSprite(String s, int posX, int posY, float scaleX, float scaleY);
	void logic();
	void show();
};

typedef struct MenuNode
{
	Menu self;
	MenuNode* parent;
	MenuNode* child;
	int num_child = 1;
}MenuNode, * MenuLink;

class MenuTree
{
	friend class StartScene;
	friend class GameScene;
	friend class Game;
public:
	MenuLink head;
	MenuLink first;
	MenuLink p;
	MenuTree();
	~MenuTree();
	void addMenu(Menu);
	void Traverse(MenuLink M);
	void Show();
};
