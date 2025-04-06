#pragma once
#include "qfontdatabase.h"
#include "qcoreapplication.h"
#include "qdebug.h"
#include "qfont.h"

class MiscSettingsImporter
{
private:
	//Here is Created to load Data
	void CustomFontImport()
	{		
		int id;
		id = QFontDatabase::addApplicationFont("C:/Users/86137/source/repos/SuperBox/font/pixel-number.ttf");
		if (id == -1)
		{
			qDebug("Warning :: ErrorFont Pos");
		}
	}
public:
	MiscSettingsImporter()
	{
		CustomFontImport();
	}
};

