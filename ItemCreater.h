#pragma once
#include "qstring.h"
#include "qmap.h"
#include "qlist.h"
#include "qdebug.h"
#include "Item.h"
#pragma execution_character_set("utf-8")
struct ItemDetails {
public:
	int itemID;
	QString itemName;
	QString sheetStyle;
	//1 is the AttackValue;
	//2 is the DefendValue;
	//3 is the HP 
	QString itemDescription;
	QMap<int, int> equipEffectDic;
};

class ItemCreater
{	

private:
	int itemIndex;
	bool isCreationFinished = false;
	QList<ItemDetails> toCreateList;
	void FillCreateList();


public:
	ItemCreater()
	{	
		FillCreateList();
		itemIndex = toCreateList.count();
		qDebug() << "Already finished __Item_Creatio__ task";
		qDebug() << "ITEM_COUNT:" << qint32(itemIndex)<<endl;
		isCreationFinished = true;
	}

	/// <summary>
	/// will get the -1 value if the system was not created
	/// </summary>
	int GetItemCount()
	{
		if (isCreationFinished)
		{
			return itemIndex;
		}
		else
		{
			return -1;
		}
	}

	Item* CreateItems();

	QList<ItemDetails> GetItemCreateList()
	{
		return toCreateList;
	}

	
};

