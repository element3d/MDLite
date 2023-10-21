#include "DialogPage.h"
#include <e3/Application.h>

DialogPage::DialogPage(e3::Element* pParent)
	: DialogPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement(new MDPopTransitionAnimation(this));
	});

	mDialogButton->SignalOnClick.Connect([this](e3::MouseEvent*) {
		mDialog->Show();
	});
}
