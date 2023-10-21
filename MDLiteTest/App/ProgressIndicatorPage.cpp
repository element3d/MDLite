#include "ProgressIndicatorPage.h"
#include <e3/Application.h>

ProgressIndicatorPage::ProgressIndicatorPage(e3::Element* pParent)
	: ProgressIndicatorPageBase(pParent)
{
	mBack->SignalOnClick.Connect([this](e3::MouseEvent*) {
		GetApplication()->PopElement();
	});

	e3::Animation* pA = new e3::Animation();
	pA->Start(5, [this](float v) {
	
		//mCircularIndicator->SetValue(v);
		//mLinearIndicator->SetValue(v);
	}, [this]() {
	
	});
}
