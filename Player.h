#pragma once
#include "Entity.h"
#include "TimeUpdater.h"
#include "qgraphicsview.h"
#include "qmap.h"
#include "qlist.h"
#include "ISaveable.h"

class Player : public Entity, public ISaveable
{
	
public:
	Player(QGraphicsView* playerGraphic, EntityProperty entityProperty) :
		Entity::Entity(entityProperty), ISaveable("/playerProperty.dat")
	{	
		this->entityGraphic = playerGraphic;
		InitAnimator();
		ExtraPropertiesImport();
	}

	void ExtraPropertiesImport()
	{
		attackRate = 4;
		chargingRange = 8;
	}

	Player():ISaveable("/playerProperty.dat")
	{
		
	}
	
	void EquipItem(QMap<int,int> equipEffect);

	void InitAnimator();

	void CallAttack();

	EntityProperty GetProperty()
	{
		return entityProperty;
	}
	void SetProperty(EntityProperty entityProperty)
	{
		this->entityProperty = entityProperty;
	}
	
	


	// 通过 ISaveable 继承
	virtual void Saving(QFile* fileToSave) override;


	// 通过 ISaveable 继承
	virtual void Loading(QFile* fileToLoad) override;

};

