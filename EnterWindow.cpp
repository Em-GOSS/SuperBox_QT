#include "EnterWindow.h"
#include "ui_EnterWindow.h"

EnterWindow::EnterWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::EnterWindowClass())
{
	ui->setupUi(this);
	setWindowTitle("Super_BOX");
	BuildTimeSystem();
	EstablishUISystem();
	EstablishButtonSystem();
	EstablishLoadUISystem();
	EstablishCustomizeSystem();

	enterUIManager.Enter();
	
	//Now current widget class was focused
	this->grabKeyboard();
}

EnterWindow::~EnterWindow()
{
	delete ui;
}

void EnterWindow::BuildTimeSystem()
{
	UITimer->setInterval(100);
	environmentTimer->setInterval(100);
	
	connect(UITimer, SIGNAL(timeout()), this, SLOT(UITimeTick()));
	connect(environmentTimer, SIGNAL(timeout()), this, SLOT(environmentTimeTick()));
}

void EnterWindow::EstablishUISystem()
{
	QGraphicsView* productorUI = QObject::findChild<QGraphicsView*>("productorUI");
	QGraphicsView* gameTittle = QObject::findChild<QGraphicsView*>("gameTittle");
	QGraphicsView* mainEnterUI = QObject::findChild<QGraphicsView*>("mainEnterUI");
	QGraphicsView* gameTipBox = QObject::findChild<QGraphicsView*>("gameTipBox");

	AnimatedGraphicsView* newJounary_Gra = QObject::findChild<AnimatedGraphicsView*>("newJounary_Gra");
	AnimatedGraphicsView* loadGame_Gra = QObject::findChild<AnimatedGraphicsView*>("loadGame_Gra");
	AnimatedGraphicsView* exitGame_Gra = QObject::findChild<AnimatedGraphicsView*>("exitGame_Gra");

	enterUIManager = EnterUIManager(
		productorUI, gameTittle, mainEnterUI,gameTipBox,
		newJounary_Gra, loadGame_Gra, exitGame_Gra
	);
	enterUIManager.TimersLoadIn(UITimer, environmentTimer);
}

void EnterWindow::UITimeTick()
{	
	enterUIManager.UIUpdate();
}

void EnterWindow::EstablishButtonSystem()
{
	AnimatedGraphicsView* newJounary_Gra = QObject::findChild<AnimatedGraphicsView*>("newJounary_Gra");
	AnimatedGraphicsView* loadGame_Gra = QObject::findChild<AnimatedGraphicsView*>("loadGame_Gra");
	AnimatedGraphicsView* exitGame_Gra = QObject::findChild<AnimatedGraphicsView*>("exitGame_Gra");

	buttonsManager = ButtonsManager(newJounary_Gra, loadGame_Gra, exitGame_Gra);

	connect(newJounary_Gra, &AnimatedGraphicsView::clicked, this, &EnterWindow::Selected1);
	connect(loadGame_Gra, &AnimatedGraphicsView::clicked, this, &EnterWindow::Selected2);
	connect(exitGame_Gra, &AnimatedGraphicsView::clicked, this, &EnterWindow::Selected3);
	connect(newJounary_Gra, &AnimatedGraphicsView::clickOver, this, &EnterWindow::Customize);
	connect(loadGame_Gra, &AnimatedGraphicsView::clickOver, this, &EnterWindow::LoadGame);
	connect(exitGame_Gra, &AnimatedGraphicsView::clickOver, this, &EnterWindow::Exit);
}
void EnterWindow::EstablishLoadUISystem()
{
	QList<LoadSlot> loadSlots;
	QString searchKey_Slot = "LoadSlot_";
	QString searchKey_SlotLabel = "_Label_";

	for (int slot_Index = 1; slot_Index <= 3; slot_Index++)
	{
		QString ob_Name = searchKey_Slot + QString::number(slot_Index);
		
		QList<QLabel*> slotLabels; 

		for (int slotLabel_Index = 1; slotLabel_Index <= 6; slotLabel_Index++)
		{
			QString	ob_Label_Name = ob_Name + searchKey_SlotLabel + QString::number(slotLabel_Index);
			QLabel* labelFont = QObject::findChild<QLabel*>(ob_Label_Name);
			slotLabels.append(labelFont);
		}

		AnimatedGraphicsView* aniGra = QObject::findChild<AnimatedGraphicsView*>(ob_Name);


		LoadSlot loadSlot = LoadSlot(aniGra, slotLabels);
		loadSlots.append(loadSlot);
	}

	QGraphicsView* loadUI_BG = QObject::findChild<QGraphicsView*>("LoadUI");

	loadUIManager = LoadUIManager(loadUI_BG, loadSlots);
	loadUIManager.SetValid(false);

	QObject::connect(loadSlots[0].GetAniGra(), &AnimatedGraphicsView::clickOver, this, &EnterWindow::LoadSlot1);
	QObject::connect(loadSlots[1].GetAniGra(), &AnimatedGraphicsView::clickOver, this, &EnterWindow::LoadSlot2);
	QObject::connect(loadSlots[2].GetAniGra(), &AnimatedGraphicsView::clickOver, this, &EnterWindow::LoadSlot3);

	
}

void EnterWindow::EstablishCustomizeSystem()
{		
	
	QString labelName = "SkillPoint_TextLabel";
	QLabel* skillPoint_TextLabel = QObject::findChild<QLabel*>(labelName);

	//Create CustomizeSlots
	QList<CustomizeSlot> propertyCustomize_Slots;
	QList<QPushButton* > increaseButtonList;
	QList<QPushButton* > decreaseButtonList;

	int skillPointEachProperty = 10;
	QString propertyGraKey = "PropertyGra_customizeSlot_";
	QString increaseButtonKey = "Increase_button_customizeSlot_";
	QString decreaseButtonKey = "Decrease_button_customizeSlot_";

	QList<QString> property_SP_Header;
	property_SP_Header.append("Zero-Empty");
	property_SP_Header.append("SkillPoint_ATK_");
	property_SP_Header.append("SkillPoint_DEF_");
	property_SP_Header.append("SkillPoint_HP_");

	for (int slotIndex = 1; slotIndex <= 3; slotIndex++)
	{	
		QList<QGraphicsView* > propertySkillPoint_Gras;

		QGraphicsView* slotPropertyGra 
			= QObject::findChild<QGraphicsView*>(propertyGraKey + QString::number(slotIndex));

		for (int skillPointIndex = 1; skillPointIndex <= skillPointEachProperty; skillPointIndex++)
		{
			QGraphicsView* skillPoint_Gra
				= QObject::findChild<QGraphicsView*>(property_SP_Header[slotIndex]+QString::number(skillPointIndex));

			propertySkillPoint_Gras.append(skillPoint_Gra);
		}

		QPushButton* increaseButton 
			= QObject::findChild<QPushButton* >(increaseButtonKey + QString::number(slotIndex));
		increaseButtonList.append(increaseButton);

		QPushButton* decreaseButton
			= QObject::findChild<QPushButton* >(decreaseButtonKey + QString::number(slotIndex));
		decreaseButtonList.append(decreaseButton);

		CustomizeSlot customizeSlot 
			= CustomizeSlot(slotPropertyGra, propertySkillPoint_Gras, increaseButton, decreaseButton);

		propertyCustomize_Slots.append(customizeSlot);
	}

	QList<AnimatedGraphicsView* > bulletSelectSlots;
	QList<QGraphicsView* > selectFrames;
	QString bulletSlotGraKey = "Bullet_CustomizeSlot_";
	QString selectFrameKey = "SelectFrame_";
	int bulletSlotCount = 5;

	for (int slotIndex = 1; slotIndex <= bulletSlotCount; slotIndex++)
	{
		AnimatedGraphicsView* bulletSelectSlot
			= QObject::findChild<AnimatedGraphicsView* >(bulletSlotGraKey + QString::number(slotIndex));
		
		bulletSelectSlots.append(bulletSelectSlot);

		//Re_adjust the first pos to be 0
		bulletSelectSlot->SetParameterMode(slotIndex - 1);
		bulletSelectSlot->EnterActiveMode();
		bulletSelectSlot->EndLoadInTask();
		bulletSelectSlot->SetClickCallBack(true);
		
		connect(bulletSelectSlot, SIGNAL(parameter_clicked(int)), this, SLOT(BulletSelect_SIGNAL_Launcher(int)));

		QGraphicsView* selectFrame
			= QObject::findChild<QGraphicsView* >(selectFrameKey + QString::number(slotIndex));

		selectFrames.append(selectFrame);
		
	}

	BulletCustomizeManager bulletCustomizeManager = BulletCustomizeManager(bulletSelectSlots, selectFrames);

	QPushButton* customizeOver_Button = QObject::findChild<QPushButton* >("CustomizeOver_Button");
	
	QGraphicsView* background_Gra = QObject::findChild<QGraphicsView* >("CustomizeUI");

	customizeManager
		= CustomizeManager(
			skillPoint_TextLabel,
			propertyCustomize_Slots,
			bulletCustomizeManager,
			customizeOver_Button,
			background_Gra
			);

	//SIGNAL AND SLOT INIT
	connect(increaseButtonList[0], SIGNAL(clicked()), this, SLOT(IncreaseATK()));
	connect(decreaseButtonList[0], SIGNAL(clicked()), this, SLOT(DecreaseATK()));

	connect(increaseButtonList[1], SIGNAL(clicked()), this, SLOT(IncreaseDEF()));
	connect(decreaseButtonList[1], SIGNAL(clicked()), this, SLOT(DecreaseDEF()));

	connect(increaseButtonList[2], SIGNAL(clicked()), this, SLOT(IncreaseHP()));
	connect(decreaseButtonList[2], SIGNAL(clicked()), this, SLOT(DecreaseHP()));

	connect(this, SIGNAL(BulletSelectSIGNAL(int)), this, SLOT(BulletSelect(int)));

	connect(customizeOver_Button, SIGNAL(clicked()), this, SLOT(CustomizeOver()));

	customizeManager.SetValid(false);
}	


void EnterWindow::environmentTimeTick()
{
	enterUIManager.environmentUpdate();
}

void EnterWindow::Selected1()
{
	buttonsManager.ButtonsSelected(1);
}

void EnterWindow::Selected2()
{
	buttonsManager.ButtonsSelected(2);
}

void EnterWindow::Selected3()
{
	buttonsManager.ButtonsSelected(3);
}

void EnterWindow::Customize()
{	
	customizeManager.SetValid(true);
}

void EnterWindow::IncreaseATK()
{
	customizeManager.IncreaseSkillPoint(0);
}

void EnterWindow::DecreaseATK()
{
	customizeManager.DecreaseSkillPoint(0);
}

void EnterWindow::IncreaseDEF()
{
	customizeManager.IncreaseSkillPoint(1);
}

void EnterWindow::DecreaseDEF()
{
	customizeManager.DecreaseSkillPoint(1);
}

void EnterWindow::IncreaseHP()
{
	customizeManager.IncreaseSkillPoint(2);
}

void EnterWindow::DecreaseHP()
{
	customizeManager.DecreaseSkillPoint(2);
}

void EnterWindow::BulletSelect_SIGNAL_Launcher(int i)
{	
	emit BulletSelectSIGNAL(i);
}

void EnterWindow::BulletSelect(int i)
{
	customizeManager.CallBulletSelect(i);
}

void EnterWindow::CustomizeOver()
{
	if (customizeManager.canStartJounary())
	{
		superBox->ImportNewJounaryCustomizeData(
			customizeManager.GetCustomizeProperty(), customizeManager.GetCustomizeBulletType());
		NewJounary();
	}
}

void EnterWindow::NewJounary()
{	
	superBox->WakeInputSystem();
	superBox->show();
	this->close();
	
}

void EnterWindow::LoadGame()
{
	//Open Load_System
	loadUIManager.SetValid(true);
}

void EnterWindow::LoadSlot1()
{
	if (loadUIManager.CanThisSlotLoad(0))
	{
		superBox->LoadModeToStartGame(0);
		superBox->show();
		this->close();
	}
}

void EnterWindow::LoadSlot2()
{
	if (loadUIManager.CanThisSlotLoad(1))
	{
		superBox->LoadModeToStartGame(1);
		superBox->show();
		this->close();
	}
}

void EnterWindow::LoadSlot3()
{
	if (loadUIManager.CanThisSlotLoad(2))
	{
		superBox->LoadModeToStartGame(2);
		superBox->show();
		this->close();
	}
}

void EnterWindow::Exit()
{
	this->close();
}

void EnterWindow::keyPressEvent(QKeyEvent* keycode)
{

}

void EnterWindow::keyReleaseEvent(QKeyEvent* keycode)
{
	switch (keycode->key())
	{	
		default:
			if (enterUIManager.CanCallEnterButton())
			{
				CallEnterButtons();

			}
			break;
	}
}

void EnterWindow::CallEnterButtons()
{	
	enterUIManager.CallEnterButtons();
		qDebug("CallEnterButtons");
}
