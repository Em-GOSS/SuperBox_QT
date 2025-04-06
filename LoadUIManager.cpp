#include "LoadUIManager.h"

void LoadUIManager::InitSlotAniData()
{
	QMap<QString, Animation> aniDic;
	QList<QString> aniSheets;
	Animation idleAni;
	Animation enterAni;
	Animation leaveAni;
	Animation clickAni;

//Empty
	aniDic.clear();
	//idle
	aniSheets.clear(); 
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadUI_SLOT_Empty.jpg);");

	idleAni = Animation(aniSheets, 1, 1);
	aniDic.insert("idle", idleAni);

	//enter
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter1.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter2.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter3.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter4.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter5.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter6.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter7.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter8.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter9.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter10.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter11.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter12.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter13.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter14.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter15.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Enter16.jpg);");
	
	enterAni = Animation(aniSheets, 16, 1);
	aniDic.insert("enter", enterAni);

	//leave
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave1.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave2.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave3.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave4.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave5.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave6.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave7.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave8.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave9.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave10.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave11.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave12.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave13.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Leave14.jpg);");

	leaveAni = Animation(aniSheets,14, 1);
	aniDic.insert("leave", leaveAni);

	//click
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click1.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click2.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click3.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click4.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click5.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click6.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click7.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click8.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click9.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click10.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click11.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/Empty/LoadUI_SLOT_Empty_Click12.jpg);");
	

	clickAni = Animation(aniSheets, 12, 1);
	aniDic.insert("click", clickAni);

	slotAniDics.insert("Empty",aniDic);

//!Empty
	aniDic.clear();
	//idle
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadUI_SLOT.jpg);");

	idleAni = Animation(aniSheets, 1, 1);
	aniDic.insert("idle", idleAni);

	//enter
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter1.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter2.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter3.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter4.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter5.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter6.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter7.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter8.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter9.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter10.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter11.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter12.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter13.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter14.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter15.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Enter16.jpg);");

	enterAni = Animation(aniSheets, 16, 1);
	aniDic.insert("enter", enterAni);

	//leave
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave1.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave2.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave3.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave4.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave5.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave6.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave7.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave8.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave9.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave10.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave11.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave12.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave13.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Leave14.jpg);");
	leaveAni = Animation(aniSheets, 14, 1);
	aniDic.insert("leave", leaveAni);

	//click
	aniSheets.clear();
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click1.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click2.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click3.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click4.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click5.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click6.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click7.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click8.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click9.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click10.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click11.jpg);");
	aniSheets.append("border-image: url(:/image/LoadSystem/LoadSlotAni/!Empty/LoadUI_SLOT_Click12.jpg);");

	clickAni = Animation(aniSheets, 12, 1);
	aniDic.insert("click", clickAni);

	slotAniDics.insert("!Empty", aniDic);
}

void LoadUIManager::InitSaveDataKey()
{	
	dataKeys.append("/playerProperty.dat");
	dataKeys.append("/BulletDetails.dat");
	dataKeys.append("/EnemyCreater.dat");
	dataKeys.append("/BagDetail.dat");
}

void LoadUIManager::InitStream(QDataStream& dataStream)
{
	dataStream.setVersion(QDataStream::Qt_5_0);
	dataStream.setByteOrder(QDataStream::LittleEndian);
}

void LoadUIManager::EstablishSlotAnimator()
{
	for (int i = 0; i < loadSlots.count(); i++)
	{
		if (loadSlots[i].isEmpty())
		{
			loadSlots[i].CreateSlotAni(slotAniDics["Empty"], loadSlots[i].isEmpty());
		}
		else
		{
			loadSlots[i].CreateSlotAni(slotAniDics["!Empty"], loadSlots[i].isEmpty());
		}
	
		loadSlots[i].UpdateSlotUI();
	}
}
/// <summary>
/// foreach all saveSlot_Folder, 
/// if this dir is exists, then make a dataGroup to loadIn slotUI,
/// else set the slot to be empty format
/// </summary>
void LoadUIManager::ReadAndLoadLocalData()
{	
	qDebug("LoadUIData Loading");

	//Foreachslots
	for (int slotIndex = 0; slotIndex < loadSlots.count(); slotIndex++)
	{	
		QString finalDirPos = dataSavePos + QString::number(slotIndex);
		QDir slotSaveDir(finalDirPos);

		// check the path 
		if (slotSaveDir.exists())
		{
			//find the loadUIsaveData 
			QString finalSavePos = finalDirPos + LoadUIDataName;
			QFile loadUIDataFile(finalSavePos);

			if (loadUIDataFile.exists())
			{	
				QList<int> slotNumberList;

				QDataStream dataStream(&loadUIDataFile);

				InitStream(dataStream);
				
				int dataCount;
				
				loadUIDataFile.open(QIODevice::ReadOnly);
				//first we should read the count of the map
				dataStream >> dataCount;

				int data_INT;
				for (int dataIndex = 0; dataIndex < dataCount; dataIndex++)
				{	
					dataStream >> data_INT;
					slotNumberList.append(data_INT);
				}

				loadUIDataFile.close();
				loadSlots[slotIndex].ImportDataFromSaveFile(slotNumberList);
				
			}
			else
			{
				qDebug("Warning: There is no loadingUI_File in this slot folder!");
			}
		}
		else
		{
			qDebug("Empty Slot");
		}

		
	}
}

bool LoadUIManager::CanThisSlotLoad(int slotIndex)
{	
	if (loadSlots[slotIndex].isEmpty())
		return false;
	else
		return true;
}

