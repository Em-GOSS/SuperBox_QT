#pragma once
#include "qlist.h"
#include "qstack.h"
#include "AnimatedGraphicsView.h"
#include "qgraphicsview.h"
class BulletCustomizeManager
{	
private:
	QList<AnimatedGraphicsView* > bulletSelectSlots;
	QList<QGraphicsView* > selectFrames;
	QStack<QGraphicsView* > selectFrameStack;
	QStack<int> bulletIDStack;
	
	int frameStackSize = 2;

public:
	BulletCustomizeManager()
	{

	}

	BulletCustomizeManager(QList<AnimatedGraphicsView* > bulletSelectSlots, QList<QGraphicsView* > selectFrames)
	{
		this->bulletSelectSlots = bulletSelectSlots;
		this->selectFrames = selectFrames;
		for (int i = 0; i < selectFrames.count(); i++)
		{
			selectFrames[i]->setVisible(false);
		}
	}
	
	void SetValid(bool isValid)
	{
		for (int i = 0; i < bulletSelectSlots.count(); i++)
		{
			bulletSelectSlots[i]->setVisible(isValid);
		}
	}

	void SelectBullet(int bulletSlotIndex)
	{
		//qDebug() << qint16(bulletSlotIndex) << QString("pos Selected");
		if (selectFrameStack.contains(selectFrames[bulletSlotIndex]))
			return;

		if (selectFrameStack.size() >= frameStackSize)
		{	
			selectFrameStack.front()->setVisible(false);

			selectFrameStack.pop_front();
			bulletIDStack.pop_front();
		}

		selectFrames[bulletSlotIndex]->setVisible(true);
		selectFrames[bulletSlotIndex]->raise();

		selectFrameStack.push_back(selectFrames[bulletSlotIndex]);
		bulletIDStack.push_back(bulletSlotIndex);
	}

	QList<int> GetOriginBulletID()
	{
		QList<int> bulletIDList;

		bulletIDList.append(bulletIDStack.front());
		bulletIDList.append(bulletIDStack.back());

		return bulletIDList;
	}

	bool isBulletCustomizeOver()
	{
		return selectFrameStack.size() == frameStackSize;
	}

};

