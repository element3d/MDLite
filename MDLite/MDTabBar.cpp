#include "MDTabBar.h"

MDTabBar::MDTabBar(e3::Element* pParent)
	: MDTabBarBase(pParent)
{

}

void MDTabBar::SetIsScrollable(bool isScrollable)
{
	mIsScrollable = isScrollable;
}

void MDTabBar::SetTabBarView(MDTabBarView* pTabBarView)
{
	mTabBarView = pTabBarView;
}

void MDTabBar::AddElement(e3::Element* pTab)
{
	AddElement((MDTab*)pTab);
	/*mContent->AddElement(pTab);
	if (!mIsScrollable)
	{
	for (auto pE : mContent->GetChildren())
	{
	pTab->SetWidthPercent((1.0 / GetNumChildren()) * 100);
	pTab->SetScaling(e3::EScaling::Shrink);
	}
	}*/
}

void MDTabBar::SetOnTabSelectCallback(OnTabSelectCallback onTabSelectCallback)
{
	mOnTabSelectCallback = onTabSelectCallback;
}

void MDTabBar::AddElement(MDTab* pTab)
{
	int index = mContent->GetNumChildren();
	if (index == 0) pTab->Select();
	else pTab->Unselect();

	mContent->AddElement(pTab);
	if (!mIsScrollable)
	{
		for (auto pE : mContent->GetChildren())
		{
			pTab->SetWidthPercent((1.0 / GetNumChildren()) * 100);
			pTab->SetScaling(e3::EScaling::Shrink);
		}
	}
	pTab->SignalOnClick.Connect([this, pTab, index](e3::MouseEvent*) {
		if (mOnTabSelectCallback) mOnTabSelectCallback(pTab);

		if (mTabBarView) mTabBarView->SetIndex(index);
		auto g = mSelection->GetGeometry();
		mAnimation = new e3::Animation();
		mAnimation->Start(0.3, [this, pTab, g](float v) {
			mSelection->SetWidth(g.width + (pTab->GetGeometry().width - g.width) * v);
			float sx = GetGeometry().x;
			mSelection->SetTranslation(glm::vec3(g.x - sx - mContent->GetScrollVec().x + (pTab->GetGeometry().x - g.x) * v, 0, 0));
		}, [this]() {
			mAnimation = nullptr;
		});
		//mSelection->SetWidth(pTab->GetGeometry().width);
		//float sx = GetGeometry().x;
		//mSelection->SetTranslation(glm::vec3(pTab->GetGeometry().x - sx, 0, 0));

		for (int i = 0; i < mContent->GetNumChildren(); ++i)
		{
			if (mContent->GetChildren()[i] == pTab) pTab->Select();
			else
			{
				((MDTab*)mContent->GetChildren()[i])->Unselect();
			}
		}

	});
}
