
#ifndef MDButton_H_
#define MDButton_H_

#include "private/MDButtonBase.h"
#include "MDIcon.h"
#include "MDTheme.h"

class E3_EXPORT MDButton : public MDButtonBase
{
public:
	MDButton(e3::Element* pParent = nullptr);

	void SetIcon(MDIcon* pIcon);
	void SetLabel(const std::string& label, bool translate = false);

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

	virtual void Render() override;
};

#endif // MDButton_H_

