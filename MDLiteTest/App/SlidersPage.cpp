#include "SlidersPage.h"
#include <e3/Application.h>

SlidersPage::SlidersPage(e3::Element *pParent)
		: SlidersPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent *) {
		GetApplication()->PopElement();
	});

	mSlider->SetOnChangeCallback([this](int v) {
		mInput->SetText(std::to_string(v));
	});
}
