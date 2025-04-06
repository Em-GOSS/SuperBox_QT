#pragma once
#pragma execution_character_set("utf-8")

#include "qstring.h"
#include "qmap.h"
class Item
{
private:
	int itemID = -1;
	QString itemName;
	QString sheetStyle;
	//1 is the AttackValue;
	//2 is the DefendValue;
	//3 is the HP 
	QString itemDescription;
	QMap<int, int> equipEffectDic;
public:
	Item()
	{

	}
	Item(int itemID, QString itemName, QString sheetStyle, QString itemDescription, QMap<int,int> equipEffectDic)
	{	
		this->itemID = itemID;
		this->itemName = itemName;
		this->sheetStyle = sheetStyle;
		this->itemDescription = itemDescription;
		this->equipEffectDic = equipEffectDic;
	}
	
	int GetItemID();

	QString GetSheetStyle();
	QString GetItemName();
	QString GetItemDescription();
	/// <summary>
	/// 1:Attack
	/// 2:Defence
	/// 3:HP
	/// </summary>
	QMap<int, int> GetequipEffectDic();
};

