
#ifndef MDTab_H_
#define MDTab_H_

#include "private/MDTabBase.h"
#include "MDTheme.h"

class E3_EXPORT MDTab : public MDTabBase
{
	friend class MDTabBar;
public:
	MDTab(e3::Element* pParent = nullptr);

	void SetTextLabel(const std::string& textLabel);
	void SetLeadingIcon(const std::string& leadingIcon);

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

	virtual void Render() override;

private:
	void Select();
	void Unselect();
};

#endif // MDTab_H_

