#pragma once

#include <QMainWindow>
#include "QtGui/qevent.h"
#include "ui_EnterWindow.h"
#include "qtimer.h"
#include "Setting.h"
#include "qdebug.h"

#include "EnterUIManager.h"
#include "ButtonsManager.h"
#include "LoadUIManager.h"
#include "LoadSlot.h"

#include "CustomizeSlot.h"
#include "CustomizeManager.h"
#include "BulletCustomizeManager.h"

#include "qlabel.h"
#include "superbox.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EnterWindowClass; };
QT_END_NAMESPACE

class EnterWindow : public QMainWindow
{
	Q_OBJECT
	
signals:
	void BulletSelectSIGNAL(int bulletSelectIndex);
public:
	EnterWindow(QWidget *parent = nullptr);
	~EnterWindow();

	void LoadSuperBox(SuperBox* sb)
	{
		this->superBox = sb;
	}

private:
	Ui::EnterWindowClass *ui;
	SuperBox* superBox;

	QTimer* UITimer = new QTimer(this);
	QTimer* environmentTimer = new QTimer(this);

	EnterUIManager enterUIManager;
	ButtonsManager buttonsManager;
	LoadUIManager loadUIManager;
	CustomizeManager customizeManager;


	void EstablishUISystem();
	void EstablishButtonSystem();
	void EstablishLoadUISystem();
	void EstablishCustomizeSystem();
	void BuildTimeSystem();

	/// <summary>
	/// Input System
	/// </summary>
	void keyPressEvent(QKeyEvent* Keycode);
	void keyReleaseEvent(QKeyEvent* Keycode);


	void CallEnterButtons();

public slots:
	
	void UITimeTick();
	
	void environmentTimeTick();

	void Selected1();
	void Selected2();
	void Selected3();
	
	//Customize
	void Customize();

	void IncreaseATK();
	void DecreaseATK();

	void IncreaseDEF();
	void DecreaseDEF();

	void IncreaseHP();
	void DecreaseHP();

	void BulletSelect_SIGNAL_Launcher(int i);
	
	void BulletSelect(int i);

	void CustomizeOver();

	void NewJounary();
	void LoadGame();

	void LoadSlot1();
	
	void LoadSlot2();

	void LoadSlot3();

	void Exit();

};
