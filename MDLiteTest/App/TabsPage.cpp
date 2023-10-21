#include "TabsPage.h"
#include <e3/Application.h>

TabsPage::TabsPage(e3::Element* pParent)
	: TabsPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement();
	});
}
