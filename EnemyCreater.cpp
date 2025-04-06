#include "EnemyCreater.h"
#include "Structs.h"

void EnemyCreater::InitializeAnimatorDic()
{	
	QMap<QString, Animation> ani_Dic;
	QList<QString> aniSheetList;

//Evil Slime
	ani_Dic.clear();
	//Idle Ani
	aniSheetList.clear();

	aniSheetList.append("border-image: url(:/image/Evil_Slime1.bmp);");
	aniSheetList.append("border-image: url(:/image/Evil_Slime2.bmp);");
	aniSheetList.append("border-image: url(:/image/Evil_Slime3.bmp);");
	aniSheetList.append("border-image: url(:/image/Evil_Slime4.bmp);");

	Animation idle_Ani = Animation(aniSheetList, 4, 1);
	ani_Dic.insert("idle", idle_Ani);

	//Attack Ani 
	aniSheetList.clear();

	aniSheetList.append("border-image: url(:/image/SlimeAttack1.bmp);");
	aniSheetList.append("border-image: url(:/image/SlimeAttack2.bmp);");
	aniSheetList.append("border-image: url(:/image/SlimeAttack3.bmp);");
	aniSheetList.append("border-image: url(:/image/SlimeAttack4.bmp);");

	Animation attack_Ani = Animation(aniSheetList, 4, 2);
	ani_Dic.insert("attack", attack_Ani);

	//Push it to StoreMap
	enemy_AniSheets_Dic.insert(EnemyType::Evil_Slime, ani_Dic);


//Evil Skeleton


}

void EnemyCreater::InitializePropertyDic()
{	
	EntityProperty entityProperty;
	QVector2D AT_Speed;
//Evil Slime 
	entityProperty = EntityProperty(1,1,5);
	enemy_Property_Dic.insert(EnemyType::Evil_Slime, entityProperty);
	AT_Speed.setX(4), AT_Speed.setY(8);
	enemy_ATSpeed_Dic.insert(EnemyType::Evil_Slime, AT_Speed);

//Evil Skeleton
	entityProperty = EntityProperty(6, 1, 4);
	enemy_Property_Dic.insert(EnemyType::Evil_Skeleton, entityProperty);
	AT_Speed.setX(2), AT_Speed.setY(6);
	enemy_ATSpeed_Dic.insert(EnemyType::Evil_Skeleton, AT_Speed);
}

void EnemyCreater::InitializeGeometry()
{	
	QVector4D enemyGeometry;
//Evil Slime
	enemyGeometry.setX(650);
	enemyGeometry.setY(150);
	enemyGeometry.setZ(64);
	enemyGeometry.setW(64);

	enemy_Geometry_Dic.insert(EnemyType::Evil_Slime, enemyGeometry);
}

void EnemyCreater::InitializeBattleDetials()
{	
	BulletDetails enemyBulletDetails;
//Evil Slime 
	enemyBulletDetails = BulletDetails(BulletType::Poision, 1);
	enemy_BDetials_Dic.insert(EnemyType::Evil_Slime,enemyBulletDetails);
	
}

void EnemyCreater::Saving(QFile* fileToSave)
{
	qDebug("EnemyCreaterDetails Saving");

	QDataStream dataStream(fileToSave);

	dataStream << enemyIndex;

	loadUI_DataMap->insert(6, enemyIndex);
}

void EnemyCreater::Loading(QFile* fileToLoad)
{
	qDebug("EnemyCreaterDetails Loading");
	QDataStream dataStream(fileToLoad);
	int enemyIndex_LoadFile;
	dataStream >> enemyIndex_LoadFile;
	this->enemyIndex = enemyIndex_LoadFile;
}

