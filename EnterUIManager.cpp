#include "EnterUIManager.h"

void EnterUIManager::Initialize()
{	
	InitAllFadeEffect();
	InitializeAnimators();
	InitButtons();
}

void EnterUIManager::InitializeAnimators()
{
	QMap<QString, Animation> aniDic;
	QList<QString> aniSheets;
	Animation animation;

//ProductorAni
	aniDic.clear();
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/EnterUI1.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI2.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI3.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI4.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI5.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI6.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI7.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI8.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI9.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI10.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI11.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI12.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI13.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI14.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI15.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI16.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI17.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI18.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI19.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI20.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI21.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI22.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI23.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI24.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI25.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI26.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI27.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI28.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI29.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI30.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI31.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI32.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI33.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI34.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI35.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI36.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI37.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI38.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI39.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterUI40.png);");



	animation = Animation(aniSheets, 40, 1);
	aniDic.insert("idle", animation);
	productorUI_Animator = Animator(productorUI, aniDic);


//mainEnterUI
	aniDic.clear();
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/BG/EnterBG1.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG2.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG3.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG4.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG5.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG6.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG7.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG8.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG9.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG10.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG11.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG12.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG13.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG14.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG15.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG16.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG17.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG18.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG19.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG20.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG21.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG22.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG23.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG24.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG25.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG26.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG27.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG28.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG29.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG30.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG31.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG32.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG33.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG34.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG35.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG36.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG37.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG38.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG39.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG40.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG41.png);");
	aniSheets.append("border-image: url(:/image/BG/EnterBG42.png);");

	animation = Animation(aniSheets, 42, 1);
	aniDic.insert("idle", animation);
	
	mainEnterUI_Animator = Animator(mainEnterUI, aniDic);
}

/// <summary>
/// 已验证UI线程与数据流线程同步
/// </summary>
void EnterUIManager::UI_Update()
{	
	currentAnimator.Animating();
}

void EnterUIManager::Environment_Update()
{	
	if (isStartButtonsFade)
	{
		if (fadeButtonIndex > 2)
		{
			environmentTimer->stop();
			for each (AnimatedGraphicsView* button in gameButtonsStore)
			{
				button->EndLoadInTask();
			}
			return;
		}
		tickTimer++;

		if (tickTimer > Interval_EachFadeTask)
		{
			gameButtonEffects[fadeButtonIndex]->setOpacity(gameButtonEffects[fadeButtonIndex]->opacity() + buttonsFadeInSpeed);

			if (gameButtonEffects[fadeButtonIndex]->opacity() >= 1)
			{
				tickTimer = 0;
				gameButtonsStore[fadeButtonIndex]->EnterActiveMode();
				fadeButtonIndex++;
			}
		}
		return;
	}
	if (isUIEnterTaskEnd == false)
	{
		//Judge The ProductorUI
		if (!isStartProductorFadeOut && currentAnimator.IsAniOver())
		{
			isStartProductorFadeOut = true;
		}
		else if (isStartProductorFadeOut)
		{
			fadeOutEffect->setOpacity(fadeOutEffect->opacity() - productorUIFadeSpeed);

			if (fadeOutEffect->opacity() <= 0)
			{
				currentAnimator = mainEnterUI_Animator;
				productorUI->hide();
				isProductorUIEnd = true;
				isStartProductorFadeOut = false;
			}
			}
		else if (isProductorUIEnd)
		{
			tickTimer++;

			if (tickTimer > tickBeforeTittleFadeIn)
			{
				isStartTittleFadeIn = true;
				isProductorUIEnd = false;
				tickTimer = 0;
			}
		}
		else if (isStartTittleFadeIn)
		{
			fadeInEffect->setOpacity(fadeInEffect->opacity() + tittleFadeSpeed);

			if (fadeInEffect->opacity() >= 1)
			{
				isUIEnterTaskEnd = true;
			}
		}
	}
	else
	{
		tickTimer++;
		tipFadeEffect->setOpacity(tipFadeEffect->opacity() + tipFadeStrength);

		if (tickTimer >= tipFadeLoopTick)
		{
			tickTimer = 0;
			tipFadeStrength = -tipFadeStrength;

			//FadeOut and never flash 
			if (isTaskEnd)
			{
				if (tipFadeStrength > 0)
				{
					isStartButtonsFade = true;
					tipFadeEffect->setOpacity(0);
				}
			}
		}
	}

}



void EnterUIManager::InitAllFadeEffect()
{
	
	fadeOutEffect->setOpacity(1);
	fadeInEffect->setOpacity(0);
	tipFadeEffect->setOpacity(0);
	

	gameTittle->setGraphicsEffect(fadeInEffect);
	productorUI->setGraphicsEffect(fadeOutEffect);
	gameTipBox->setGraphicsEffect(tipFadeEffect);

	//GameButtons
	for (int i = 0; i < gameButtonsStore.length(); i++)
	{	
		gameButtonEffects[i]->setOpacity(0);
		gameButtonsStore[i]->setGraphicsEffect(gameButtonEffects[i]);
	}
}
void EnterUIManager::InitButtons()
{

}


