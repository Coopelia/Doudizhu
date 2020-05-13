#pragma once
#include"Def.h"

typedef struct Pos
{
	int x;
	int y;
	Pos() :x(0), y(0) {};
}Pos;

typedef struct Scale
{
	float x;
	float y;
	Scale() :x(0.5), y(0.5) {};
}Scale;

typedef struct Speed
{
	float x;
	float y;
	Speed() :x(0), y(0) {};
}Speed;

class GunCharm
{
public:
	GunCharm();
	void start();
	void updata();
	void clear();
	Pos puke_pos[20];
	Speed speed_mov[20];
	Speed acc[20];
	float speed_sca[20];
	float puke_scale[20];
	int num;
	Clock clock_mov, clock_spe;
	float elapsTime_mov, elapsTime_spe;
};