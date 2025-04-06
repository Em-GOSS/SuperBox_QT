#include "SelectUI.h"

void SelectUI::SetValid(bool isValid)
{
	textLabel->setVisible(isValid);
	textLabel->setEnabled(isValid);

	selectUIBackGround->setVisible(isValid);
	selectUIBackGround->setEnabled(isValid);

	for (int i = 1; i <= 3; i++)
	{
		select_Boxs[i]->setVisible(isValid);
		select_Boxs[i]->setEnabled(isValid);
	}
	select_Button->setVisible(isValid);
	select_Button->setEnabled(isValid);
	
	descriptionBox->setVisible(isValid);
	descriptionBox->setEnabled(isValid);

	SetSelectButtonEnabled(false);
	select_Index = -1;
	isOpen = isValid;
}

void SelectUI::Item_Data_Inport(Item* items)
{
	for (int i = 1; i <= 3; i++)
	{
		itemsToSelect[i] = items[i];
		LoadSelectBox(i);
	}
}

void SelectUI::selecting(int i)
{	
	if (i < 1 || i>3)
		return;
	select_Index = i;
	LoadSelectBox(i);
	LoadSelectDescription(i);
	
}

Item SelectUI::GetCurrentSelectItem()
{
	return itemsToSelect[select_Index];
}


void SelectUI::LoadSelectBox(int i)
{
	select_Boxs[i]->setStyleSheet(itemsToSelect[i].GetSheetStyle());
	select_Boxs[i]->repaint();	
}

void SelectUI::LoadSelectDescription(int i)
{
	descriptionBox->setText(itemsToSelect[i].GetItemDescription());
	descriptionBox->repaint();
}




