#pragma once
#include "qgraphicsview.h"
#include "QStack.h"
#include "qlist.h"
#include "Structs.h"
class Bar 
{
private:
	QGraphicsView* barParentBase = NULL;

	QGraphicsView* unitBar = NULL;
	QGraphicsView* barHead = NULL;
	QGraphicsView* barEnd = NULL;
	
	Vector2 unitSize = Vector2(16,10);
	Vector2 eachFragmentOffset = Vector2(16, 0);
	
	/// <summary>
	/// 0->head
	/// 1->fragment
	/// 2->end	
	/// 3->unit
	/// </summary>
	QList<QString> barStylesheets;

	QList<QGraphicsView*> fragments;

	Vector2 headPos;

	bool isUnitMode = false;
	bool isLeftDir = false;

	int barMaxLength = 0;
	int barCurrentLength = 0;
	
public:
	Bar()
	{

	}
	Bar(QList<QString> barStylesheets, Vector2 headPos, QGraphicsView* parent, int barLenth, bool isLeftDir = false)
	{	
		this->barStylesheets = barStylesheets;
		this->headPos = headPos;
		this->barParentBase = parent;
		this->isLeftDir = isLeftDir;
		isUnitMode = false;
		InitBar(barLenth);
	}

	bool isChargeOver()
	{
		return barMaxLength == barCurrentLength;
	}

	void InitBar(int i);

	void ReSizeBar(int amount);

	void UnitModeTransforming();

	void ExitUnitMode();

	void ChargingBar(int amount);
	void LessenBar(int amount);
	
	void DestoryBar();
};

