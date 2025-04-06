#pragma once
#include "qdebug.h"
#include "qlist.h" 
#include "qdir.h"
#include "qfile.h"
#include "qfiledialog.h"
#include "qdatastream.h"
#include "SaveDetails.h"
#include "ISaveable.h"
class LoadManager
{
private:
	QList<ISaveable* > loadTaskList;
	QString dataSavePos = QDir::currentPath() + "/SaveData" + "/Slot";
public:
	LoadManager()
	{

	}

	void ProcessAllLoadTask(int slot_ID)
	{
		//Path Defination
		QString targetSavePath = GetDirBySlotID(slot_ID);
		
		for each (ISaveable * loadTask in loadTaskList)
		{
			loadTask->Load(targetSavePath);
		}
	}

	void RegisterNewLoadTask(ISaveable* loadTask)
	{
		loadTaskList.append(loadTask);
	}

	QString GetDirBySlotID(int slot_ID)
	{
		return dataSavePos + QString::number(slot_ID);
	}

};

