#pragma once
#include "qtimer.h"
#include "TimeUpdater.h"
class TimeTest : public TimeUpdater
{
public:
	TimeTest()
	{

	}
	// Í¨¹ý TimeUpdater ¼Ì³Ð
	virtual void Update() override;


};

