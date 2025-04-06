#include "Item.h"
#pragma execution_character_set("utf-8")
int Item::GetItemID()
{
	return itemID;
}
QString Item::GetSheetStyle()
{
	return sheetStyle;
}



QString Item::GetItemName()
{
	return itemName;
}

QString Item::GetItemDescription()
{
	return itemDescription;
}

QMap<int, int> Item::GetequipEffectDic()
{
	return equipEffectDic;
}
