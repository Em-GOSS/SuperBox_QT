#pragma once
#include "qlist.h"
class TimeUpdater 
{	
public:
	bool isUpdating = true;

	void TimeUpdater::StartUpdate()
	{
		isUpdating = true;
	}

	void TimeUpdater::StopUpdate()
	{
		isUpdating = false;
	}	

	virtual void Update()
	{

	}
	
};

