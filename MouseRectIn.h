#pragma once
#include"Def.h"

class MouseRectIn
{
public:
	bool isMousePressed;
	MouseRectIn();
	bool isRectIn(int x01, int x02, int y01, int y02, int x11, int x12, int y11, int y12);
};
extern MouseRectIn mouseRect;