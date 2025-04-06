#pragma once
#include "qframe.h"
#include "qpushbutton.h"
#include "qgraphicsview.h"
#include "ISaveable.h"
#include "qmap.h"
#include "Item.h"
#include "ItemCreater.h"

class Bag : public ISaveable
{
private:
	bool isBagTrigged = false;
	QFrame* bagSlots[20] = { NULL };
	QGraphicsView* bagBackground =NULL;
	QPushButton* bagButton = NULL;
	QList<ItemDetails> itemDetailLibrary;
	

	//Load Task's Base
	QList<int> itemIDList;

	//bag Store index is 0-9
	int bagSize = 0;
	int nextPushPos = 0;

public:

	Bag() : ISaveable("/BagDetail.dat")
	{

	}

	Bag(QFrame* Slots[], QGraphicsView* background, QPushButton* bagButton) : ISaveable("/BagDetail.dat")
	{	
		bagBackground = background;
		this->bagButton = bagButton;
		bagSize = 9;
		for (int i = 0; i < 10; i++)
		{
			bagSlots[i] = Slots[i];
		}
	}

	void Init();

	void SetValid(bool isvisable);

	void TriggerBag();

	void ReleaseBag();

	void BagClick();

	void KeyTrigger(bool isOpen);

	void AddNewItem(Item newItem);
	
	void ITEM_DETAIL_Library_LoadIn(QList<ItemDetails> idDetailsLibrary);

	void FillTheBagWithLoadFile();
	
	

	// Í¨¹ý ISaveable ¼Ì³Ð
	virtual void Saving(QFile* fileToSave) override;

	virtual void Loading(QFile* fileToLoad) override;

};

