#include"Menu.h"

Menu::Menu()
{
	this->app = NULL;
	this->posX = 0;
	this->posY = 0;
	this->num_button = 0;
	this->num_text = 0;
	this->num_sprite = 0;
	this->font.loadFromFile("assets/fonts/fSimpleRound.ttf");
}

void Menu::setBack(String s)
{
	this->tBack.loadFromFile(s);
	this->sBack.setTexture(this->tBack);
}

void Menu::setPosition(int x, int y)
{
	this->sBack.setPosition(x, y);
	this->posX = x;
	this->posY = y;
}

void Menu::addButton(String s, int posX, int posY, float scaleX, float scaleY)
{
	this->button[this->num_button].setTextrue(s);
	this->button[this->num_button].setPosition(posX, posY);
	this->button[this->num_button].setScale(scaleX, scaleY);
	this->button[this->num_button].app = this->app;
	this->num_button++;
}

void Menu::addText(String s, int posX, int posY, int size, Color color)
{
	this->text[this->num_text].setFont(this->font);
	this->text[this->num_text].setString(s);
	this->text[this->num_text].setPosition(posX, posY);
	this->text[this->num_text].setCharacterSize(size);
	this->text[this->num_text].setFillColor(color);
	this->num_text++;
}

void Menu::addSprite(String s, int posX, int posY, float scaleX, float scaleY)
{
	this->texture[this->num_sprite].loadFromFile(s);
	this->sprite[this->num_sprite].setTexture(this->texture[this->num_sprite]);
	this->sprite[this->num_sprite].setScale(scaleX, scaleY);
	this->sprite[this->num_sprite].setPosition(posX, posY);
	this->num_sprite++;
}

void Menu::show()
{
	(*app).draw(this->sBack);
	for (int i = 0; i < this->num_button; i++)
	{
		this->button[i].show();
	}
	for (int i = 0; i < this->num_text; i++)
	{
		(*app).draw(this->text[i]);
	}
}
