#include "MenuPage.h"
#include <e3/Application.h>

MenuPage::MenuPage(e3::Element* pParent)
	: MenuPageBase(pParent)
{
	mBack->SetOnClickCallback([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});
}
