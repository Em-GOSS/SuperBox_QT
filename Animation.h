#pragma once
#include "qstring.h"
#include "qlist.h"
/// <summary>
/// Warning: this class only use for read
/// Create as a Data Store
/// </summary>
class Animation
{
public:
	QList<QString> ani_Sheets;
	int ani_Count = NULL;
	int ani_Interval = NULL;

	Animation(QList<QString> sheets, int aniCount, int aniInterval)
	{
		this->ani_Sheets = sheets;
		this->ani_Count = aniCount;
		this->ani_Interval = aniInterval;
	}
	Animation()
	{

	}

	int GetTotalTicks()
	{
		return ani_Count * ani_Interval;
	}
};

