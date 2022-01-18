
#ifndef MDFloatingActionButton_H_
#define MDFloatingActionButton_H_

#include "private/MDFloatingActionButtonBase.h"
#include "MDIcon.h"
#include "MDTheme.h"

class E3_EXPORT MDFloatingActionButton : public MDFloatingActionButtonBase
{
public:
	MDFloatingActionButton(e3::Element* pParent = nullptr);

	void SetIcon(e3::Element* pIcon);

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

	virtual void Render() override;
};

#endif // MDFloatingActionButton_H_

