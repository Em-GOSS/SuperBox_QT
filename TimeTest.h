#pragma once
#include "qtimer.h"
#include "TimeUpdater.h"
class TimeTest : public TimeUpdater
{
public:
	TimeTest()
	{

	}
	// ͨ�� TimeUpdater �̳�
	virtual void Update() override;


};

