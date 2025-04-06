#pragma once
#include "Enums.h"
#include "qdebug.h"
#include "qstring.h"
class BulletDetails
{
public:
	int level = -1;
	BulletType bulletType = BulletType::Energy;

	BulletDetails()
	{	
		//Do Nothing
	}
	BulletDetails(BulletType bType, int level)
	{
		this->bulletType = bType;
		this->level = level;
	}
	
	/// <summary>
	/// return true if LevelUp task is Successful
	/// </summary>
	/// <returns></returns>
	bool LevelUP()
	{
		if (!isMaxLevel())
		{
			level++;
			qDebug() << "LevelUP!!!" << qint32(bulletType)<< qint16(level)<<endl;
			return true;
		}
		else
		{
			return false;
		}
	}
	
	bool isMaxLevel()
	{	
		//Poision Bullet has no level Boundary
		if (bulletType == BulletType::Poision)
			return false;

		if (level >= 10)
			return true;
		else
			return false;
	}
};

