#include "PropertiesUI.h"
#include "qdebug.h"

void PropertiesUI::UpdateProperties(Property property, int updateValue)
{	
	if (updateValue < 0)
	{
		updateValue = 0;
	}
	switch (property)
	{	

		case Property::attack:
			attack_Value = updateValue;
			propertyTexts[1]->setText(QString::number(updateValue));
			propertyTexts[1]->repaint();
			break;

		case Property::defence:
			defence_Value = updateValue;
			propertyTexts[2]->setText(QString::number(updateValue));
			propertyTexts[2]->repaint();
			break;

		case Property::HP:
			HP_Value = updateValue;
			propertyTexts[3]->setText(QString::number(updateValue));
			propertyTexts[3]->repaint();
			break;

		default:
			break;
	}
}

void PropertiesUI::UpdateProperties(int attack, int defence, int HP)
{
	attack_Value = attack;
	defence_Value = defence;
	HP_Value = HP;
	propertyTexts[1]->setText(QString::number(attack));
	propertyTexts[2]->setText(QString::number(defence));
	propertyTexts[3]->setText(QString::number(HP));

	for (int i = 1; i <= 3; i++)
	{
		propertyTexts[i]->repaint();
	}
}

void PropertiesUI::UpdateProperties(EntityProperty entityProperty)
{
	attack_Value = entityProperty.Attack();
	defence_Value = entityProperty.Defence();
	HP_Value = entityProperty.HP();
	propertyTexts[1]->setText(QString::number(attack_Value));
	propertyTexts[2]->setText(QString::number(defence_Value));
	propertyTexts[3]->setText(QString::number(HP_Value));
}
