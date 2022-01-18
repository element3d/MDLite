#include "MDCheckable.h"
#include "MDRadioGroup.h"

void MDCheckable::SetGroup(MDRadioGroup* pGroup)
{
	pGroup->AddItem(this);
}

void MDCheckable::Check() 
{
	mChecked = true;
	for (OnChangeCallback& c : mOnChangeCallbacks)
		c(true);
	//if (mOnChangeCallback) mOnChangeCallback(true);
}

void MDCheckable::Uncheck() 
{
	mChecked = false;
	for (OnChangeCallback& c : mOnChangeCallbacks)
		c(false);
	//if (mOnChangeCallback) mOnChangeCallback(false);
}

bool MDCheckable::IsChecked() 
{
	return mChecked;
}

void MDCheckable::SetOnChangeCallback(OnChangeCallback c) { mOnChangeCallbacks.push_back(c); }