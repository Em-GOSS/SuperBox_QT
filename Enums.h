#pragma once

enum class Property
{
	attack,
	defence,
	HP
};

enum class EnemyType
{
	Evil_Slime,
	Evil_Skeleton
};

enum class BulletType
{	
	//Player's Bullet
	Energy,
	Thunder,
	Stone,
	Water,
	Ice,
	//Enemy's Bullet
	Poision
};

enum class Effect 
{	
	Frozen,
	Electrified,
	Burning,   
	Curative, 

	DefendUp,
	AttackUp,
};
