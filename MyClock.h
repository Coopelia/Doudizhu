#pragma once
#include"Def.h"

class MyClock
{
public:
	int hour;
	int minute;
	int second;
	float minTime;//×ÜÊ±¼ä(ms)
	float elapsedTime;
	bool isRun;
	clock_t beginTime, endTime;
	MyClock();
	void update();
	void start();
	void stop();
	void restart();
};