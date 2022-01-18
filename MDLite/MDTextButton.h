
#ifndef MDTextButton_H_
#define MDTextButton_H_

#include "private/MDTextButtonBase.h"
#include "MDIcon.h"
#include "MDTheme.h"

class E3_EXPORT MDTextButton : public MDTextButtonBase
{
public:
	MDTextButton(e3::Element* pParent = nullptr);

	void SetIcon(MDIcon* pIcon);
	void SetLabel(const std::string& label, bool translate = false);

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

	virtual void Render() override;
};

#endif // MDTextButton_H_

