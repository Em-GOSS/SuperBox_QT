#include "InventoryManager.h"

Item InventoryManager::GetRandomItem()
{
	
	int id = QRandomGenerator::global()->bounded(itemCount);
	
	return itemStore[id];
	
}
/// <summary>
/// The Item* index start from 1
/// </summary>
/// <returns></returns>
Item* InventoryManager::Build_SelectedItemData()
{
	Item* items = new Item[4];
	/*for (int i = 1; i <= 3; i++)
	{
		items[i] = GetRandomItem();
	}*/
	items[1] = itemStore[0];
	items[2] = itemStore[2];
	items[3] = itemStore[3];
	return items;
}


//The Saving and Loading below is no need for use, but still can be a saving data in future
void InventoryManager::Saving(QFile* fileToSave)
{
	qDebug("Inventory Saving"); 

	QDataStream dataStream(fileToSave);
	//Save the itemCount
	dataStream << itemCount;

	//Save The Inventory Details To File
	for (int i = 0; i < itemCount; i++)
	{
		dataStream << i << itemStore[i].GetItemID();
	}

}

void InventoryManager::Loading(QFile* fileToLoad)
{
	qDebug("Inventory Loading");

	QDataStream dataStream(fileToLoad);
	//Read the itemCount 
	int itemCount_Load;
	dataStream >> itemCount_Load;
	itemCount = itemCount_Load;

	QMap<int, int> posIDMap;
	
	int itemPos_Load;
	int itemID_Load;

	for (int i = 0; i < itemCount_Load; i++)
	{
		dataStream >> itemPos_Load >> itemID_Load;
		posIDMap.insert(itemPos_Load,itemID_Load);
		qDebug() << qint16(itemPos_Load) << qint16(itemID_Load);
	}
	
}
