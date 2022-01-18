#include "ButtonsPage.h"
#include <e3/Application.h>

ButtonsPage::ButtonsPage(e3::Element* pParent)
	: ButtonsPageBase(pParent)
{
	mBack->SetOnClickCallback([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});
}
