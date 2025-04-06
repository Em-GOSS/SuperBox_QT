#include "ItemCreater.h"
#include "qmap.h"
#pragma execution_character_set("utf-8")

void ItemCreater::FillCreateList()
{	
	ItemDetails itemDetails;

	//000
	itemDetails.itemName = "布丁！！！";
	itemDetails.itemDescription = "布丁(=ェ=)。\n HP++ ";
	itemDetails.sheetStyle = "border-image: url(:/image/cake1.bmp);";
	itemDetails.equipEffectDic.insert(1, 0);
	itemDetails.equipEffectDic.insert(2, 0);
	itemDetails.equipEffectDic.insert(3, 4);

	toCreateList.append(itemDetails);
	//001
	itemDetails.itemName = "樱花蒟蒻";
	itemDetails.itemDescription = "来自异国他乡的神秘食物。降低生命力但增强防御力与攻击力";
	itemDetails.sheetStyle = "border-image: url(:/image/cake2.bmp);";
	itemDetails.equipEffectDic.insert(1, 2);
	itemDetails.equipEffectDic.insert(2, 2);
	itemDetails.equipEffectDic.insert(3, -2);

	toCreateList.append(itemDetails);

	//002
	itemDetails.itemName = "彩虹蛋糕";
	itemDetails.itemDescription = " 来自神圣国的礼物（很漂亮，某只猫的呕吐物也是这样的）。宇宙无敌蛋糕咕隆 （- ： -）";
	itemDetails.sheetStyle = "border-image: url(:/image/cake3.bmp);";
	itemDetails.equipEffectDic.insert(1, 1);
	itemDetails.equipEffectDic.insert(2, 1);
	itemDetails.equipEffectDic.insert(3, 1);

	toCreateList.append(itemDetails);

	//003
	itemDetails.itemName = "巧克力蛋糕";
	itemDetails.itemDescription = "一块巧克力蛋糕，吃下后会充满力量哦。";
	itemDetails.sheetStyle = "border-image: url(:/image/cake4.bmp);";
	itemDetails.equipEffectDic.insert(1, 2);
	itemDetails.equipEffectDic.insert(2, 0);
	itemDetails.equipEffectDic.insert(3, 0);

	toCreateList.append(itemDetails);

	//004
	itemDetails.itemName = "蓝莓小蛋糕";
	itemDetails.itemDescription = "一块蓝莓小蛋糕，能增强防御力。";
	itemDetails.sheetStyle = "border-image: url(:/image/cake5.bmp);";
	itemDetails.equipEffectDic.insert(1, 0);
	itemDetails.equipEffectDic.insert(2, 2);
	itemDetails.equipEffectDic.insert(3, 0);

	toCreateList.append(itemDetails);


	//005
	itemDetails.itemName = "柠檬小蛋糕";
	itemDetails.itemDescription = "一块柠檬小蛋糕，能增强生命力。";
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



