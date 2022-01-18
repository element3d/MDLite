#include "DialogPage.h"
#include <e3/Application.h>

DialogPage::DialogPage(e3::Element* pParent)
	: DialogPageBase(pParent)
{
	mBack->SetOnClickCallback([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});

	mDialogButton->SetOnClickCallback([this](e3::MouseEvent*) {
		mDialog->Show();
	});
}
