#pragma once
#include "EntityProperty.h"
#include "BattleDetails.h"
class SaveDetails
{
private:
	EntityProperty saved_PlayerProperty = EntityProperty(0, 0, 0);
	BattleDetails saved_BattleDetails;

public:
	SaveDetails()
	{

	}

	SaveDetails(EntityProperty saved_PlayerProperty, BattleDetails saved_BattleDetails)
	{	
		this->saved_PlayerProperty = saved_PlayerProperty;
		this->saved_BattleDetails = saved_BattleDetails;
	}

	BattleDetails GetBattleDetails()
	{
		return saved_BattleDetails;
	}

	EntityProperty GetProperty()
	{
		return saved_PlayerProperty;
	}

};

