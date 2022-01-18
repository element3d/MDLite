#include "MDRadioGroup.h"

MDRadioGroup::MDRadioGroup() 
{

}

void MDRadioGroup::AddItem(MDCheckable* pItem)
{
	if (!mItems.size())
	{
		pItem->Check();
	}
	mItems.push_back(pItem);
	pItem->SetOnChangeCallback([this, pItem](bool checked) {
		if (!checked) return;
		for (auto pI : mItems)
		{
			if (pI != pItem)
			{
				pI->Uncheck();
			}
		}
	});
}