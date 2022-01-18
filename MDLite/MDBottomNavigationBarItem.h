
#ifndef MDBottomNavigationBarItem_H_
#define MDBottomNavigationBarItem_H_

#include "private/MDBottomNavigationBarItemBase.h"
#include "MDTheme.h"

class E3_EXPORT MDBottomNavigationBarItem : public MDBottomNavigationBarItemBase
{
public:
	MDBottomNavigationBarItem(e3::Element* pParent = nullptr);

	void SetTitle(const std::string& title, bool translate = false);
	void SetIcon(const std::string& iconName);

	void Select();
	void Unselect();

	virtual bool OnClick(e3::MouseEvent*) override;
	virtual void OnMouseHover(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;
	virtual void Render() override;

private:
	void _DismissRipple();

private:
	e3::Animation* mAnimation = nullptr;
	e3::Animation* mRippleAnimation = nullptr;
	bool mSelected = false;
};

#endif // MDBottomNavigationBarItem_H_

