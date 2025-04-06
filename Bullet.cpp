#include "Bullet.h"
#include "qvector2d.h"


void Bullet::Shooting(QVector2D velocity, int end_Xpos, bool isLeftDir)
{
	bullet_Velocity = velocity;
	this->endXpos = end_Xpos;
	this->isDirectionLeft = isLeftDir;
	bulletAnimator.PlayAnimation("shooting",true);
	isShooting = true;
}

/// <summary>
/// Charging Bullet, Waiting for Shoot_Launching
/// </summary>
/// <param name="instantiatePos"></param>
void Bullet::IDLECharging(QVector2D instantiatePos)
{	
	bullet_AniBase->setGeometry(instantiatePos.x(), instantiatePos.y(), 32, 32);
	currentPos = instantiatePos;
	bulletAnimator.PlayAnimation("idle",true);
	bullet_AniBase->setVisible(true);
	bullet_AniBase->raise();
}

/// <summary>
/// Make Bullet Move in each tick
/// </summary>
void Bullet::BulletPhysicMoving()
{	
	if (isDirectionLeft)
	{
		if (currentPos.x() <= endXpos)
		{
			isMovingOver = true;
			isShooting = false;
			return;
		}
	}
	else
	{
		if (currentPos.x() >= endXpos)
		{
			isMovingOver = true;
			isShooting = false;
			return;
		}
	}
	
	currentPos = currentPos + bullet_Velocity;
	bullet_AniBase->move(currentPos.x(),currentPos.y());
}

//void Bullet::LifePassing()
//{
//	bulletLifeTimer += DeltaTime;
//	if (bulletLifeTimer >= bulletLifeTime)
//		this->~Bullet();
//}
