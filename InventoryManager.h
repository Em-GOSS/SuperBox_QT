#pragma once
#include "Item.h"
#include "qlist.h"
#include "qrandom.h"
#include "ISaveable.h"
class InventoryManager : public ISaveable
{
private:
	Item* itemStore ;
	int  itemCount = 0;
public:
	InventoryManager() : ISaveable("/Inventory.dat")
	{
		itemStore = new Item;
	}
	
	InventoryManager(Item *items,int itemCount) : ISaveable("/Inventory.dat")
	{	
		this->itemCount = itemCount;
		itemStore = new Item[itemCount];

		for (int i = 0; i < itemCount; i++)
		{
			itemStore[i] = items[i];
		}
	}

	Item GetRandomItem();
	
	Item* Build_SelectedItemData();

	int GetItemCount()
	{
		return itemCount;
	}

	void LoadItemWithIDList()
	{

	}

	// ͨ�� ISaveable �̳�
	virtual void Saving(QFile* fileToSave) override;

	// ͨ�� ISaveable �̳�
	virtual void Loading(QFile* fileToLoad) override;
};

