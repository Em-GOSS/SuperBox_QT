#pragma once
#include "qgraphicsview.h"
#include "qpushbutton.h"
#include "qlist.h"
#include "Enums.h"
class CustomizeSlot
{

private: 
	
	int currentPointAmount = 1;
	int pointCurrentIndex = 0;
	int pointMaxIndex = 9;
	QGraphicsView* customProperty_Gra = NULL;
	QList<QGraphicsView* > propertySkillPoint_Gras;
	QPushButton* increaseButton = NULL;
	QPushButton* decreaseButton = NULL;

public: 
	CustomizeSlot(QGraphicsView* customProperty_Gra, QList<QGraphicsView* > skillPoints, QPushButton* increaseButton, QPushButton* decreaseButton)
	{
		this->customProperty_Gra = customProperty_Gra;
		this->propertySkillPoint_Gras = skillPoints;
		this->increaseButton = increaseButton; 
		this->decreaseButton = decreaseButton;

		for (int i = 1; i <= pointMaxIndex; i++)
		{
			propertySkillPoint_Gras[i]->setVisible(false);
		}
	}

	void IncreaseSkillPoint()
	{	
		currentPointAmount++;
		pointCurrentIndex++;
		propertySkillPoint_Gras[pointCurrentIndex]->setVisible(true);
	}

	void DecreaseSkillPoint()
	{
		currentPointAmount--;
		propertySkillPoint_Gras[pointCurrentIndex]->setVisible(false);
		pointCurrentIndex--;
	}

	bool CanIncreasePoint()
	{
		if (pointCurrentIndex < pointMaxIndex)
			return true;
		else
			return false;
	}

	bool CanDecreasePoint()
	{
		if (pointCurrentIndex > 0)
			return true;
		else
			return false;
	}


	void SetValid(bool isValid)
	{
		this->customProperty_Gra->setVisible(isValid);
		this->increaseButton->setVisible(isValid);
		this->decreaseButton->setVisible(isValid);

		for (int i = 0; i <= pointCurrentIndex; i++)
		{
			propertySkillPoint_Gras[i]->setVisible(isValid);
		}
	}

	int GetSkillPointAmount()
	{
		return currentPointAmount;
	}
	
};

