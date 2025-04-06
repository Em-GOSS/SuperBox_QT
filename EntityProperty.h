#pragma once
#include "Enums.h"
#include "qlist.h"
class EntityProperty
{
private:
	int entity_Attack = 0;
	int entity_Defence = 0;
	int entity_HP = 0;

public:

	EntityProperty()
	{

	}
	EntityProperty(int attack, int defence, int HP)
	{
		entity_Attack = attack;
		entity_Defence = defence;
		entity_HP = HP;
	}

	void UpdateProperty(Property propertyToUpdate, int value);

	void UpdateProperty(int attack, int defence, int HP);

	int Attack()
	{
		return entity_Attack;
	}

	int Defence()
	{
		return entity_Defence;
	}

	int HP()
	{
		return entity_HP;
	}

	/// <summary>
	///  Get save_INT by ID( range of (0~2))
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	int GetPropertyValueByID(int id)
	{
		switch (id)
		{
		case (0):
			return entity_Attack;
			break;
		case (1):
			return entity_Defence;
			break;
		case (2):
			return entity_HP;
			break;
		default:
			break;
		}
	}

};

