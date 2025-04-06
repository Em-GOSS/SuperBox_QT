#pragma once
#include "qstring.h"
#include "qlist.h"
#include "qfile.h"
#include "qdebug.h"
#include "qdatastream.h"
/// <summary>
/// this interface need to implement the save method
/// </summary>
class ISaveable
{
private:
	

protected:
	QString fileName;	

	//send data to SaveManager
	QMap<int, int>* loadUI_DataMap;
	
public:
	ISaveable(QString fileName)
	{
		this->fileName = fileName;
	}
	
	void Save(QString saveDir)
	{	

		QString savePos = saveDir + "/" + fileName;

		QFile fileToSave(savePos);
			
		if (fileToSave.exists())
		{
			fileToSave.resize(0);

			//Discarded in 2024/5/14
			//should not use the reset method, this will change the files IODevice to the random acess
			//we normal call it RAM_MODE
			//fileToSave.reset();
		}

		fileToSave.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::WriteOnly );

		if (fileToSave.isOpen())
		{
			Saving(&fileToSave);
		}
		else
		{
			qDebug() << QString("OpenFile_Error" + savePos);
		}
		
		fileToSave.close();

	}

	void Load(QString saveDir)
	{
		QString loadPos = saveDir + "/" + fileName;

		QFile fileToLoad(loadPos);

		if (fileToLoad.exists())
		{
			fileToLoad.open(QIODevice::ReadOnly);

			Loading(&fileToLoad);

			fileToLoad.close();
		}
		else
		{
			qDebug("Warning: loadDirectionWrong, there is no such file in this position");
		}
	}

	void MountDataMap_LoadUI(QMap<int, int>* dataMap)
	{
		this->loadUI_DataMap = dataMap;
	}


	virtual void Saving(QFile* fileToSave) = 0;

	virtual void Loading(QFile* fileToLoad) = 0;

	
};

