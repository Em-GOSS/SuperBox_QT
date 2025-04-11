# # GossEmperis ‘s Qt aniMachine

Hello，welcome to gossemperis‘s Qt aniMachine，this is my first project which is build all on my own，Including but not limited to program and art。This project was built while I was learning Qt, so there will be a lot of stupid code written. But in the end this project works smoothly and is exciting!

### **Some Ani created in asprite**

*Convergence of Water Balloon*

![image](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/SuperBox/WaterIDLE.gif#pic_center)

*The spread of energy*

![image](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/SuperBox/EnergyIDLE.gif)

*Flying posion ball*

![image](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/SuperBox/Flying%20posionBall-exporx8t.gif)

*Save and load UI*

![image](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/SuperBox/LoadUI_SLOT_Empty_Leave1.gif)

*Slime*

![image](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/SuperBox/Evil_Slime1t.gif)

*SuperBox*

![image](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/SuperBox/SuperBox_Idle.gif)

### [演示视频 demo video]

[![](https://github.com/Em-GOSS/SuperBox_QT/blob/master/image/BG/SuperBOX_Tittle_p.png)](//player.bilibili.com/player.html?isOutside=true&aid=114302954505823&bvid=BV1GmdpYvEQj&cid=29306127525&p=1)

# Animation System

#### animation&&animator

The most basic component of the animation system,
animation, is a meta base class that serves as the playback data for animator, storing all the data needed to compose a piece of animation. The animator, as a player, is also the storage class for animation and the pool of animation objects. Animation can be played in various ways (concurrent play, wait play, loop play, specified loop count play, maintain play) and can be used in various scenarios.

```
#pragma once
#include "qstring.h"
#include "qlist.h"
/// <summary>
/// Warning: this class only use for read
/// Create as a Data Store
/// </summary>
class Animation
{
public:
	QList<QString> ani_Sheets;
	int ani_Count = NULL;
	int ani_Interval = NULL;

	Animation(QList<QString> sheets, int aniCount, int aniInterval)
	{
		this->ani_Sheets = sheets;
		this->ani_Count = aniCount;
		this->ani_Interval = aniInterval;
	}
	Animation()
	{

	}

	int GetTotalTicks()
	{
		return ani_Count * ani_Interval;
	}
};
```

```
Animator(QGraphicsView* ani_Base, QMap<QString, Animation> ani_Dic)
	{
		this->ani_Base = ani_Base;
		this->ani_Dic = ani_Dic;

		//Set the First IDLE Ani As the original ANI
		originSheetStyle = ani_Dic["idle"].ani_Sheets[0];
		ani_Base->setStyleSheet(originSheetStyle);
	}
```

I use the List of the image pos to build the animation。
and init it in the animator.

# How to build the AnimatedGraphicsView：

```
AnimatedGraphicsView(QWidget* parent = nullptr) : QGraphicsView::QGraphicsView(parent)
	{	
		aniTimer = new QTimer(this);
		aniTimer->setInterval(UI_Tick_Interval);
		QObject::connect(aniTimer, SIGNAL(timeout()), this, SLOT(TimeTick()));
		isUpdating = false;
	}
	
	AnimatedGraphicsView()
	{

	}
	~AnimatedGraphicsView()
	{	
		if(aniTimer != NULL)
			delete aniTimer;
	}

	void CreateAni(QMap<QString, Animation> graAniDic)
	{
		graAnimator = Animator(this, graAniDic);
		graAnimator.SetOriginStyle(this->styleSheet());
		isUpdating = false;
	}

	void EnterActiveMode()
	{
		isActiveMode = true;
		aniTimer->start();
	}

	void ExitActiveMode()
	{
		isActiveMode = false;
		aniTimer->stop();
	}

	void EndLoadInTask()
	{
		canClicked = true;
	}
	
	void SetClickCallBack(bool isCallBack)
	{
		isClickCallBack = isCallBack;
	}

	/// <summary>
	/// if the button is ParameterMode
	/// that means this button can be only use for send data
	/// dont play any ani;
	/// </summary>
	/// <param name="parameter"></param>
	void SetParameterMode(int parameter)
	{	
		isParameterMode = true;
		this->parameter = parameter;

	}
```

AnimatedGraphicsView is a custom component constructed by combining all the dynamic components in the project , a borderless animated click component , supports multiple modes of operation , internally linked signal slots , internal threads and animation pool .
I use the Qtimer to build a new thread, so all the ani will be **Parallel**

```mermaid
graph TD;
Animation-->AniMachine
Animator-->AniMachine-->AnimatedGraphicsView
Q_OBJECT-->GraphicsView-->AnimatedGraphicsView
QTimer-->TimeUpdater-->AnimatedGraphicsView
```

# SaveAndLoadSystem

In my project, I use the virtual method to build the saving and loading task

```
virtual void Saving(QFile* fileToSave) = 0;
virtual void Loading(QFile* fileToLoad) = 0;
```

And all the class which is inherited from isaveable will be add to the list of save and load task.
Save&&Load manager gives us the method to run all the saving or loading task.

```mermaid
graph TD;
Inventory-->ISaveable(Interface)
EnemyData-->ISaveable(Interface)
WeaponData-->ISaveable(Interface)
PlayerStatusData-->ISaveable(Interface)

ISaveable(Interface)--> SaveData
SaveData-->SaveManager-->LocalData
LocalData-->LoadManager
LoadManager-->LoadData
LoadData-->LocalData

GameData-->Inventory
GameData-->EnemyData
GameData-->WeaponData
GameData-->PlayerStatusData

LocalData -->PreparingData-->LoadGame
```
