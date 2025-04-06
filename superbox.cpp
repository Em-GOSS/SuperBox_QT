#include "superbox.h"
#include "qtimer.h"
#include <QtGui/qevent.h>
#include <qdebug.h>
#include <qpushbutton.h>
#include <qframe.h>
#include <qgraphicsview.h>
#include "Player.h"
#include "Setting.h"
using namespace std;

SuperBox::SuperBox(QWidget *parent) : QMainWindow(parent)
{   
    ui.setupUi(this);
    
    //…Ë÷√¥∞ø⁄±ÍÃ‚
    DataInitProcessing();
    
    //visable Object create
    PlayerInit();
    SetStartWindow();

    Create_Bag();
    Create_SelectUI();
    Create_PropertiesUI();

    CreateBattleSystem();
    //DebugItemStore(6);
    BuildTimeSystem();
    EstablishSaveSystem();
    EstablishLoadSystem();

}

SuperBox::~SuperBox()
{

}

void SuperBox::DataInitProcessing()
{
    itemCreater = ItemCreater();
    inventoryManager = InventoryManager(itemCreater.CreateItems(), itemCreater.GetItemCount());
}

void SuperBox::PlayerInit()
{
    QGraphicsView* playerGraphic = findChild<QGraphicsView*>("Player");
    player = new Player(playerGraphic, playerOriginProperty);
    player->SetValid(false);
}

//_________________________________________________________________________________________________________________________________________
//UICreate

void SuperBox::SetStartWindow()
{
    setWindowTitle("”Ó÷ÊŒﬁµ–øÒ◊ßÏ≈ø·∞‘ÃÏ¬›–˝…¡π‚∑…ÃÏBOX_The Cosmic invincible crazy drag cool Decepticon spiral flash flying BOX");
    QPushButton* startButton = findChild<QPushButton*>("startButton");
    connect(startButton, SIGNAL(clicked()), this, SLOT(CallSelectUI()));
}


void SuperBox::Create_Bag()
{   
    QFrame* bagSlots[20] = { NULL };
    QGraphicsView* bagBackGround = NULL;
    QPushButton* bagButton;
    bagButton = findChild<QPushButton*>("Fox");
    bagBackGround = findChild<QGraphicsView*>("Bag_BackGround");
    //Find slots by key;
    char key[7] = { 's','l','o','t'};
    for (int i = 0; i <= 9; i++)
    {
        key[4] = char(48 + i);
        bagSlots[i] = findChild<QFrame*>(key);
    }

    mainBag = Bag( bagSlots, bagBackGround, bagButton);
    mainBag.Init();
    mainBag.ITEM_DETAIL_Library_LoadIn(itemCreater.GetItemCreateList());

    connect(bagButton, SIGNAL(clicked()), this, SLOT(CallBag()));
}

void SuperBox::Create_SelectUI()
{   
    QLabel* textLabel = NULL;
    QGraphicsView* selectUIBackground = NULL;
    QPushButton* selectedBoxs[5] = { NULL };
    QPushButton* selectButton = NULL;
    QLabel* descriptionBox = NULL;

    textLabel = findChild<QLabel*>("SelectLabel");

    selectUIBackground = findChild<QGraphicsView*>("SelectUI");

    selectedBoxs[1] = findChild<QPushButton*>("Select_Button1");
    selectedBoxs[2] = findChild<QPushButton*>("Select_Button2");
    selectedBoxs[3] = findChild<QPushButton*>("Select_Button3");

    selectButton = findChild<QPushButton*>("SlectButton");

    descriptionBox = findChild<QLabel*>("DesCriptonBox");
    
    mainSelectUI = SelectUI(textLabel, selectUIBackground, selectedBoxs, selectButton,descriptionBox);

      
    connect(selectButton, SIGNAL(clicked()), this, SLOT(CallSelect()));

    connect(selectedBoxs[1], SIGNAL(clicked()), this, SLOT(Selecting_1()));
    connect(selectedBoxs[2], SIGNAL(clicked()), this, SLOT(Selecting_2()));
    connect(selectedBoxs[3], SIGNAL(clicked()), this, SLOT(Selecting_3()));

/// <summary>
///  Disabled in 2024 03 24, waiting for reconstructe
/// </summary>
/// //__________________________________________________________________________________________________________
   /* for (int i = 1; i <= 3; i++)
    {
        signalMapper->setMapping(selectedBoxs[i], i);
        connect(selectedBoxs[i], SIGNAL(click()), signalMapper, SLOT(Selecting(int)));
    }

    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(onStepIncreased(int)));
    */
//______________________________________________________________________________________
}

void SuperBox::Create_PropertiesUI()
{
    QGraphicsView* propertyGraphics[5] = { NULL };
    QLabel* propertyTexts[5] = { NULL };
    QGraphicsView* propertiesUI_Background = NULL;
    
    propertyGraphics[1] = findChild<QGraphicsView*>("Property_Attack");
    propertyGraphics[2] = findChild<QGraphicsView*>("Property_Defence");
    propertyGraphics[3] = findChild<QGraphicsView*>("Property_HP");

    propertyTexts[1] = findChild<QLabel*>("Property_AttackLabel");
    propertyTexts[2] = findChild<QLabel*>("Property_DefenceLabel");
    propertyTexts[3] = findChild<QLabel*>("Property_HPLabel");

    propertiesUI_Background = findChild<QGraphicsView*>("PropertiesUI");

    propertiesUI = PropertiesUI(propertyGraphics, propertyTexts, propertiesUI_Background);
    UpdateDataToPropertiesUI();
}

//_________________________________________________________________________________________________________________________________________
//Battle

void SuperBox::CreateBattleSystem()
{   
    QGraphicsView* bg = findChild<QGraphicsView*>("BattleWindow");

    //initialize bulletSystem
    bulletManager = new BulletManager(ui.BulletSlot);
    //initialize enemyCreater
    enemyCreater = EnemyCreater(bg);

    //BattleWindow initialize
    battleWindow = new BattleWindow(bg, ui.PowerUI, bulletManager);
    battleWindow->SetValid(false);
}


//_________________________________________________________________________________________________________________________________________
//TimeSystem
void SuperBox::BuildTimeSystem()
{
    uiTimer = new QTimer(this);
    uiTimer->setInterval(UI_Tick_Interval);
    uiTimer->start();
    
    physicTimer = new QTimer(this);
    physicTimer->setInterval(PHYSIC_Tick_Interval);
    physicTimer->start();

    playerTimer = new QTimer(this);
    playerTimer->setInterval(ENTITY_Tick_Interval);
    QObject::connect(playerTimer, SIGNAL(timeout()), this, SLOT(PlayerUpdate()));

    enemyTimer = new QTimer(this);
    enemyTimer->setInterval(ENTITY_Tick_Interval);
    QObject::connect(enemyTimer, SIGNAL(timeout()), this, SLOT(EnemyUpdate()));

    //initTimeManager
    timeManager = TimeManager(uiTimer, physicTimer);
    timeManager.RegisterNewTimer("playerTimer", playerTimer);
    timeManager.RegisterNewTimer("enemyTimer", enemyTimer);
    
    //Build SIGNAL Launcher
        //In the UI_stream make the coroutine to speed up the program, eastablish the one-many system
    QObject::connect(uiTimer, SIGNAL(timeout()), this, SLOT(UI_TimeTick()));

    //Build SIGNAL Launcher
       //In the UI_stream make the coroutine to speed up the program, eastablish the one-many system
    QObject::connect(physicTimer, SIGNAL(timeout()), this, SLOT(Physic_TimeTick()));   
    QObject::connect(this, SIGNAL(PhysicTimer_TimeOut()), this, SLOT(PlayerBulletUpdate()));
    QObject::connect(this, SIGNAL(PhysicTimer_TimeOut()), this, SLOT(EnemyBulletUpdate()));
}



void SuperBox::EstablishSaveSystem()
{      
    QPushButton* push_SaveIcon = QObject::findChild<QPushButton* >("SaveIcon");
    saveIcon = SaveIcon(push_SaveIcon);

    connect(push_SaveIcon, SIGNAL(clicked()), this, SLOT(SaveIconSave()));
    

    //saveManager.RegisterNewSaveTask(&inventoryManager);
    saveManager.RegisterNewSaveTask(player);
    saveManager.RegisterNewSaveTask(bulletManager);
    saveManager.RegisterNewSaveTask(&enemyCreater);
    saveManager.RegisterNewSaveTask(&mainBag);
}

void SuperBox::EstablishLoadSystem()
{   
    //loadManager.RegisterNewLoadTask(&inventoryManager);
    loadManager.RegisterNewLoadTask(player);
    loadManager.RegisterNewLoadTask(bulletManager);
    loadManager.RegisterNewLoadTask(&enemyCreater);
    loadManager.RegisterNewLoadTask(&mainBag);
    

    //Send dataMap to ISaveables
    saveManager.MountExtraDataToSaveTasks();
}



void SuperBox::ImportNewJounaryCustomizeData(EntityProperty customize_Property, QList<BulletType> customize_BulletTypes)
{
    player->SetProperty(customize_Property);
    propertiesUI.UpdateProperties(player->GetProperty());

    //There is only 2 slot for the bulletImport
    bulletManager->BulletImport(customize_BulletTypes[0]);
    bulletManager->BulletImport(customize_BulletTypes[1]);
    bulletManager->UpdateBulletData();
    bulletManager->UpdateBulletUI();
}

void SuperBox::LoadModeToStartGame(int loadslot)
{
    
    WakeInputSystem();
    Load(loadslot);
    
}

//_________________________________________________________________________________________________________________________________________
//Data Export
void SuperBox::UpdateDataToPropertiesUI()
{
    propertiesUI.UpdateProperties(
        player->entityProperty.Attack(),
        player->entityProperty.Defence(),
        player->entityProperty.HP()
    );
}


//Input 

void SuperBox::keyPressEvent(QKeyEvent* keycode) {
    switch (keycode->key()) {
    case Qt::Key::Key_B:
        mainBag.KeyTrigger(true);
        break;
    }
 
}

void SuperBox::keyReleaseEvent(QKeyEvent* keycode) {
    switch (keycode->key()) {
    case Qt::Key_B:
        mainBag.KeyTrigger(false);
        break;

    case Qt::Key_Q:
        SwitchBullet_Left();
        break;

    case Qt::Key_E:
        SwitchBullet_Right();
        break;

    case Qt::Key_A:
        saveIcon.SwitchSaveSlot(true);
        currentSaveSlotIndex = saveIcon.GetCurrentSaveSlotIndex();
        break;
    
    case Qt::Key_D:
        saveIcon.SwitchSaveSlot(false);
        currentSaveSlotIndex = saveIcon.GetCurrentSaveSlotIndex();
        break;

    case Qt::Key_S:
        //QuickSave
        Save(0);
        break;

    case Qt::Key_L:
        //QuickLoad
        Load(0);
        break;
    }
}



//Slots//_____________________________________________________________________________________________________________


//Bag
void SuperBox::CallBag()
{
    mainBag.BagClick();
}


#pragma region SelectUI
//Select
void SuperBox::CallSelectUI()
{   
    if (mainSelectUI.canOpen())
    {
        mainSelectUI.Item_Data_Inport(inventoryManager.Build_SelectedItemData());
        mainSelectUI.SetValid(true);
    }
}

void SuperBox::CallSelect()
{
    if (mainSelectUI.canExit())
    {   
        //ItemUpdate
        Item newItem = mainSelectUI.GetCurrentSelectItem();
        mainBag.AddNewItem(newItem);

        //Close UI
        mainSelectUI.SetValid(false);

        //Equip
        player->EquipItem(newItem.GetequipEffectDic());
        UpdateDataToPropertiesUI();

        //Prepare for battle
        Enemy* enemy = enemyCreater.CreateEnemy(EnemyType::Evil_Slime);
        battleWindow->ImportEntity(player,enemy);
        
        //Enter Battle Window
        CallBattle();
    }
}

void SuperBox::CallBattle()
{
    battleWindow->BarsInitialize();
    battleWindow->SetValid(true);
    timeManager.SetBattleTimer(true);
}

void SuperBox::Selecting(int i)
{
    mainSelectUI.selecting(i);
    mainSelectUI.SetSelectButtonEnabled(true);
}

void SuperBox::Selecting_1()
{
    Selecting(1);
}

void SuperBox::Selecting_2()
{
    Selecting(2);
}

void SuperBox::Selecting_3()
{
    Selecting(3);
}

#pragma endregion


#pragma region BulletSystem

void SuperBox::SwitchBullet_Left()
{
    bulletManager->SwitchBullet(true);
}

void SuperBox::SwitchBullet_Right()
{
    bulletManager->SwitchBullet(false);
}

#pragma endregion


#pragma region TimeSystem
void SuperBox::UI_TimeTick()
{  
    if (battleWindow->CanProcessUpdate())
        emit UITimer_TimeOut();
}
void SuperBox::PlayerUpdate()
{   
    if (battleWindow->CanProcessUpdate())
        battleWindow->PlayerUpdateProcess();
}

void SuperBox::EnemyUpdate()
{   
    if (battleWindow->CanProcessUpdate())
        battleWindow->EnemyUpdateProcess();
}


void SuperBox::Physic_TimeTick()
{   
    if(battleWindow->CanProcessUpdate())
        emit PhysicTimer_TimeOut();
}

void SuperBox::PlayerBulletUpdate()
{
    battleWindow->PlayerBulletsProcess();      
}

void SuperBox::EnemyBulletUpdate()
{
    battleWindow->EnemyBulletsProcess();
}
void SuperBox::SaveIconSave()
{
    Save(currentSaveSlotIndex);
}
#pragma endregion


#pragma region SaveLoadSystem

void SuperBox::Save(int saveSlot_ID)
{
    //is part was discarded in 2024/5/13
    //it still can be the 
    //We use the  more convenient way to save file - ISaveable interface
       /* BattleDetails battleDetails = BattleDetails(
            inventoryManager.GetItemCount(),
            bulletManager->GetBulletCount(),
            enemyCreater.GetCurrentEnemyIndex(),
            bulletManager->GetCurrentBulletIndex(),
            bulletManager->GetBulletStore()
        );
        SaveDetails dataToSave(player->GetProperty(),battleDetails);
        saveManager.Save(dataToSave, saveSlot_ID);*/

    saveManager.ProcessAllSaveTask(saveSlot_ID);

}

void SuperBox::Load(int saveSlot_ID)
{
    loadManager.ProcessAllLoadTask(saveSlot_ID);

    //Update UI
    propertiesUI.UpdateProperties(player->GetProperty()); 
}

#pragma endregion


#pragma region Test
void SuperBox::DebugItemStore(int index)
{
    Item* items;
    items = itemCreater.CreateItems();
    for (int i = 0; i < index; i++)
    {
        qDebug() << items[i].GetSheetStyle() << " " << items[i].GetItemName() << " " << items[i].GetItemDescription() << endl;
        qDebug() << "A" << qint64(items[i].GetequipEffectDic()[1]) << "D" << qint64(items[i].GetequipEffectDic()[2]) << "Hp" << qint64(items[i].GetequipEffectDic()[3]);
    }
}
#pragma endregion



