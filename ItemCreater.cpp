#include "ItemCreater.h"
#include "qmap.h"
#pragma execution_character_set("utf-8")

void ItemCreater::FillCreateList()
{	
	ItemDetails itemDetails;

	//000
	itemDetails.itemName = "����������";
	itemDetails.itemDescription = "����(=��=)��\n HP++ ";
	itemDetails.sheetStyle = "border-image: url(:/image/cake1.bmp);";
	itemDetails.equipEffectDic.insert(1, 0);
	itemDetails.equipEffectDic.insert(2, 0);
	itemDetails.equipEffectDic.insert(3, 4);

	toCreateList.append(itemDetails);
	//001
	itemDetails.itemName = "ӣ���X�m";
	itemDetails.itemDescription = "����������������ʳ���������������ǿ�������빥����";
	itemDetails.sheetStyle = "border-image: url(:/image/cake2.bmp);";
	itemDetails.equipEffectDic.insert(1, 2);
	itemDetails.equipEffectDic.insert(2, 2);
	itemDetails.equipEffectDic.insert(3, -2);

	toCreateList.append(itemDetails);

	//002
	itemDetails.itemName = "�ʺ絰��";
	itemDetails.itemDescription = " ������ʥ���������Ư����ĳֻè��Ż����Ҳ�������ģ��������޵е��⹾¡ ��- �� -��";
	itemDetails.sheetStyle = "border-image: url(:/image/cake3.bmp);";
	itemDetails.equipEffectDic.insert(1, 1);
	itemDetails.equipEffectDic.insert(2, 1);
	itemDetails.equipEffectDic.insert(3, 1);

	toCreateList.append(itemDetails);

	//003
	itemDetails.itemName = "�ɿ�������";
	itemDetails.itemDescription = "һ���ɿ������⣬���º���������Ŷ��";
	itemDetails.sheetStyle = "border-image: url(:/image/cake4.bmp);";
	itemDetails.equipEffectDic.insert(1, 2);
	itemDetails.equipEffectDic.insert(2, 0);
	itemDetails.equipEffectDic.insert(3, 0);

	toCreateList.append(itemDetails);

	//004
	itemDetails.itemName = "��ݮС����";
	itemDetails.itemDescription = "һ����ݮС���⣬����ǿ��������";
	itemDetails.sheetStyle = "border-image: url(:/image/cake5.bmp);";
	itemDetails.equipEffectDic.insert(1, 0);
	itemDetails.equipEffectDic.insert(2, 2);
	itemDetails.equipEffectDic.insert(3, 0);

	toCreateList.append(itemDetails);


	//005
	itemDetails.itemName = "����С����";
	itemDetails.itemDescription = "һ������С���⣬����ǿ��������";
	itemDetails.sheetStyle = "border-image: url(:/image/cake6.bmp);";
	itemDetails.equipEffectDic.insert(1, 0);
	itemDetails.equipEffectDic.insert(2, 0);
	itemDetails.equipEffectDic.insert(3, 2);

	toCreateList.append(itemDetails);

	//006
	

	for (int i = 0; i < toCreateList.count(); i++)
	{
		toCreateList[i].itemID = i;
	}
}

/// <summary>
/// the *item is begin in [0] pos;
/// </summary>
/// <returns></returns>
Item* ItemCreater::CreateItems()
{	
	int maxSize = toCreateList.size();

	Item* itemStore = new Item[maxSize];
	for (int i = 0; i < maxSize; i++)
	{
		ItemDetails creater_BaseData = toCreateList.at(i);
		Item newItem = 
			Item(
				creater_BaseData.itemID,
				creater_BaseData.itemName,
				creater_BaseData.sheetStyle,
				creater_BaseData.itemDescription,
				creater_BaseData.equipEffectDic
			);
		itemStore[i] = newItem;
	}
	return itemStore;
}



