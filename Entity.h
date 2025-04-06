#pragma once
#include "EntityProperty.h"
#include "qstring.h"
#include "Animator.h"
class Entity : public TimeUpdater
{
protected:
	int HP = 0;
	int attack = 0;
	int defence = 0;
	
	//attack every tickGroup
	int attackRate = 10;
	int chargingRange = 10;

	QGraphicsView* entityGraphic = NULL;
	Animator animator;

	Entity()
	{
		entityProperty = EntityProperty();
	}
	~Entity()
	{
		if (entityGraphic != NULL)
		{
			delete entityGraphic;
		}
	}

	Entity(EntityProperty entityProperty)
	{
		this->entityProperty = entityProperty;
		HP = entityProperty.HP();
		attack = entityProperty.Attack();
		defence = entityProperty.Defence();
	}
public:
	int currentHP() { get: return HP; }
	int currentAttack() { get: return attack; }
	int currentDefence() { get: return defence; }
	

	EntityProperty entityProperty;
	virtual void Update() override
	{	
		if (isUpdating)
		{
			animator.Animating();
			animator.DelayAnimating();
		}	
	}

	void SetValid(bool isValid)
	{
		entityGraphic->setVisible(isValid);
		entityGraphic->setEnabled(isValid);

		isUpdating = isValid;
	}

	//Animation 
	void CallAnimation(QString ani_Name, bool isLoop)
	{
		animator.PlayAnimation(ani_Name, isLoop);
	}
	void StopAnimation()
	{
		animator.StopAnimation();
	}

	bool isCurrentAniOver()
	{
		return animator.IsAniOver();
	}
	

	// Battle
	virtual void Attack()
	{

	}

	void Damaged(int original_AT)
	{	
		int finalAT = original_AT - defence;
		if (finalAT < 0)
			finalAT = 0;

		HP -= finalAT;

		if (HP < 0)
			HP = 0;
	}

	int AttackRate()
	{
		return attackRate;
	}

	int ChargingRange()
	{
		return chargingRange;
	}
};

