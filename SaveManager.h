#pragma once
#include "qdebug.h"
#include "qlist.h" 
#include "qdir.h"
#include "qfile.h"
#include "qfiledialog.h"
#include "qdatastream.h"
#include "SaveDetails.h"
#include "ISaveable.h"
#include "Setting.h"

class SaveManager
{
private:
	QList<ISaveable* > saveTaskList;
	QString dataSavePos = QDir::currentPath() + "/SaveData" + "/Slot";
	QList<QString> dataSaveHeaders;

	QString LoadUIDataName = "/LoadUIData.dat";

	//given 6 slot to store
	QMap<int, int> loadUI_DataMap;

	void InitStream(QDataStream &dataStream)
	{
		dataStream.setVersion(QDataStream::Qt_5_0);	
		dataStream.setByteOrder(QDataStream::LittleEndian);
	}

	void save_LoadUIData(int slot_ID)
	{	
		qDebug("LoadUIData Saving");

		QString UIDataSavePos = GetDirBySlotID(slot_ID) + LoadUIDataName;
		
		QDir saveDir(UIDataSavePos);
		
		QFile loadUI_SaveFile(UIDataSavePos);
		if (loadUI_SaveFile.exists())
		{	
			//clear origin data
			loadUI_SaveFile.resize(0);
		}
		QDataStream dataStream(&loadUI_SaveFile);

		InitStream(dataStream);

		loadUI_SaveFile.open(QIODevice::Append | QIODevice::ReadWrite | QIODevice::Text);

		dataStream << loadUI_DataMap.size();
		qDebug() << qint16(loadUI_DataMap.size());

		for (int i = 1; i <= 6; i++)
		{
			dataStream << loadUI_DataMap.value(i);
		}
		loadUI_SaveFile.close();

	}

	//Log
	void InitHeader()
	{	
		//UIData
		dataSaveHeaders.append("ATK: ");
		dataSaveHeaders.append("DEF: ");
		dataSaveHeaders.append("HP: ");
		dataSaveHeaders.append("ItemCount: ");
		dataSaveHeaders.append("BulletCount: ");
		dataSaveHeaders.append("EnemyIndex: ");

		//HidenData
		dataSaveHeaders.append("CurrentBulletIndex: ");
		dataSaveHeaders.append("playerBulletStore: ");

	}
public:
	SaveManager()
	{
		InitHeader();
	}

	void InitPath(QString targetPath)
	{
		QDir makePathDir(targetPath);
		if (makePathDir.exists())
		{	
			return;
		}
		else
		{
			makePathDir.mkpath(targetPath);
		}		
	}

	void ProcessAllSaveTask(int slot_ID)
	{	
		//Path Defination
		QString targetSavePath = GetDirBySlotID(slot_ID);
		InitPath(targetSavePath);

		for each (ISaveable* saveTask in saveTaskList)
		{
			saveTask->Save(targetSavePath);
		}

		save_LoadUIData(slot_ID);
	}

	void RegisterNewSaveTask(ISaveable* saveTask)
	{
		saveTaskList.append(saveTask);
	}

	QString GetDirBySlotID(int slot_ID)
	{
		return dataSavePos + QString::number(slot_ID);
	}

	void MountExtraDataToSaveTasks()
	{
		for (int i = 0; i < saveTaskList.count(); i++)
		{
			saveTaskList[i]->MountDataMap_LoadUI(&loadUI_DataMap);
		}
	}
};

