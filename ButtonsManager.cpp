#include "ButtonsManager.h"

void ButtonsManager::InitializeAniDatas()
{
	QMap<QString, Animation> aniDic;
	QList<QString> aniSheets;
	Animation idleAni;//this Ani is used to store normal styleSheets
	Animation enterAni;
	Animation leaveAni;
	Animation clickAni;

	
// 1 NewJounary
	aniDic.clear();

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame.png);");
	idleAni = Animation(aniSheets, 1, 1);
	aniDic.insert("idle", idleAni);


	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Enter1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Enter2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Enter3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Enter4.png);");
	enterAni = Animation(aniSheets, 4, 1);
	aniDic.insert("enter", enterAni);

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Leave1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Leave2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Leave3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Leave4.png);");
	leaveAni = Animation(aniSheets, 4, 1);
	aniDic.insert("leave", leaveAni);

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click4.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click5.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click6.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click7.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click8.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click9.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click10.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click11.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click12.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click13.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click14.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click15.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click16.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click17.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click18.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click19.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click20.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click21.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click22.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click23.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click24.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click25.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click26.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click27.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click28.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_NewGame_Click29.png);");
	clickAni = Animation(aniSheets, 29, 1);
	aniDic.insert("click", clickAni);


	aniGra_AniDics.insert(1, aniDic);

// 2 Load Game
	aniDic.clear();

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame.png);");
	idleAni = Animation(aniSheets, 1, 1);
	aniDic.insert("idle", idleAni);


	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Enter1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Enter2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Enter3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Enter4.png);");
	enterAni = Animation(aniSheets, 4, 1);
	aniDic.insert("enter", enterAni);

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Leave1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Leave2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Leave3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGame_Leave4.png);");
	leaveAni = Animation(aniSheets, 4, 1);
	aniDic.insert("leave", leaveAni);

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick4.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick5.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick6.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick7.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick8.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick9.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick10.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick11.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick12.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick13.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick14.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick15.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_LoadGameClick16.png);");
	clickAni = Animation(aniSheets, 16, 1);
	aniDic.insert("click", clickAni);


	aniGra_AniDics.insert(2, aniDic);

// 3 ExitGame
	aniDic.clear();

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_Exit.png);");
	idleAni = Animation(aniSheets, 1, 1);
	aniDic.insert("idle", idleAni);


	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Enter1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Enter2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Enter3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Enter4.png);");
	enterAni = Animation(aniSheets, 4, 1);
	aniDic.insert("enter", enterAni);

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Leave1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Leave2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Leave3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Leave4.png);");
	leaveAni = Animation(aniSheets, 4, 1);
	aniDic.insert("leave", leaveAni);

	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click1.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click2.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click3.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click4.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click5.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click6.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click7.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click8.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click9.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click10.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click11.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click12.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click13.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click14.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click15.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click16.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click17.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click18.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click19.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click20.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click21.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click22.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click23.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click24.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click25.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click26.png);");
	aniSheets.append("border-image: url(:/image/BG/Button_Exit_Click27.png);");
	clickAni = Animation(aniSheets, 27, 1);
	aniDic.insert("click", clickAni);


	aniGra_AniDics.insert(3, aniDic);

}
