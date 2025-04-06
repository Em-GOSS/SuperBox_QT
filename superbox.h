#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QMainWindow>
#include "ui_superbox.h"
#include "Bag.h"
#include "SelectUI.h"
#include "PropertiesUI.h"
#include "BattleWindow.h"

#include "ItemCreater.h"
#include "EnemyCreater.h"
#include "InventoryManager.h"

#include "BulletManager.h"
#include "Enemy.h"
#include "Player.h"

#include "QtConcurrent/QtConcurrent"
#include "TimeManager.h"
#include "TimeTest.h"

#include "Enums.h"

#include "EntityProperty.h"
#include "BattleDetails.h"
#include "SaveDetails.h"
#include "SaveManager.h"
#include "LoadManager.h"
#include "SaveIcon.h"

class SuperBox : public QMainWindow
{
    Q_OBJECT
signals:
    void PlayerTimer_TimeOut();

    void EnemyTimer_TimeOut();

    void UITimer_TimeOut();
    void PhysicTimer_TimeOut();
public:
    SuperBox(QWidget *parent = nullptr);
    ~SuperBox();

    void WakeInputSystem()
    {
        //Now current widget class was focused
        this->grabKeyboard();
    }

    void ImportNewJounaryCustomizeData(EntityProperty customize_Property, QList<BulletType> customize_BulletTypes);

    void LoadModeToStartGame(int loadslot);

  
   
private:
    Ui::SuperBoxClass ui;


    //Data Init
    ItemCreater itemCreater;
    EnemyCreater enemyCreater;
    InventoryManager inventoryManager = InventoryManager();
    EntityProperty playerOriginProperty = EntityProperty(5,5,5);

    //UI Init
    Bag mainBag = Bag();
    SelectUI mainSelectUI = SelectUI();
    PropertiesUI propertiesUI = PropertiesUI();

    BattleWindow* battleWindow = new BattleWindow();

    //Entity Create()
    Player* player;
    
    //BattleSystm
    BulletManager* bulletManager;

    //TimeSystem
    QFuture<void> BattleWindowFuture;
    TimeTest tt;
    QTimer* uiTimer;
    QTimer* playerTimer;
    QTimer* enemyTimer;
    QTimer* physicTimer;
    TimeManager timeManager;

    //SaveLoadSystem
    int currentSaveSlotIndex = 0;
    SaveIcon saveIcon;
    SaveManager saveManager;
    LoadManager loadManager;

    
    void DataInitProcessing();
    void SetStartWindow();
    
    
    void PlayerInit();

    void Create_Bag();
    void Create_SelectUI();
    void Create_PropertiesUI();
    
    void CreateBattleSystem();

    void BuildTimeSystem();

    
    void EstablishSaveSystem();
    void EstablishLoadSystem();

    void UpdateDataToPropertiesUI();

    /// <summary>
    /// Input System
    /// </summary>
    void keyPressEvent(QKeyEvent* Keycode);
    void keyReleaseEvent(QKeyEvent* Keycode);

    //Test
    void DebugItemStore(int index);

   


public slots:
#pragma region Bag
    void CallBag();
#pragma endregion

#pragma region UI
    void CallSelectUI();
    void CallSelect();
    void CallBattle();

    void Selecting(int i);
    void Selecting_1();
    void Selecting_2();
    void Selecting_3();

    void SwitchBullet_Left();
    void SwitchBullet_Right();

    void UI_TimeTick();
    void PlayerUpdate();
    void EnemyUpdate();

    void Physic_TimeTick();
    void PlayerBulletUpdate();
    void EnemyBulletUpdate();

    void SaveIconSave();
#pragma endregion

#pragma region SaveLoadSystem
    //SaveSystem
    void Save(int saveSlot_ID);

    void Load(int saveSlot_ID);
#pragma endregion

#pragma region ExternMethod
    //None 
#pragma endregion

};
