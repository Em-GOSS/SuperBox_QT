#pragma once
#include "qdebug.h"
#include "qstring.h"
class CodeCreater
{
public:
	static void CreateAppendWork(QString keyPrefix, int createCount, QString fileType)
	{
		for (int i = 1; i <= createCount; i++)
		{
			qDebug() << QString(keyPrefix + QString::number(i) + "." + fileType);
		}
	}

};

