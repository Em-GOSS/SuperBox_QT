#pragma once
#include "Enums.h"
class DamageDetails
{
private:
	int originDamageValue = 0;
	Effect damageEffect;
public:
	DamageDetails(int originDamageValue, Effect damageEffect)
	{
		this->originDamageValue = originDamageValue;
		this->damageEffect = damageEffect;
	}
};

