#include "SelectionControlsPage.h"
#include <e3/Application.h>

SelectionControlsPage::SelectionControlsPage(e3::Element* pParent)
	: SelectionControlsPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement();
	});

	mCheckbox1->SetOnChangeCallback([this](bool checked) {
		if (checked) mCheckTest1->SetBackgroundColor(MDColors::Primary::Get());
		else mCheckTest1->SetBackgroundColor(MDColors::Grey::Get());
	});
	mCheckbox2->SetOnChangeCallback([this](bool checked) {
		if (checked) mCheckTest2->SetBackgroundColor(MDColors::Primary::Get());
		else mCheckTest2->SetBackgroundColor(MDColors::Grey::Get());
	});
	mCheckbox3->SetOnChangeCallback([this](bool checked) {
		if (checked) mCheckTest3->SetBackgroundColor(MDColors::Primary::Get());
		else mCheckTest3->SetBackgroundColor(MDColors::Grey::Get());
	});

	mRadio1->SetOnChangeCallback([this](bool checked) {
		if (checked) mRadioTest1->SetBackgroundColor(MDColors::Primary::Get());
		else mRadioTest1->SetBackgroundColor(MDColors::Grey::Get());
	});
	mRadio2->SetOnChangeCallback([this](bool checked) {
		if (checked) mRadioTest2->SetBackgroundColor(MDColors::Primary::Get());
		else mRadioTest2->SetBackgroundColor(MDColors::Grey::Get());
	});
	mRadio3->SetOnChangeCallback([this](bool checked) {
		if (checked) mRadioTest3->SetBackgroundColor(MDColors::Primary::Get());
		else mRadioTest3->SetBackgroundColor(MDColors::Grey::Get());
	});

	mSwitch->SetOnChangeCallback([this](bool checked) {
		if (checked) mSwitchTest1->SetBackgroundColor(MDColors::Primary::Get());
		else mSwitchTest1->SetBackgroundColor(MDColors::Grey::Get());
	});
}
