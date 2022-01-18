
#ifndef MDTabBar_H_
#define MDTabBar_H_

#include "private/MDTabBarBase.h"
#include "MDTab.h"
#include "MDTabBarView.h"

class E3_EXPORT MDTabBar : public MDTabBarBase
{
	typedef std::function<void(MDTab*)> OnTabSelectCallback;
public:
	MDTabBar(e3::Element* pParent = nullptr);

	virtual void AddElement(e3::Element* pTab);
	void AddElement(MDTab* pTab);

public:
	void SetIsScrollable(bool isScrollable);
	void SetTabBarView(MDTabBarView* pTabBarView);
	void SetOnTabSelectCallback(OnTabSelectCallback onTabSelectCallback);

private:
	bool mIsScrollable = false;
	MDTabBarView* mTabBarView = nullptr;
	OnTabSelectCallback mOnTabSelectCallback;
	e3::Animation* mAnimation = nullptr;
};

#endif // MDTabBar_H_

