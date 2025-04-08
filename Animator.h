#pragma once
#include "Animation.h"
#include "TimeUpdater.h"
#include "qgraphicsview.h"
#include "qmap.h"
#include "qstack.h"
#include "QString"
#include "qdebug.h"
class Animator 
{	
private:
	QString originSheetStyle = "OriginStyle";
	QGraphicsView* ani_Base = NULL;
	QMap<QString, Animation> ani_Dic;
	Animation currentAnimation;

	//Boolean
	bool isAnimating = false;
	bool isAniLoop = false;
	bool isAniOver = false;
	bool isAniQueuing = false;
	bool isHoldLastFrame = false;

	//animation start at 0 pos ,when the timer got the right tick, then change to 0 (where is the first sprite)
	int aniIndex = 0;
	int timeTick = 0;

	//Ani IEnumator
	int delayAniTimer = 0;
	int waitDuration = 0;
	bool loopMode = false;
	QString delayAniName = "None";
	

public:
	Animator()
	{

	}

	/// <summary>
	/// In the ani_Dic must give a idle ani as the originAniBase;
	/// </summary>
	/// <param name="ani_Base"></param>
	/// <param name="ani_Dic"></param>
	Animator(QGraphicsView* ani_Base, QMap<QString, Animation> ani_Dic)
	{
		this->ani_Base = ani_Base;
		this->ani_Dic = ani_Dic;

		//Set the First IDLE Ani As the original ANI
		originSheetStyle = ani_Dic["idle"].ani_Sheets[0];
		ani_Base->setStyleSheet(originSheetStyle);
	}

	bool IsAniOver()
	{
		return isAniOver;
	}

	/// <summary>
	/// Give 3 mode to use this animator 
	/// </summary>
	/// <param name="aniName"></param>
	/// <param name="isLoop"></param>
	/// <param name="isHoldLastFrame"></param>
	void PlayAnimation(QString aniName, bool isLoop, bool isHoldLastFrame = false)
	{	
		isAnimating = true;
		isAniOver = false;
		aniIndex = 0;
		timeTick = 0;
		isAniLoop = isLoop;
		this->isHoldLastFrame = isHoldLastFrame;
		if (ani_Dic.contains(aniName))
		{
			currentAnimation = ani_Dic[aniName];
			ani_Base->setStyleSheet(currentAnimation.ani_Sheets[0]);
		}
		else
		{
			qDebug("There is No Such animation that contais in dic, error : Animator_DIC");
		}
		
	}

	void StopAnimation(bool isHoldLastFrame = false)
	{
		isAnimating = false;
		isAniLoop = false;
		isAniOver = true;
		if(!isHoldLastFrame)
			ani_Base->setStyleSheet(originSheetStyle);
	}

	void DelayAniPlay(QString aniName, bool isLoop, int waitTicks)
	{
		delayAniName = aniName;
		loopMode = isLoop;
		waitDuration = waitTicks;
	}

	void DelayAniPlay(QString aniName, bool isLoop, QString lastAniName)
	{
		delayAniName = aniName;
		loopMode = isLoop;
		waitDuration = ani_Dic[lastAniName].GetTotalTicks();
	}

	void DelayAnimating()
	{		
		if (delayAniName == "None")
			return;

		delayAniTimer++;
		if (delayAniTimer >= waitDuration)
		{
			PlayAnimation(delayAniName, loopMode);
			delayAniTimer = 0;
			delayAniName = "None";
		}
	}


	void Animating()
	{
		if (isAnimating == false)
			return;
		timeTick++;

		if (timeTick >= currentAnimation.ani_Interval)
		{	
			timeTick = 0;
			aniIndex++;
			if (aniIndex >= currentAnimation.ani_Count)
			{	
				
				if (isAniLoop)
				{
					aniIndex = 0;
				}
				else
				{	
					StopAnimation(isHoldLastFrame);
					return;
				}
			}
			ani_Base->setStyleSheet(currentAnimation.ani_Sheets[aniIndex]);
		}
	}
	
	void SetOriginStyle(QString originStyle)
	{
		this->originSheetStyle = originStyle;
	}

	QString GetOriginStyle()
	{
		return originSheetStyle;
	}
		

	int GetAniLength(QString aniName)
	{
		return ani_Dic[aniName].GetTotalTicks();
	}

};

