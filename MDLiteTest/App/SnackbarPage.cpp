#include "SnackbarPage.h"

SnackbarPage::SnackbarPage(e3::Element* pParent)
	: SnackbarPageBase(pParent)
{
	mButton->SetOnClickCallback([this](e3::MouseEvent*) {
		mSnackbar->Show();
	});
}
