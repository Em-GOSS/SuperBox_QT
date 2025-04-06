#pragma once
#include "qgraphicsview.h"
#include "qpushbutton.h" 
#include "qdebug.h"
#include "qstring.h"
class SaveIcon
{
private:
	QPushButton* pushIcon = NULL;
	
	int currentSaveSlotIndex = 1;
	int maxSaveSlotInde = 3;
public:
	SaveIcon(QPushButton* pushIcon)
	{
		this->pushIcon = pushIcon;
	}
	SaveIcon()
	{

	}
	
	void SwitchSaveSlot(bool isSwitchLeft)
	{
		if (isSwitchLeft)
		{
			if (currentSaveSlotIndex == 1)
				currentSaveSlotIndex = 3;
			else
				currentSaveSlotIndex--;
		}
		else
		{
			if (currentSaveSlotIndex == 3)
				currentSaveSlotIndex = 1;
			else
				currentSaveSlotIndex++;
		}

		pushIcon->setText(QString::number(currentSaveSlotIndex));
	}

	int GetCurrentSaveSlotIndex()
	{
		return currentSaveSlotIndex - 1;
	}

};

