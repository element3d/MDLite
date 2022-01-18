
#ifndef ProgressIndicatorPage_H_
#define ProgressIndicatorPage_H_

#include "private/ProgressIndicatorPageBase.h"

class E3_EXPORT ProgressIndicatorPage : public ProgressIndicatorPageBase
{
public:
	ProgressIndicatorPage(e3::Element* pParent = nullptr);

	void Render() override
	{
		ProgressIndicatorPageBase::Render();
	}
};

#endif // ProgressIndicatorPage_H_

