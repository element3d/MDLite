#include "DrawerPage.h"
#include <e3/Application.h>

DrawerPage::DrawerPage(e3::Element* pParent)
	: DrawerPageBase(pParent)
{
	mBack->SetOnClickCallback([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});

	mDrawerButton->SetOnClickCallback([this](e3::MouseEvent*) {
		mDrawer->ShowModal();
	});
}
