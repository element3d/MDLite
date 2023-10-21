#include "SnackbarPage.h"

SnackbarPage::SnackbarPage(e3::Element* pParent)
	: SnackbarPageBase(pParent)
{
	mButton->SignalOnClick.Connect([this](e3::MouseEvent*) {
		mSnackbar->Show();
	});
}
