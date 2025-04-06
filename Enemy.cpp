#include "Enemy.h"
#include "Entity.h"
#include "Animator.h"

void Enemy::AniDicLoadIn(QMap<QString, Animation> aniDic)
{
	animator = Animator(entityGraphic,aniDic);
}

void Enemy::BulletDetailsLoadIn(BulletDetails bulletDetails)
{
	this->bulletDetails = bulletDetails;
}
