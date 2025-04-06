#include "Bar.h"
#include "qdebug.h"

void Bar::InitBar(int fragment_Count)
{	
	if (fragment_Count < 1)
	{
		qDebug("Invalid Input");
		return;
	}

	if (isLeftDir)
	{
		eachFragmentOffset = Vector2(-16, 0);
	}

	//Set barLenth
	barMaxLength = fragment_Count;
	barCurrentLength = fragment_Count;

	//Unit Init
	unitBar = new QGraphicsView(barParentBase);
	unitBar->setStyleSheet(barStylesheets[3]);
	unitBar->setGeometry(headPos.x, headPos.y, unitSize.x, unitSize.y);
	unitBar->setVisible(false);

	fragments.append(unitBar);

	//Head Init
	barHead = new QGraphicsView(barParentBase);
	//DirJudge
	if (isLeftDir)
		barHead->setStyleSheet(barStylesheets[2]);
	else
		barHead->setStyleSheet(barStylesheets[0]);
	
	barHead->setGeometry(headPos.x, headPos.y, unitSize.x,unitSize.y);
	
	fragments.append(barHead);
	//Fragment Init
	Vector2 nextPos = headPos + eachFragmentOffset;
	if (fragment_Count >= 2)
	{
		for (int i = 0; i < fragment_Count-2; i++)
		{
			QGraphicsView* newFragment = new QGraphicsView(barParentBase);
			newFragment->setStyleSheet(barStylesheets[1]);
			newFragment->setGeometry(nextPos.x, nextPos.y, unitSize.x, unitSize.y);

			fragments.append(newFragment);

			nextPos = nextPos + eachFragmentOffset;
		}
	}
	
	//End Init
	barEnd = new QGraphicsView(barParentBase);
	//DirJudge
	if (isLeftDir)
		barEnd->setStyleSheet(barStylesheets[0]);
	else
		barEnd->setStyleSheet(barStylesheets[2]);
	barEnd->setGeometry(nextPos.x, nextPos.y, unitSize.x, unitSize.y);

	fragments.append(barEnd);


	if (fragment_Count == 1)
	{
		UnitModeTransforming();
	}

	qDebug() << qint16(fragments.count());
}

void Bar::ReSizeBar(int amount)
{		
	//Judge boundary
	if (amount == barCurrentLength || amount > barMaxLength)
	{	
		return;
	}
		
	
	//Empty Bar
	if (amount <= 0)
	{
		for (int i = 0; i <= barCurrentLength; i++)
		{
			fragments[i]->setVisible(false);
		}
		
		barEnd->setVisible(false);
		barCurrentLength = 0;
		return;
	}

	//UnitMode
	if (amount == 1)
	{	
		for (int i = 0; i <= barCurrentLength; i++)
		{
			fragments[i]->setVisible(false);
		}
		
		UnitModeTransforming();
		
		barCurrentLength = 1;
		return;
	}


	//Normal Situation
	int finalXPos = headPos.x + (amount-1) * unitSize.x;
	if (isLeftDir)
		finalXPos = headPos.x - (amount - 1) * unitSize.x;

	if (amount < barCurrentLength)
	{	
		//Subtitude the lastSlot with barEnd;
		for (int i = amount; i < barCurrentLength; i++)
		{
			fragments[i]->setVisible(false);
		}
	}
	else
	{	
		if (isUnitMode)
			ExitUnitMode();

		for (int i = barCurrentLength; i < amount; i++)
		{
			fragments[i]->setVisible(true);
		}
	}
	
	barEnd->setGeometry(finalXPos, headPos.y, unitSize.x, unitSize.y);
	barCurrentLength = amount;
}

void Bar::UnitModeTransforming()
{
	unitBar->setVisible(true);
	barEnd->setVisible(false);

	isUnitMode = true;
}

void Bar::ExitUnitMode()
{
	unitBar->setVisible(false);
	barEnd->setVisible(true);

	isUnitMode = false;
}

/// <summary>
/// left to right with amount-Step Charging
/// </summary>
/// <param name="amount"></param>
void Bar::ChargingBar(int amount)
{	

	if (amount + barCurrentLength > barMaxLength)
	{	
		ReSizeBar(barMaxLength - amount - barCurrentLength - 1);
	}
	else 
	{
		ReSizeBar(barCurrentLength + amount);
	}
	
}
 
/// <summary>
/// right to left with amount-Step Minus
/// </summary>
/// <param name="amount"></param>
void Bar::LessenBar(int amount)
{	
	ReSizeBar(barCurrentLength - amount);
}

void Bar::DestoryBar()
{
	delete barHead;
	delete barEnd;
	for (int i = 0; i <= barMaxLength; i++)
	{
		delete fragments[i];
	}
}


