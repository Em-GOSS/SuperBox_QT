#pragma once
#include "AnimatedGraphicsView.h"
#include "qfontdatabase.h"
#include "SaveDetails.h"
#include "TimeUpdater.h"
#include "Animator.h"
#include "qlabel.h"
#include "qlist.h"
#include "qdebug.h"
class LoadSlot
{
private:
	AnimatedGraphicsView* slotAniGraphic = NULL;
	QList<QLabel*> loadFilePropertyLabels;
	bool isSlotEmpty = true;
	QFont labelFont;
	

	//Import custom Font make sure we can show exact font in any environment
	void AmendLabelsFont()
	{
		labelFont.setFamily("Pixel Number");
		for (int i = 0; i < loadFilePropertyLabels.count(); i++)
		{
			loadFilePropertyLabels[i]->setFont(labelFont);
		}	
	}

public:
	LoadSlot()
	{

	}

	LoadSlot(AnimatedGraphicsView* slotAniGraphic, QList<QLabel*> slotLabels)
	{
		this->slotAniGraphic = slotAniGraphic;
		this->loadFilePropertyLabels = slotLabels;
		AmendLabelsFont();
	}

	~LoadSlot()
	{
		slotAniGraphic = NULL;
	}

	void SetValid(bool isValid)
	{
		slotAniGraphic->setVisible(isValid);
		if (!isSlotEmpty)
		{
			for (int i = 0; i < loadFilePropertyLabels.count(); i++)
			{
				loadFilePropertyLabels[i]->setVisible(isValid);
			}
		}
		else
		{
			for (int i = 0; i < loadFilePropertyLabels.count(); i++)
			{
				loadFilePropertyLabels[i]->setVisible(false);
			}
		}
		
	}

	//must use this method before Enter any other work
	void ImportDataFromSaveFile(QList<int> dataList)
	{
		this->isSlotEmpty = false;
		for (int labelIndex = 0; labelIndex < loadFilePropertyLabels.count(); labelIndex++)
		{	
			loadFilePropertyLabels[labelIndex]->setText(QString::number(dataList[labelIndex]));
		}
	}

	void CreateSlotAni(QMap<QString, Animation> graAniDic, bool isSlotEmpty)
	{
		slotAniGraphic->CreateAni(graAniDic);
		slotAniGraphic->EnterActiveMode();
		slotAniGraphic->EndLoadInTask();
		slotAniGraphic->SetClickCallBack(!isSlotEmpty);
	}


	bool isEmpty()
	{
		return isSlotEmpty;
	}

	
	void UpdateSlotUI()
	{
		slotAniGraphic->UpdateStyle();
	}

	AnimatedGraphicsView* GetAniGra()
	{
		return slotAniGraphic;
	}

#pragma region Debug
	//Debug need to remove 
	/*void SetEmptyFalse()
	{
		this->isSlotEmpty = false;
	}*/
#pragma endregion


};

