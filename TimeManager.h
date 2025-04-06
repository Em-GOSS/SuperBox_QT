#pragma once
#include "qtimer.h"
#include "qlist.h"
#include "qmap.h"
class TimeManager
{		
private:
	QTimer* uiTimer = NULL;
	QTimer* physicTimer = NULL;

	int	TimerMaxIndex = -1;

	QList<QTimer*> Final_TimeMachine;
	QMap<QString, int> TimerIndexDic;
public:
	TimeManager()
	{

	}
	TimeManager(QTimer* uiTimer, QTimer* physicTimer)
	{
		this->uiTimer = uiTimer;
		RegisterNewTimer("uiTimer", uiTimer);

		this->physicTimer = physicTimer;
		RegisterNewTimer("physicTimer", physicTimer);
	}
	
	void RegisterNewTimer(QString timerName,QTimer* timer)
	{
		TimerMaxIndex++;
		Final_TimeMachine.append(timer);
		TimerIndexDic.insert(timerName, TimerMaxIndex);
	}

	void SetBattleTimer(bool isTiming)
	{
		if (isTiming)
		{
			Final_TimeMachine[TimerIndexDic["playerTimer"]]->start();
			Final_TimeMachine[TimerIndexDic["enemyTimer"]]->start();
		}
		else
		{
			Final_TimeMachine[TimerIndexDic["playerTimer"]]->stop();
			Final_TimeMachine[TimerIndexDic["enemyTimer"]]->stop();
		}
	}


	void StopAllTimer()
	{	
		for (int i = 0; i < Final_TimeMachine.count(); i++)
		{
			Final_TimeMachine[i]->stop();
		}
	}

	void StartAllTimer()
	{
		for (int i = 0; i < Final_TimeMachine.count(); i++)
		{
			Final_TimeMachine[i]->start();
		}
	}

	

};

