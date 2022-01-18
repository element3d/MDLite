
#ifndef MDRadio_H_
#define MDRadio_H_

#include "private/MDRadioBase.h"
#include "MDCheckable.h"
#include "MDTheme.h"

class E3_EXPORT MDRadio : public MDRadioBase, public MDCheckable
{
public:
	MDRadio(e3::Element* pParent = nullptr);

public:
	virtual bool OnClick(e3::MouseEvent*) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

public:
	void Check();
	void Uncheck();
	bool IsChecked();

private:
	e3::Dim mCheckDim;
	bool mChecked = false;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDRadio_H_

