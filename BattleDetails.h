#pragma once
#include "qlist.h"
#include "BulletDetails.h"
class BattleDetails
{
private:
//Data in ui to show
	int ItemCount = 0;
	int BulletCount = 0;
	int EnemyIndex = 0;
	
//Data need to hiden
	//bulletSystem serialized
	int currentBulletIndex = 0;	
	QList<BulletDetails> playerBulletStore;

	//itemSystem serialized
	QList<int> itemIDList;

public:
	BattleDetails()
	{

	}

	BattleDetails(int ItemCount, int BulletCount, int EnemyIndex, int currentBulletIndex, QList<BulletDetails> playerBulletStore)
	{	
		this->ItemCount = ItemCount;
		this->BulletCount = BulletCount;
		this->EnemyIndex = EnemyIndex;
		this->currentBulletIndex = currentBulletIndex;

		this->playerBulletStore = playerBulletStore;
	}

	
	/// <summary>
	/// Get INT_Data By id(0~2)
	/// </summary>
	/// <param name="id"></param>
	/// <returns></returns>
	int GetIntDataByID(int id)
	{	
		switch (id)
		{
		case(0):
			return ItemCount;
			break;
		case(1):
			return BulletCount;
			break;
		case(2):
			return EnemyIndex;
			break;
		default:
			break;
		}
		return -1;
	}

	QList<BulletDetails> GetBulletStore()
	{
		return playerBulletStore;
	}
	

};

