#include "Bag.h"

void Bag::Init()
{
	SetValid(false);
}

void Bag::SetValid(bool isValid)
{	
	bagBackground->setVisible(isValid);
	for (int i = 0; i <= 9; i++)
	{
		bagSlots[i]->setVisible(isValid);

	}
}

void Bag::TriggerBag()
{
	SetValid(true);
	isBagTrigged = true;
	bagButton->setStyleSheet("background-image: url(:/image/24_bagICON_disabled .bmp);");
}

void Bag::ReleaseBag()
{	
	SetValid(false);
	isBagTrigged = false;
	bagButton->setStyleSheet("background-image: url(:/image/24_bagICON.bmp);");
	qDebug("realse");
}

void Bag::BagClick()
{	
	
	if (isBagTrigged)
	{
		ReleaseBag();
	}
	else
	{	
		TriggerBag();
	}
	
}

void Bag::KeyTrigger(bool isOpen)
{	
	if (isOpen)
	{
		TriggerBag();
	}
	else
	{
		ReleaseBag();
	}
}



void Bag::AddNewItem(Item newItem)
{
	if (nextPushPos > bagSize)
	{
		qDebug("There is no empty slot in the bag!!!");
	}
	else
	{
		bagSlots[nextPushPos]->setStyleSheet(newItem.GetSheetStyle());
		bagSlots[nextPushPos]->repaint();
		itemIDList.append(newItem.GetItemID());
		nextPushPos++;
	}

}

void Bag::ITEM_DETAIL_Library_LoadIn(QList<ItemDetails> idDetailsLibrary)
{
	this->itemDetailLibrary = idDetailsLibrary;
}

void Bag::FillTheBagWithLoadFile()
{
	for (int i = 0; i < itemIDList.count(); i++)
	{
		bagSlots[i]->setStyleSheet(itemDetailLibrary[itemIDList[i]].sheetStyle);
	}
}

void Bag::Saving(QFile* fileToSave)
{
	qDebug("Bag Saving");

	QDataStream dataStream(fileToSave);

	dataStream << itemIDList.count(); 

	for (int slotIndex = 0; slotIndex < itemIDList.count(); slotIndex++)
	{
		dataStream << itemIDList[slotIndex];
	}

	loadUI_DataMap->insert(4,itemIDList.count());
	
}

void Bag::Loading(QFile* fileToLoad)
{
	qDebug("Bag Loading");

	QDataStream dataStream(fileToLoad);

	int idCount;
	
	dataStream >> idCount; 
	
	itemIDList.clear();

	int ID_Load;

	for (int slotIndex = 0; slotIndex < idCount; slotIndex++)
	{	
		dataStream >> ID_Load;
		itemIDList.append(ID_Load);
		qDebug() << itemDetailLibrary[ID_Load].itemName;
	}

	nextPushPos = idCount;

	FillTheBagWithLoadFile();

}
