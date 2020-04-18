#include"MyClock.h"

MyClock::MyClock()
{
	hour = 0;
	minute = 0;
	second = 0;
	minTime = 0;
	this->endTime = 0;
	this->beginTime = 0;
	this->elapsedTime = 0;
	this->isRun = false;
}

void MyClock::stop()
{
	hour = 0;
	minute = 0;
	second = 0;
	minTime = 0;
	this->endTime = 0;
	this->beginTime = 0;
	this->elapsedTime = 0;
	this->isRun = false;
}

void MyClock::start()
{
	this->beginTime = clock();
	this->isRun = true;
}

void MyClock::restart()
{
	this->stop();
	this->start();
}

void MyClock::update()
{
	this->endTime = clock();
	if (this->isRun)
	{
		this->minTime += (this->endTime - this->beginTime);
		this->elapsedTime += (this->endTime - this->beginTime);
		this->second = elapsedTime / 1000;
		if (this->second == 60)
		{
			this->beginTime = this->endTime;
			this->elapsedTime = 0;
			this->minute++;
		}
		if (this->minute == 60)
		{
			this->minute = 0;
			this->hour++;
		}
	}
	this->beginTime = this->endTime;
}