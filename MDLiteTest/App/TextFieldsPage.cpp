#include "TextFieldsPage.h"
#include <e3/Application.h>

TextFieldsPage::TextFieldsPage(e3::Element* pParent)
	: TextFieldsPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement();
	});
}
