#pragma once
#include "qgraphicsview.h"
#include "qlabel.h"
#include "EntityProperty.h"
#include "Enums.h"
class PropertiesUI
{
private	:
	//Constructor
	QGraphicsView* propertyGraphics[5] = { NULL };
	QLabel* propertyTexts[5] = { NULL };
	QGraphicsView* propertiesUI_Background = NULL;
	
	//Properties
	int attack_Value = 1;
	int defence_Value = 1;
	int HP_Value = 1;

	
public:
	PropertiesUI(){}
	PropertiesUI(QGraphicsView* _propertyGraphics[], QLabel* _propertyTexts[], QGraphicsView* _propertiesUI_Background )
	{
		this->propertiesUI_Background = propertiesUI_Background;
		for (int i = 1; i <= 3; i++)
		{
			propertyGraphics[i] = _propertyGraphics[i];

			propertyTexts[i] = _propertyTexts[i];

		}
	}
	
	void UpdateProperties(Property property, int updateValue);

	void UpdateProperties(int attack, int defence, int HP);

	void UpdateProperties(EntityProperty entityProperty);
};

