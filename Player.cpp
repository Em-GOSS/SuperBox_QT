#include "Player.h"
void Player::EquipItem(QMap<int, int> equipEffect)
{
	int newAttack = entityProperty.Attack() + equipEffect[1];
	int newDefence = entityProperty.Defence() + equipEffect[2];
	int newHP = entityProperty.HP() + equipEffect[3];

	entityProperty.UpdateProperty(newAttack, newDefence, newHP);
}

void Player::InitAnimator()
{	
	QMap<QString, Animation> ani_Dic;
	QList<QString> aniSheetList;

	//Idle Ani
	aniSheetList.clear();
	aniSheetList.append("border-image: url(:/image/Idle1.bmp);");
	aniSheetList.append("border-image: url(:/image/Idle2.bmp);");
	aniSheetList.append("border-image: url(:/image/Idle3.bmp);");

	Animation idle_Ani = Animation(aniSheetList, 3, 1);
	ani_Dic.insert("idle", idle_Ani);

	//Attack Ani
	aniSheetList.clear();
	aniSheetList.append("border-image: url(:/image/ButtonAttack1.bmp);");
	aniSheetList.append("border-image: url(:/image/ButtonAttack2.bmp);");
	aniSheetList.append("border-image: url(:/image/ButtonAttack3.bmp);");

	Animation attack_Ani = Animation(aniSheetList, 3, 1);
	ani_Dic.insert("attack", attack_Ani);

	animator = Animator(entityGraphic, ani_Dic);
	
}

void Player::CallAttack()
{
	Attack();
	CallAnimation("attack", false);
}

void Player::Saving(QFile* fileToSave)
{
	qDebug("PlayerProperty Saving");
	QDataStream dataStream(fileToSave);
	dataStream << entityProperty.Attack() << entityProperty.Defence() << entityProperty.HP();
	loadUI_DataMap->insert(1, entityProperty.Attack());
	loadUI_DataMap->insert(2, entityProperty.Defence());
	loadUI_DataMap->insert(3, entityProperty.HP());
}

void Player::Loading(QFile* fileToLoad)
{
	qDebug("PlayerProperty Loading");
	QDataStream dataStream(fileToLoad);
	int ATK{}, DEF{}, HP{};
	dataStream >> ATK >> DEF >> HP;
	qDebug() << QString("Update" + QString::number(ATK) + " " + QString::number(DEF) + " " + QString::number(HP));
	entityProperty.UpdateProperty(ATK,DEF,HP);
}


