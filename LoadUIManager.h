#pragma once
#include "qgraphicsview.h"
#include "LoadSlot.h"
#include "qlist.h"
#include "qmap.h"
#include "qdir.h"
#include "qfont.h"
#include "AnimatedGraphicsView.h"
#include "Animation.h"
#include "Animator.h"
class LoadUIManager
{
private:
	QGraphicsView* loadUIBG = NULL;
	QFont labelFont;
	QList<LoadSlot> loadSlots;
	QString dataSavePos = QDir::currentPath() + "/SaveData" + "/Slot";
	QString LoadUIDataName = "/LoadUIData.dat";

	QMap<QString, QMap<QString, Animation>> slotAniDics;

	QList<QString> dataKeys;

	void InitSlotAniData();

	void InitSaveDataKey();

	void InitStream(QDataStream& dataStream);

	void EstablishSlotAnimator();
	
	void ReadAndLoadLocalData();


public:

	LoadUIManager()
	{

	}

	LoadUIManager(QGraphicsView*  LoadUI_BG, QList<LoadSlot> loadSlots)
	{
		this->loadUIBG = LoadUI_BG;
		this->loadSlots = loadSlots;

		InitSaveDataKey();
		InitSlotAniData();
		
		//Load action
		ReadAndLoadLocalData();

		//Establish ani
		EstablishSlotAnimator();
		
	}

	void SetValid(bool isValid)
	{
		loadUIBG->setVisible(isValid);

		for (int i = 0; i < loadSlots.count(); i++)
		{
			loadSlots[i].SetValid(isValid);
		}
	}

	bool CanThisSlotLoad(int slotIndex);
	
};

