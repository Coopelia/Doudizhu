#include "Button.h"

Button::Button()
{
	this->app = NULL;
	this->PreBehRel = false;
	this->sbfx.loadFromFile("assets/Sound/Special/SpecOk.ogg");
	this->fx.setBuffer(sbfx);
}

void Button::setTextrue(String s)
{
	this->t.loadFromFile(s);
	this->s.setTexture(this->t);
}

void Button::setPosition(int x, int y)
{
	this->s.setPosition(x, y);
}

void Button::setScale(float x, float y)
{
	this->s.setScale(x, y);
}

bool Button::onClick(Event& e)
{
	bool flag = false;
	FloatRect box = s.getGlobalBounds();
	if (Mouse::getPosition(*app).x >= box.left && Mouse::getPosition(*app).x <= (box.left + box.width) && Mouse::getPosition(*app).y >= box.top && Mouse::getPosition(*app).y <= (box.top + box.height))
	{
		if (e.type == Event::MouseButtonReleased && e.key.code == Mouse::Left && PreBehRel)
		{
			this->PreBehRel = false;
			flag = true;
			this->fx.setVolume(vol_sound);
			this->fx.play();
		}
		else
			flag = false;
		if (e.type == Event::MouseButtonPressed && e.key.code == Mouse::Left)
		{
			this->s.setColor(Color(125, 125, 0, 255));
			this->PreBehRel = true;
		}
		else
			this->s.setColor(Color(125, 125, 125, 255));
	}
	else
		this->s.setColor(Color(255,255,255, 255));
	return flag;
}

void Button::show()
{
	(*app).draw(s);
}