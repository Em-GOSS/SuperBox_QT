#pragma once
#include "Animation.h"
#include "Animator.h"
#include "qgraphicsview.h"
#include "qlist.h"
#include "qmap.h"
#include "Enums.h"
#include "Enemy.h"
#include "ISaveable.h"
#include "qvector4d.h"
#include "qvector2d.h"
#include "BulletDetails.h"
class EnemyCreater : public ISaveable
{
private: 
	int enemyIndex = 1;
	int enemyAmount = 0;
	QGraphicsView* enemyParent = NULL;
	QMap<EnemyType, QMap<QString,Animation>> enemy_AniSheets_Dic;
	QMap<EnemyType, EntityProperty> enemy_Property_Dic;
	QMap<EnemyType, BulletDetails> enemy_BDetials_Dic;
	QMap<EnemyType, QVector4D> enemy_Geometry_Dic;
	QMap<EnemyType, QVector2D> enemy_ATSpeed_Dic;

public:
	EnemyCreater() : ISaveable("/EnemyCreater.dat")
	{
		
	}

	EnemyCreater(QGraphicsView* enemyParent) : ISaveable("/EnemyCreater.dat")
	{	
		this->enemyParent = enemyParent;
		InitializeAnimatorDic();
		InitializePropertyDic();
		InitializeGeometry();
		InitializeBattleDetials();
	}

	void InitializeAnimatorDic();

	void InitializePropertyDic();

	void InitializeGeometry();

	void InitializeBattleDetials();
	
	QMap<QString, Animation> GetEnemyData(EnemyType enemyType)
	{
		return enemy_AniSheets_Dic[enemyType];
	}

	int GetCurrentEnemyIndex()
	{
		return enemyIndex;
	}

	Enemy* CreateEnemy(EnemyType enemyType)
	{		
		QVector4D enemyGeometry = enemy_Geometry_Dic[enemyType];
		QGraphicsView* enemyGraphic = new QGraphicsView();
		enemyGraphic->setGeometry(enemyGeometry.x(), enemyGeometry.y(), enemyGeometry.z(), enemyGeometry.w());
		enemyGraphic->setParent(enemyParent);
		
		Enemy* enemy = new Enemy(enemyGraphic, enemy_Property_Dic[enemyType]);
		enemy->ExtraPropertiesImport(enemy_ATSpeed_Dic[enemyType]);
		enemy->BulletDetailsLoadIn(enemy_BDetials_Dic[enemyType]);
		enemy->AniDicLoadIn(GetEnemyData(enemyType));
		return enemy;
	}

	// 通过 ISaveable 继承
	virtual void Saving(QFile* fileToSave) override;

	// 通过 ISaveable 继承
	virtual void Loading(QFile* fileToLoad) override;
};

