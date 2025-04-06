#pragma once
#include "qgraphicsview.h"
#include "qstring.h"
#include "Animation.h"
#include "Animator.h"
#include "TimeUpdater.h"
#include "qtimer.h"
#include "qdebug.h"
#include "qmap.h"
#include "qlist.h"
#include "AnimatedGraphicsView.h"
#include "QGraphicsOpacityEffect"
class EnterUIManager : TimeUpdater
{	
private:

	Animator currentAnimator;

	QGraphicsView* productorUI = NULL;
	Animator productorUI_Animator;

	QGraphicsView* mainEnterUI = NULL;
	Animator mainEnterUI_Animator;

	QGraphicsView* gameTittle = NULL;
	QGraphicsView* gameTipBox = NULL;

	QTimer* UITimer = NULL;
	QTimer* environmentTimer = NULL;


	AnimatedGraphicsView* newGameButton = NULL;
	AnimatedGraphicsView* loadGameButton = NULL;
	AnimatedGraphicsView* exitGameButton = NULL;
	
	QList<AnimatedGraphicsView*> gameButtonsStore;

	int tickTimer = 0;

	//Tip Fade
	float tipFadeStrength = 0.08;
	float tipFadeLoopTick = 10;
	
	//tittleFadeIn
	float tittleFadeSpeed = 0.08;
	float productorUIFadeSpeed = 0.05;
	int tickBeforeTittleFadeIn = 25;

	//Button FadeIn
	float buttonsFadeInSpeed = 0.1;
	float Interval_EachFadeTask = 4;
	int fadeButtonIndex = 0;

	
	//Sprite transformation booleans
	bool isStartProductorFadeOut = false;
	bool isProductorUIEnd = false;
	bool isStartTittleFadeIn = false;
	bool isUIEnterTaskEnd = false;
	bool isTaskEnd = false;
	bool isStartButtonsFade = false;


	QGraphicsOpacityEffect* fadeInEffect = new QGraphicsOpacityEffect();
	QGraphicsOpacityEffect* fadeOutEffect = new QGraphicsOpacityEffect();

	QGraphicsOpacityEffect* tipFadeEffect = new QGraphicsOpacityEffect();

	QGraphicsOpacityEffect* newGameEffect = new QGraphicsOpacityEffect();
	QGraphicsOpacityEffect* loadGameEffect = new QGraphicsOpacityEffect();
	QGraphicsOpacityEffect* exitGameEffect = new QGraphicsOpacityEffect();

	QList<QGraphicsOpacityEffect* > gameButtonEffects;


	void Initialize();
	void InitializeAnimators();

	void UI_Update();
	void Environment_Update();

	void InitAllFadeEffect();

	void InitButtons();

public:

	EnterUIManager(QGraphicsView* productorUI, QGraphicsView* gameTittle, QGraphicsView* mainEnterUI, QGraphicsView* gameTipBox,
		AnimatedGraphicsView* newGameButton, AnimatedGraphicsView* loadGameButton, AnimatedGraphicsView* exitGameButton
	)
	{
		this->productorUI = productorUI;
		this->gameTittle = gameTittle; 
		this->mainEnterUI = mainEnterUI;
		this->gameTipBox = gameTipBox;

		this->newGameButton = newGameButton;
		gameButtonsStore.append(newGameButton);

		this->loadGameButton = loadGameButton;
		gameButtonsStore.append(loadGameButton);

		this->exitGameButton = exitGameButton;
		gameButtonsStore.append(exitGameButton);

		gameButtonEffects.append(newGameEffect);
		gameButtonEffects.append(loadGameEffect);
		gameButtonEffects.append(exitGameEffect);

		Initialize();
	}

	EnterUIManager()
	{
		
	}

	void TimersLoadIn(QTimer* uiTimer, QTimer* environmentTimer)
	{
		this->UITimer = uiTimer;
		this->environmentTimer = environmentTimer;
	}

	void Enter()
	{		
		productorUI_Animator.PlayAnimation("idle", false);
		mainEnterUI_Animator.PlayAnimation("idle", true);
		currentAnimator = productorUI_Animator;

		productorUI->raise();

		isUpdating = true;
		UITimer->start();
		environmentTimer->start();
		
	}

	void UIUpdate()
	{
		if(isUpdating)
			UI_Update();
	}

	void environmentUpdate()
	{	
		if (isUpdating)
			Environment_Update();
	}

	bool CanCallEnterButton()
	{
		return isUIEnterTaskEnd && !isTaskEnd;
	}

	void CallEnterButtons()
	{
		isTaskEnd = true;
	}
};
