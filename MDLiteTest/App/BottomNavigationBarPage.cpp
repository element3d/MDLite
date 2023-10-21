#include "BottomNavigationBarPage.h"
#include <e3/Application.h>

BottomNavigationBarPage::BottomNavigationBarPage(e3::Element* pParent)
	: BottomNavigationBarPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});
}

