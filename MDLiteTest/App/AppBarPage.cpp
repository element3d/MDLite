#include "AppBarPage.h"
#include <e3/Application.h>
#include "MDPopTransitionAnimation.h"
AppBarPage::AppBarPage(e3::Element* pParent)
	: AppBarPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});
}
