#include "EntityProperty.h"

void EntityProperty::UpdateProperty(Property propertyToUpdate, int value)
{
	switch (propertyToUpdate)
	{
	case Property::attack:
		entity_Attack = value;
		break;
	case Property::defence:
		entity_Defence = value;
		break;
	case Property::HP:
		entity_HP = value;
		break;
	default:
		break;
	}
}

void EntityProperty::UpdateProperty(int attack, int defence, int HP)
{
	entity_Attack = attack;
	entity_Defence = defence;
	entity_HP = HP;
}
