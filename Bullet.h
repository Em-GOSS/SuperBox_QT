#pragma once
#include "qgraphicsview.h"
#include "qvector2d.h"
#include "Structs.h"
#include "Enums.h"
#include "qmap.h"
#include "Setting.h"
#include "Animator.h"
#include "qtimer.h"
#include "BulletDetails.h"
#include "TimeUpdater.h"
class Bullet : TimeUpdater
{
private:
	BulletDetails bulletDetails;

	QGraphicsView* bullet_AniBase;
	Animator bulletAnimator;

	QVector2D bullet_Velocity;
	Vector2 graphicsSize = Vector2(32,32);

	//Bullet physicMoving
	QVector2D currentPos;
	int endXpos = 0;
	bool isDirectionLeft = false;	
	bool isChargingOver = false;
	bool isShooting = false;
	bool isMovingOver = false;
	
	//TimeSystem 
	int bulletChargingTick = 0;//give None origin waiting time , it will cause some timeDecoro problem
	int chargingTimer = 0;

public:
	Bullet(QGraphicsView* canvas, BulletDetails bulletDetails, QMap<QString, Animation> ani_Dic)
	{
		this->bullet_AniBase = new QGraphicsView(canvas);
		this->bulletAnimator = Animator(bullet_AniBase,ani_Dic);
		this->bulletDetails = bulletDetails;

		bulletChargingTick += bulletAnimator.GetAniLength("idle");
		isShooting = false;
	}
	~Bullet()
	{
		delete bullet_AniBase;
	}
	
	void SetBulletSheetStyle(QString style)
	{
		bulletAnimator.SetOriginStyle(style);
	}
	void Update() override
	{	
		bulletAnimator.Animating();

		if (!isShooting)
		{	
			chargingTimer++;
			if(chargingTimer >= bulletChargingTick)
			{
				isChargingOver = true;
			}
		}
		else
		{
			BulletPhysicMoving();
		}
	}
	

	void Shooting(QVector2D velocity, int end_Xpos, bool isLeftDir);

	void IDLECharging(QVector2D instantiatePos);

	void BulletPhysicMoving();
	
	bool isNeedDestory()
	{
		return isMovingOver;
	}
	
	bool isNeedShoot()
	{
		if (!isShooting && isChargingOver)
			return true;
		else
			return false;
	}
};

