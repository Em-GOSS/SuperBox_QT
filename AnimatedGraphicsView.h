#pragma once
#include "qgraphicsview.h"
#include "Setting.h"
#include "Animation.h"
#include "Animator.h"
#include "qtimer.h"
#include "TimeUpdater.h"
#include "qevent.h"
#include "qmap.h"
#include "qevent.h"
#include "qdebug.h"
class AnimatedGraphicsView : public QGraphicsView, public TimeUpdater 
{	
	Q_OBJECT
signals:
	void parameter_clicked(int parameter);
	void clicked();
	void clickOver();
private:
	bool canClicked = false;
	bool isActiveMode = false;
	bool isParameterMode = false;
	bool isClicked = false;
	bool isClickCallBack = true;
	

	int parameter = -1;

	Animator graAnimator;
	QTimer* aniTimer = NULL;
	
	void MouseEnter()
	{	
		isUpdating = true;
		graAnimator.PlayAnimation("enter", false, true);
	}
	
	void MouseLeave()
	{	
		isUpdating = true;
		graAnimator.PlayAnimation("leave", false, true);
	}
	
	void MouseClick()
	{	
		isUpdating = true;
		graAnimator.PlayAnimation("click", false, true);
	}

protected:
	bool event(QEvent* event) override
	{	
		if (!isClicked)
		{
			switch (event->type())
			{
			case QEvent::Enter:
				if (isActiveMode && isParameterMode == false)
					MouseEnter();
				break;

			case QEvent::Leave:
				if (isActiveMode && isParameterMode == false)
					MouseLeave();
				break;

			default:
				break;
			}
		}
		
		return QGraphicsView::event(event);
	}

	void mousePressEvent(QMouseEvent* event) override
	{	
		if (isParameterMode)
		{
			emit parameter_clicked(parameter);
		}
		else if (isClicked == false && isActiveMode && canClicked)
		{
			MouseClick();
			
			//if this gra Can't press than we should not freeze the animator and the AniTimer;
			if (isClickCallBack == false)
				return;

			isClicked = true;
				
			emit clicked();
		}
	}
	
	void FreezeAniSystem()
	{
		aniTimer->stop();
		isUpdating = false;
	}
	void UnFreezeAniSystem()
	{
		aniTimer->start();
		isUpdating = true;
	}
public:
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
//UI_Change

	void UpdateStyle()
	{
		this->setStyleSheet(graAnimator.GetOriginStyle());
	}

public slots:
	void TimeTick()
	{
		if (isUpdating)
		{	
			if (graAnimator.IsAniOver())
			{
				isUpdating = false;
				if (isClicked)
				{
					FreezeAniSystem();
					emit clickOver();
				}
			}
			else
			{
				graAnimator.Animating();
			}
		}
	}
		
};

