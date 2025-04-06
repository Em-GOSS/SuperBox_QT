#pragma once
#include "qgraphicsview.h"
#include "qqueue.h"
#include "Player.h"
#include "Enemy.h"
#include "Bar.h"
#include "Bullet.h"
#include "BulletDetails.h"
#include "BulletManager.h"
#include "TimeUpdater.h"
class BattleWindow : TimeUpdater
{
private:
	//boolean
	bool isBattling = false;
	
	bool isFreezeBar = false;

	bool isFreezePlayerAni = false;
	bool isFreezeEnemyAni = false;

	bool isPlayerShooting = false;
	
	bool isEnemyShooting = false;

	//Compoent
	QGraphicsView* background = NULL;
	QGraphicsView* powerUI = NULL;

	///Entity
	Player* player = NULL;
	Enemy* enemy = NULL;

	//Bar
	Bar playerHPBar;
	Bar playerEGBar;
	Bar enemyHPBar;
	Bar enemyEGBar;

	QList<QString> HP_Sheets;
	QList<QString> EG_Sheets;
	
	//Bullet 
	Bullet* playerBullet = NULL;
	Bullet* enemyBullet = NULL;
	BulletManager* bulletManager = NULL;

	//Time Updater
	int player_AtTimer = 0;
	int enemy_AtTimer = 0;


public:
	BattleWindow()
	{

	}
	BattleWindow(QGraphicsView* bg, QGraphicsView* powerUI, BulletManager* bulletManager) 
	{
		this->background = bg;
		this->powerUI = powerUI;
		this->bulletManager = bulletManager;
		SheetDataImport();
	}
	
	~BattleWindow() 
	{
		if (player != NULL)
			delete player;
		if (enemy != NULL)
			delete enemy;
		
	}
	void ImportEntity(Player* player, Enemy* enemy)
	{
		this->player = player;
		this->enemy = enemy;
	}


	//Time Updater
	/// <summary>
	/// This Method Only use to store the update Tasks ,do not take it into the update stream, 
	/// Dozens of datas will slow down the speed of the program
	/// </summary>
	void Update() override
	{	
		if (isBattling)
		{
			PlayerUpdateProcess();
			EnemyUpdateProcess();

			PlayerBulletsProcess();
			EnemyBulletsProcess();
		}
	}

	bool CanProcessUpdate()
	{
		return isBattling;
	}

	//Entity UI Transformation
	void PlayerUpdateProcess();	
	void EnemyUpdateProcess();
	
	//Bullet Update
	void PlayerBulletsProcess();
	void EnemyBulletsProcess();

	//AttackCharging
	void PlayerAttackCharging();
	void EnemyAttackCharging();

	//Bar
	void SheetDataImport();
	void BarsInitialize();
	void BarsDestory();

	//Battle
	void PlayerShoot();
	void EnemyShoot();

	void CallPlayerDamaged();
	void CallEnemyDamaged();

	//Ani
	void UnFreezeAllAni();


//UI
//__________________________________________________________________________________________________________________
	//Valid
	void SetValid(bool isValid);

	//SheetStyleImport
	void SwitchPower(QString sheetStyle);
	void SwitchBullet(QString sheetStyle);

};

