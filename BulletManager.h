#pragma once
#include "Enums.h"
#include "qmap.h"
#include "qlist.h"
#include "qstring.h"
#include "Animator.h"
#include "Animation.h"
#include "Bullet.h"
#include "ISaveable.h"
#include "BulletDetails.h"
#include "qgraphicsview.h"
class BulletManager : public ISaveable
{
private :
	QGraphicsView* bulletUI;

	int currentBulletIndex = 0;
	int maxBulletIndex = -1;

	int currentBulletLevel = -1;
	BulletType currentBulletType = BulletType::Energy;

	QMap<BulletType, QMap<QString, Animation> >bulletAni_Dics;
	QList<BulletDetails> playerBulletStore;
	QMap<BulletType, QString> bulletUISheetMap;
	QMap<BulletType, QString> bulletOriginStyleDic;
	
	void InitializeBulletDetails();
	void InitializeBulletUIDetials();

	void RegisterNewBullet(BulletType bulletType);

	bool LevelUpBullet(BulletType bulletType);

public:
	BulletManager(QGraphicsView* bulletUI) : ISaveable("/BulletDetails.dat")
	{	
		this->bulletUI = bulletUI;
		InitializeBulletDetails();
		InitializeBulletUIDetials();
		
		/*BulletImport(BulletType::Ice);
		BulletImport(BulletType::Stone);
		BulletImport(BulletType::Thunder);
		BulletImport(BulletType::Energy);
		BulletImport(BulletType::Water);*/

		//UpdateBulletData();
		//UpdateBulletUI();
	}

	void LoadBulletUI(QGraphicsView* bulletUI);

	void SwitchBullet(bool isLeftSwitching);

	void BulletImport(BulletType bulletType);

	bool isContains(BulletType bulletType);

	Bullet* CreatePlayerBullet(QGraphicsView* bulletCanvas);
	Bullet* CreateEnemyBullet(QGraphicsView* bulletCanvas, BulletDetails bulletDetails);

	QString GetCurrentUIStyle();
	void UpdateBulletUI();
	void UpdateBulletData();

	QList<BulletDetails> GetBulletStore();
	int GetCurrentBulletIndex();
	int GetBulletCount();

	void SetBulletUIValid(bool isValid)
	{
		bulletUI->setVisible(isValid);
	}

	// Í¨¹ý ISaveable ¼Ì³Ð
	virtual void Saving(QFile* fileToSave) override;
	virtual void Loading(QFile* fileToLoad) override;
};

