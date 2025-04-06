#pragma once
#include "qlist.h"
#include "Enums.h"
#include "EntityProperty.h"
#include "CustomizeSlot.h"
#include "BulletCustomizeManager.h"
#include "qgraphicsview.h"
#include "qpushbutton.h"
#include "qlabel.h"

class CustomizeManager
{
private:
	
	int residualSkillPoint = 10;
	QLabel* skillPoint_TextLabel = NULL;
	QList<CustomizeSlot> propertyCustomize_Slots;
	BulletCustomizeManager bulletCustomizeManager;
	QPushButton* customizeOver_Button = NULL;
	QGraphicsView* background_Gra = NULL;
	QList<BulletType> bulletType_ID_MapList;

	//data to exchange
	QList<int> propertyValueList;
public:
	CustomizeManager()
	{

	}

	CustomizeManager(
		QLabel* skillPoint_TextLabel,
		QList<CustomizeSlot> propertyCustomize_Slots,
		BulletCustomizeManager bulletCustomizeManager,
		QPushButton* customizeOver_Button,
		QGraphicsView* background_Gra)
	{	
		this->skillPoint_TextLabel = skillPoint_TextLabel;
		this->propertyCustomize_Slots = propertyCustomize_Slots;
		this->bulletCustomizeManager = bulletCustomizeManager;
		this->customizeOver_Button = customizeOver_Button;
		this->background_Gra = background_Gra;

		UpdateTextLabel();
		InitMapList();
	}

	void InitMapList()
	{
		bulletType_ID_MapList.append(BulletType::Energy);
		bulletType_ID_MapList.append(BulletType::Ice);
		bulletType_ID_MapList.append(BulletType::Stone);
		bulletType_ID_MapList.append(BulletType::Thunder);
		bulletType_ID_MapList.append(BulletType::Water);
	}

	
	void SetValid(bool isValid)
	{	
		skillPoint_TextLabel->setVisible(isValid);
		customizeOver_Button->setVisible(isValid);
		background_Gra->setVisible(isValid);


		for (int i = 0; i < propertyCustomize_Slots.count(); i++)
		{
			propertyCustomize_Slots[i].SetValid(isValid);
		}

		bulletCustomizeManager.SetValid(isValid);
	}
	

	void IncreaseSkillPoint(int slotIndex)
	{	
		if(propertyCustomize_Slots[slotIndex].CanIncreasePoint())
		{	
			if (residualSkillPoint > 0)
			{
				residualSkillPoint--;
				propertyCustomize_Slots[slotIndex].IncreaseSkillPoint();
				UpdateTextLabel();
			}
		}
	}

	void DecreaseSkillPoint(int slotIndex)
	{
		if (propertyCustomize_Slots[slotIndex].CanDecreasePoint())
		{
			residualSkillPoint++;
			propertyCustomize_Slots[slotIndex].DecreaseSkillPoint();
			UpdateTextLabel();
		}
	}

	void CallBulletSelect(int bulletSelectIndex)
	{
		bulletCustomizeManager.SelectBullet(bulletSelectIndex);
	}

	void UpdateTextLabel()
	{
		skillPoint_TextLabel->setText(QString::number(residualSkillPoint));
	}

	bool canStartJounary()
	{
		return bulletCustomizeManager.isBulletCustomizeOver() && residualSkillPoint == 0;
	}

	EntityProperty GetCustomizeProperty()
	{
		return EntityProperty(
			propertyCustomize_Slots[0].GetSkillPointAmount(),
			propertyCustomize_Slots[1].GetSkillPointAmount(),
			propertyCustomize_Slots[2].GetSkillPointAmount()
		);
	}

	QList<BulletType> GetCustomizeBulletType()
	{	
		QList<BulletType> bulletTypeList;
		for each (int bulletID in bulletCustomizeManager.GetOriginBulletID())
		{
			bulletTypeList.append(bulletType_ID_MapList[bulletID]);
		}

		return bulletTypeList;
	}
};

