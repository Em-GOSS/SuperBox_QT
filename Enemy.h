#pragma once
#include "Entity.h"
#include "qvector2d.h"
#include "qgraphicsview.h"
#include "Animator.h"
#include "Animation.h"
#include "BulletDetails.h"
class Enemy : public Entity                                                                                   
{
private:
	BulletDetails bulletDetails;
public:
	Enemy(QGraphicsView* enemyGraphic, EntityProperty entityProperty) : Entity::Entity(entityProperty)
	{
		this->entityGraphic = enemyGraphic;
	}

	void AniDicLoadIn(QMap<QString, Animation> aniDic);
	void BulletDetailsLoadIn(BulletDetails bulletDetails);
	
	void ExtraPropertiesImport(QVector2D AT_Speed)
	{
		this->attackRate = AT_Speed.x();
		this->chargingRange = AT_Speed.y();
	}
	
	void CallAttack()
	{
		Attack();
		animator.PlayAnimation("attack", false);
	}
	
	BulletDetails GetEnemyBulletDetails()
	{
		return bulletDetails;
	}
};

