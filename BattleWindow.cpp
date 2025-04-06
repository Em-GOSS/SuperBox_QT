#include "BattleWindow.h"
#include "qdebug.h"

void BattleWindow::BarsInitialize()
{	
	playerHPBar = Bar(HP_Sheets, Vector2(25,50), background,player->entityProperty.HP());
	playerEGBar = Bar(EG_Sheets, Vector2(25,30), background,player->ChargingRange());	
	playerEGBar.ReSizeBar(0);
	
	enemyHPBar = Bar(HP_Sheets, Vector2(809,50), background, enemy->entityProperty.HP(),true);
	enemyEGBar = Bar(EG_Sheets, Vector2(809,30), background, enemy->ChargingRange(),true);
	enemyEGBar.ReSizeBar(0);
}

//Update

void BattleWindow::PlayerUpdateProcess()
{	
	if (!isFreezePlayerAni)
	{
		player->Update();		
	}
	
	if (!isFreezeBar)
	{
		PlayerAttackCharging();
	}

	
}

void BattleWindow::EnemyUpdateProcess()
{	
	if (!isFreezeEnemyAni)
	{
		enemy->Update();
		
	}

	if (!isFreezeBar)
	{
		EnemyAttackCharging();
	}
}

void BattleWindow::PlayerBulletsProcess()
{	
	if (isEnemyShooting)
		return;

	if (player->isCurrentAniOver() && isPlayerShooting)
	{
		isFreezePlayerAni = true;
		player->CallAnimation("idle", true);
	}

	if (playerBullet != NULL)
	{	
		if (playerBullet->isNeedShoot())
		{
			playerBullet->Shooting({ BULLET_X_SPEED, 0 }, 600, false);
		}

		if (playerBullet->isNeedDestory())
		{
			
			CallEnemyDamaged();
			UnFreezeAllAni();
			isPlayerShooting = false;
			//Destory
			playerBullet->~Bullet();
			playerBullet = NULL;
			return;
		}

		playerBullet->Update();
	}
}

void BattleWindow::EnemyBulletsProcess()
{	
	if (isPlayerShooting)
		return;

	if (enemy->isCurrentAniOver() && isEnemyShooting)
	{
		isFreezeEnemyAni = true;
		enemy->CallAnimation("idle", true);
	}

	if (enemyBullet != NULL)
	{
		if (enemyBullet->isNeedShoot())
		{
			enemyBullet->Shooting({ -BULLET_X_SPEED, 0 }, 200, true);
		}
		
		if (enemyBullet->isNeedDestory())
		{

			CallPlayerDamaged();
			UnFreezeAllAni();
			isEnemyShooting = false;
			//Destory
			enemyBullet->~Bullet();
			enemyBullet = NULL;
			return;
		}
		
		enemyBullet->Update();
	}
}

void BattleWindow::PlayerAttackCharging()
{
	player_AtTimer++;
	if (player_AtTimer >= player->AttackRate())
	{
		player_AtTimer = 0;
		playerEGBar.ChargingBar(1);
		if (playerEGBar.isChargeOver())
		{
			PlayerShoot();
		}
	}
}

void BattleWindow::EnemyAttackCharging()
{
	enemy_AtTimer++;
	if (enemy_AtTimer >= enemy->AttackRate())
	{
		enemy_AtTimer = 0;
		enemyEGBar.ChargingBar(1);
		if (enemyEGBar.isChargeOver())
		{
			EnemyShoot();
		}
	}
}



//Data
void BattleWindow::SheetDataImport()
{
	//HP SheetStyle
	HP_Sheets.append("border-image: url(:/image/HP_Bar_Head.bmp);");
	HP_Sheets.append("border-image: url(:/image/HP_Fragment.bmp);");
	HP_Sheets.append("border-image: url(:/image/HP_Bar_End.bmp);");
	HP_Sheets.append("border-image: url(:/image/unit_HP.bmp);");

	//Energy SheetStyle
	EG_Sheets.append("border-image: url(:/image/EgFormal_Head.bmp);");
	EG_Sheets.append("border-image: url(:/image/EgFormal_Fragment.bmp);");
	EG_Sheets.append("border-image: url(:/image/EgFormal_End.bmp);");
	EG_Sheets.append("border-image: url(:/image/eg_Unit.bmp);");	
}

void BattleWindow::BarsDestory()
{
	playerHPBar.DestoryBar();
	enemyHPBar.DestoryBar();
	playerEGBar.DestoryBar();
	enemyEGBar.DestoryBar();
}


#pragma region  Battle

void BattleWindow::PlayerShoot()
{	
	isFreezeEnemyAni = true;
	isFreezeBar = true;

	isPlayerShooting = true;

	player->CallAttack();
	playerBullet = bulletManager->CreatePlayerBullet(background);
	
}

void BattleWindow::EnemyShoot()
{	

	isFreezePlayerAni = true;
	isFreezeBar = true;

	isEnemyShooting = true;

	enemy->CallAttack();
	enemyBullet = bulletManager->CreateEnemyBullet(background, enemy->GetEnemyBulletDetails());

}

void BattleWindow::CallPlayerDamaged()
{
	//player->Damaged();
}

void BattleWindow::CallEnemyDamaged()
{
	//enemy->Damaged();
}

#pragma endregion


void BattleWindow::UnFreezeAllAni()
{
	isFreezeBar = false;
	isFreezePlayerAni = false;	
	isFreezeEnemyAni = false;
}


#pragma region UI

void BattleWindow::SetValid(bool isValid)
{
	background->setVisible(isValid);
	powerUI->setVisible(isValid);
	bulletManager->SetBulletUIValid(isValid);

	if (player != NULL)
	{
		player->SetValid(isValid);

		if (isValid)
		{
			player->CallAnimation("idle", true);
		}
		else
		{
			player->StopAnimation();
		}
	}

	if (enemy != NULL)
	{
		enemy->SetValid(isValid);

		if (isValid)
		{
			enemy->CallAnimation("idle", true);
		}
		else
		{
			player->StopAnimation();
		}
	}
	isBattling = isValid;
}

void BattleWindow::SwitchPower(QString style)
{
	powerUI->setStyleSheet(style);
}


#pragma endregion

