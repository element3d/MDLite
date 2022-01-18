#include "BottomNavigationBarPage.h"
#include <e3/Application.h>

BottomNavigationBarPage::BottomNavigationBarPage(e3::Element* pParent)
	: BottomNavigationBarPageBase(pParent)
{
	mBack->SetOnClickCallback([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});
}

