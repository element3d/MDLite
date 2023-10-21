#include "MenuPage.h"
#include <e3/Application.h>

MenuPage::MenuPage(e3::Element* pParent)
	: MenuPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});
}
