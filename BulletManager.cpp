#include "BulletManager.h"

void BulletManager::InitializeBulletDetails()
{
	QMap<QString, Animation> bulletAni_Dic;
	QList<QString> aniSheets;
	Animation idleAni;
	Animation shootingAni;
//Player's Bullet 

//Energy

	bulletAni_Dic.clear();

	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/EnergyIDLE1.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE2.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE3.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE4.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE5.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE6.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE7.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE8.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE9.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE10.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE11.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE12.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE13.bmp);");
	aniSheets.append("border-image: url(:/image/EnergyIDLE14.bmp);");
	
	idleAni = Animation(aniSheets, 14, 2);
	bulletAni_Dic.insert("idle", idleAni);

	//shooting
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/NormalButton_IDLE1.bmp);");
	aniSheets.append("border-image: url(:/image/NormalButton_IDLE2.bmp);");
	aniSheets.append("border-image: url(:/image/NormalButton_IDLE3.bmp);");
	aniSheets.append("border-image: url(:/image/NormalButton_IDLE4.bmp);");

	shootingAni = Animation(aniSheets, 4, 2);
	bulletAni_Dic.insert("shooting", shootingAni);

	bulletAni_Dics.insert(BulletType::Energy, bulletAni_Dic);
	bulletOriginStyleDic.insert(BulletType::Energy, "border-image: url(:/image/bullet_Energy.bmp);");

//Thunder
	bulletAni_Dic.clear();

	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/ThunderIDLE1.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE2.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE3.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE4.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE5.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE6.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE7.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE8.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE9.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE10.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE11.bmp);");
	aniSheets.append("border-image: url(:/image/ThunderIDLE12.bmp);");

	idleAni = Animation(aniSheets, 12, 2);
	bulletAni_Dic.insert("idle", idleAni);

	//shooting
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/TunderShooting1.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting2.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting3.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting4.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting5.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting6.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting7.bmp);");
	aniSheets.append("border-image: url(:/image/TunderShooting8.bmp);");

	shootingAni = Animation(aniSheets, 8 ,2);
	bulletAni_Dic.insert("shooting", shootingAni);

	bulletAni_Dics.insert(BulletType::Thunder, bulletAni_Dic);
	bulletOriginStyleDic.insert(BulletType::Thunder, "border-image: url(:/image/bullet_ThunderGem.bmp);");
	
//Stone 
	bulletAni_Dic.clear();

	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/StoneIDLE1.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE2.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE3.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE4.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE5.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE6.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE7.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE8.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE9.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE10.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE11.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE12.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE13.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE14.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE15.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE16.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE17.bmp);");
	aniSheets.append("border-image: url(:/image/StoneIDLE18.bmp);");

	idleAni = Animation(aniSheets, 18, 2);
	bulletAni_Dic.insert("idle", idleAni);

	//shooting
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/StoneShooting1.bmp);");
	aniSheets.append("border-image: url(:/image/StoneShooting2.bmp);");
	aniSheets.append("border-image: url(:/image/StoneShooting3.bmp);");
	aniSheets.append("border-image: url(:/image/StoneShooting4.bmp);");
	aniSheets.append("border-image: url(:/image/StoneShooting5.bmp);");
	aniSheets.append("border-image: url(:/image/StoneShooting6.bmp);");

	shootingAni = Animation(aniSheets, 6, 2);
	bulletAni_Dic.insert("shooting", shootingAni);
	
	bulletAni_Dics.insert(BulletType::Stone, bulletAni_Dic);
	bulletOriginStyleDic.insert(BulletType::Stone, "border-image: url(:/image/bullet_HeavyStone.bmp);");

	//Ice
	bulletAni_Dic.clear();

	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/IceIDLE1.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE2.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE3.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE4.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE5.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE6.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE7.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE8.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE9.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE10.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE11.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE12.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE13.bmp);");
	aniSheets.append("border-image: url(:/image/IceIDLE14.bmp);");

	idleAni = Animation(aniSheets, 14, 2);
	bulletAni_Dic.insert("idle", idleAni);

	//shooting
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/IceShooting1.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting2.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting3.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting4.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting5.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting6.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting7.bmp);");
	aniSheets.append("border-image: url(:/image/IceShooting8.bmp);");

	shootingAni = Animation(aniSheets, 8, 2);
	bulletAni_Dic.insert("shooting", shootingAni);

	bulletAni_Dics.insert(BulletType::Ice, bulletAni_Dic);
	bulletOriginStyleDic.insert(BulletType::Ice, "border-image: url(:/image/bullet_Ice.bmp);");

	//Water
	bulletAni_Dic.clear();

	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/WaterIDLE1.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE2.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE3.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE4.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE5.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE6.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE7.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE8.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE9.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE10.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE11.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE12.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE13.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE14.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE15.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE16.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE17.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE18.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE19.bmp);");
	aniSheets.append("border-image: url(:/image/WaterIDLE20.bmp);");

	idleAni = Animation(aniSheets, 20, 2);
	bulletAni_Dic.insert("idle", idleAni);

	//shooting
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/WaterShooting1.bmp);");
	aniSheets.append("border-image: url(:/image/WaterShooting2.bmp);");
	aniSheets.append("border-image: url(:/image/WaterShooting3.bmp);");
	aniSheets.append("border-image: url(:/image/WaterShooting4.bmp);");
	aniSheets.append("border-image: url(:/image/WaterShooting5.bmp);");


	shootingAni = Animation(aniSheets, 5, 2);
	bulletAni_Dic.insert("shooting", shootingAni);

	bulletAni_Dics.insert(BulletType::Water, bulletAni_Dic);
	bulletOriginStyleDic.insert(BulletType::Water, "border-image: url(:/image/bullet_Water.bmp);");


//Enemy's Bullet
//Poision

	bulletAni_Dic.clear();

	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/PosionShooting1.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting2.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting3.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting4.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting5.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting6.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting7.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting8.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting9.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting10.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting11.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting12.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting13.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting14.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting15.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting16.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting17.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting18.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting19.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting20.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting21.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting22.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting23.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting24.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting25.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting26.bmp);");
	aniSheets.append("border-image: url(:/image/PosionShooting27.bmp);");

	idleAni = Animation(aniSheets, 27, 2);
	bulletAni_Dic.insert("idle", idleAni);

	//shooting
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/Posion_Bullet1.bmp);");
	aniSheets.append("border-image: url(:/image/Posion_Bullet2.bmp);");
	aniSheets.append("border-image: url(:/image/Posion_Bullet3.bmp);");
	aniSheets.append("border-image: url(:/image/Posion_Bullet4.bmp);");
	aniSheets.append("border-image: url(:/image/Posion_Bullet5.bmp);");

	idleAni = Animation(aniSheets, 5, 2);
	bulletAni_Dic.insert("shooting", idleAni);

	
	bulletAni_Dics.insert(BulletType::Poision, bulletAni_Dic);
	bulletOriginStyleDic.insert(BulletType::Poision, "border-image: url(:/image/Posion_Bullet1.bmp);");



}

void BulletManager::InitializeBulletUIDetials()
{
	bulletUISheetMap.insert(BulletType::Energy, "border-image: url(:/image/BulletSlot_Energy.bmp);");
	bulletUISheetMap.insert(BulletType::Ice, "border-image: url(:/image/BulletSlot_Ice.bmp);");
	bulletUISheetMap.insert(BulletType::Thunder, "border-image: url(:/image/BulletSlot_Thunder.bmp);");
	bulletUISheetMap.insert(BulletType::Stone, "border-image: url(:/image/BulletSlot_Stone.bmp);");
	bulletUISheetMap.insert(BulletType::Water, "border-image: url(:/image/BulletSlot_Water.bmp);");
}

void BulletManager::RegisterNewBullet(BulletType bulletType)
{	
	BulletDetails newBullet = BulletDetails(bulletType, 1);
	playerBulletStore.append(newBullet);
	maxBulletIndex++;
}

/// <summary>
/// return true if LevelUp task is Successful
/// </summary>
/// <returns></returns>
bool BulletManager::LevelUpBullet(BulletType bulletType)
{
	for (int i = 0; i < playerBulletStore.count(); i++)
	{
		if (playerBulletStore[i].bulletType == bulletType)
		{		
			return playerBulletStore[i].LevelUP();			
		}
	}
	return false;
}

void BulletManager::LoadBulletUI(QGraphicsView* bulletUI)
{
	this->bulletUI = bulletUI;
}

void BulletManager::SwitchBullet(bool isLeftSwitching)
{	
	if (isLeftSwitching)
	{
		if (currentBulletIndex == 0)
			currentBulletIndex = maxBulletIndex;
		else
			currentBulletIndex--;
	}
	else
	{
		if (currentBulletIndex == maxBulletIndex)
			currentBulletIndex = 0;
		else
			currentBulletIndex++;
	}
	currentBulletType = playerBulletStore[currentBulletIndex].bulletType;
	currentBulletLevel = playerBulletStore[currentBulletIndex].level;

	UpdateBulletUI();
}

void BulletManager::BulletImport(BulletType bulletType)
{
	if (!isContains(bulletType))
	{
		RegisterNewBullet(bulletType);
	}
	else
	{	
		//调用时已经levelUp
		if (LevelUpBullet(bulletType) == false)
		{
			//添加金币
			qDebug("ADD GOLD");
		}
	}
}

bool BulletManager::isContains(BulletType bulletType)
{
	for (int i = 0; i < playerBulletStore.count(); i++)
	{
		if (playerBulletStore[i].bulletType == bulletType)
			return true;
	}
	
	return false;
}

Bullet* BulletManager::CreatePlayerBullet(QGraphicsView* bulletCanvas)
{	
	BulletDetails currentB_Details = playerBulletStore[currentBulletIndex];
	Bullet* newBullet = new Bullet(bulletCanvas, currentB_Details,bulletAni_Dics[currentBulletType]);
	newBullet->SetBulletSheetStyle(bulletOriginStyleDic[currentB_Details.bulletType]);
	newBullet->IDLECharging({220,170});
	return newBullet;
}

Bullet* BulletManager::CreateEnemyBullet(QGraphicsView* bulletCanvas, BulletDetails bulletDetails)
{	
	Bullet* newBullet = new Bullet(bulletCanvas, bulletDetails, bulletAni_Dics[bulletDetails.bulletType]);
	newBullet->SetBulletSheetStyle(bulletOriginStyleDic[bulletDetails.bulletType]);
	newBullet->IDLECharging({620,170});
	return newBullet;
}


QString BulletManager::GetCurrentUIStyle()
{
	return bulletUISheetMap[currentBulletType];
}

void BulletManager::UpdateBulletUI()
{
	bulletUI->setStyleSheet(GetCurrentUIStyle());
}

void BulletManager::UpdateBulletData()
{
	currentBulletType = playerBulletStore[currentBulletIndex].bulletType;
	currentBulletLevel = playerBulletStore[currentBulletIndex].level;
}

QList<BulletDetails> BulletManager::GetBulletStore()
{
	return playerBulletStore;
}

int BulletManager::GetCurrentBulletIndex()
{
	return currentBulletIndex;
}

int BulletManager::GetBulletCount()
{
	return playerBulletStore.count();
}

void BulletManager::Saving(QFile* fileToSave)
{
	qDebug("BulletDetails Saving"); 

	QDataStream dataStream(fileToSave);
	 
	dataStream << currentBulletIndex;
	dataStream << playerBulletStore.count();
	
	//Save Model as bulletType
	for (int i = 0; i < playerBulletStore.count(); i++)
	{
		dataStream << int(playerBulletStore[i].bulletType) << playerBulletStore[i].level;
	}
	
	loadUI_DataMap->insert(5, playerBulletStore.count());

}

void BulletManager::Loading(QFile* fileToLoad)
{	
	qDebug("BulletDetails Loading");

	int currentBulletIndex_LoadFile;
	int bulletStoreCount_LoadFile;

	QDataStream dataStream(fileToLoad);

	dataStream >> currentBulletIndex_LoadFile >> bulletStoreCount_LoadFile;

	currentBulletIndex = currentBulletIndex_LoadFile;

	//We must make the index to be -1, because the last pos is 1 point less than Count
	maxBulletIndex = bulletStoreCount_LoadFile - 1;

	playerBulletStore.clear();

	for (int i = 0; i < bulletStoreCount_LoadFile; i++)
	{
		int bulletType_INT;
		int bulletLevel;

		dataStream >> bulletType_INT >> bulletLevel;
		qDebug() << qint16(bulletType_INT) << qint16(bulletLevel);
		
		playerBulletStore.append(BulletDetails(BulletType(bulletType_INT),bulletLevel));

	}

	UpdateBulletData();
	UpdateBulletUI();

}
