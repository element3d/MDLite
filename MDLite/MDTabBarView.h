
#ifndef MDTabBarView_H_
#define MDTabBarView_H_

#include "private/MDTabBarViewBase.h"

class MDTabBar;
class E3_EXPORT MDTabBarView : public MDTabBarViewBase
{
public:
	MDTabBarView(e3::Element* pParent = nullptr);

	void SetTabBar(MDTabBar* pTabBar);
	virtual void AddElement(e3::Element* pPage) override;
	void SetIndex(int index);

private:
	int mIndex = 0;
	e3::Element* mCurrentPage = nullptr;
	e3::Element* mTmpPage = nullptr;
	e3::Animation* mAnimation = nullptr;

};

#endif // MDTabBarView_H_

