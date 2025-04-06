#pragma once
#include "qgraphicsview.h"
#include "AnimatedGraphicsView.h"
#include "qmap.h"
class ButtonsManager
{
private:
	//MAPID: 1, 2, 3
	AnimatedGraphicsView* button_NewJounary = NULL;
	AnimatedGraphicsView* button_LoadGame = NULL;
	AnimatedGraphicsView* button_ExitGame = NULL;

	QMap<int, QMap<QString, Animation>> aniGra_AniDics;
	QList<AnimatedGraphicsView* > buttonsStore;

	void InitializeAniDatas();
public:
	ButtonsManager(AnimatedGraphicsView* newJounary_Gra, AnimatedGraphicsView* loadGame_Gra, AnimatedGraphicsView* exitGame_Gra)
	{	
		InitializeAniDatas();
		this->button_NewJounary = newJounary_Gra;
		this->button_LoadGame = loadGame_Gra;
		this->button_ExitGame = exitGame_Gra;
		buttonsStore.append(button_NewJounary);
		buttonsStore.append(button_LoadGame);
		buttonsStore.append(button_ExitGame);
		
		button_NewJounary->CreateAni(aniGra_AniDics[1]);
		button_LoadGame->CreateAni(aniGra_AniDics[2]);
		button_ExitGame->CreateAni(aniGra_AniDics[3]);
	}
	ButtonsManager()
	{
		
	}

	void ButtonsSelected(int buttonIndex)
	{	
		buttonIndex -= 1;
		for (int i = 0; i < 3; i++)
		{
			if (i != buttonIndex)
			{
				buttonsStore[i]->ExitActiveMode();
			}
		}
	}


};

