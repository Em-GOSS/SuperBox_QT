#pragma once
#include "qgraphicsview.h"
#include "qpushbutton.h"
#include "qlabel.h"
#include "Item.h"
class SelectUI
{
private:
	QLabel* textLabel = NULL;
	QGraphicsView* selectUIBackGround = NULL;
	QPushButton* select_Boxs[5] = { NULL };
	QPushButton* select_Button = NULL;
	QLabel* descriptionBox = NULL;
	Item itemsToSelect[5];
	int select_Index = -1;
	bool isOpen = false;
	
public:
	SelectUI()
	{

	}
	SelectUI(QLabel* textLabel, QGraphicsView* background, QPushButton* slectBoxs[],QPushButton* select_Button, QLabel* descriptionBox)
	{
		this->textLabel = textLabel;
		selectUIBackGround = background;
		for (int i = 1; i <= 3; i++)
		{
			select_Boxs[i] = slectBoxs[i];
		}

		this->select_Button = select_Button;
		this->descriptionBox = descriptionBox;

		SetValid(false);
	}
	bool canExit() { get: return select_Index != -1; }
	bool canOpen() { get: return !isOpen; }

	void SetSelectButtonEnabled(bool isEnabled)
	{
		select_Button->setEnabled(isEnabled); 
	}

	void SetValid(bool isValid);

	void Item_Data_Inport(Item* items);

	void selecting(int i);

	Item GetCurrentSelectItem();
	
	void LoadSelectBox(int i);
	
	void LoadSelectDescription(int i);
};

