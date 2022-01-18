#include "MDTabBarView.h"
#include "MDTabBar.h"

MDTabBarView::MDTabBarView(e3::Element* pParent)
	: MDTabBarViewBase(pParent)
{

}

void MDTabBarView::SetTabBar(MDTabBar* pTabBar)
{
	pTabBar->SetTabBarView(this);
}

void MDTabBarView::SetIndex(int index)
{
	if (index == mIndex) return;
	if (mAnimation) return;
	if (GetNumChildren() <= index) return;

	int oldIndex = mIndex;
	mIndex = index;
	mTmpPage = GetChildren()[index];
	mTmpPage->SetLeft(0);
	e3::Rect2f currGeo = mCurrentPage->GetGeometry();
	if (index > oldIndex)
	{
		mTmpPage->SetTranslation(glm::vec3(currGeo.width, 0, 0));
	}
	else
	{
		mTmpPage->SetTranslation(glm::vec3(currGeo.width, 0, 0));
	}
	mTmpPage->SetVisibility(e3::EVisibility::Visible);

	mAnimation = new e3::Animation();
	mAnimation->Start(0.3, [this, currGeo, index, oldIndex](float v) {
		if (index > oldIndex)
		{
			mCurrentPage->SetTranslation(glm::vec3(v * (-currGeo.width), 0, 0));
			mTmpPage->SetTranslation(glm::vec3((1 - v) * currGeo.width, 0, 0));
		}
		else
		{
			mCurrentPage->SetTranslation(glm::vec3(v * currGeo.width, 0, 0));
			mTmpPage->SetTranslation(glm::vec3((1 - v) * (-currGeo.width), 0, 0));
		}
	}, [this]() {
		mAnimation = nullptr;
		mCurrentPage->SetVisibility(e3::EVisibility::Gone);
		mCurrentPage = mTmpPage;
		mCurrentPage->SetVisibility(e3::EVisibility::Visible);
		mTmpPage = nullptr;
	});
}


void MDTabBarView::AddElement(e3::Element* pPage)
{
	e3::Element::AddElement(pPage);

	if (!mCurrentPage)
	{
		mCurrentPage = pPage;
		mCurrentPage->SetVisibility(e3::EVisibility::Visible);
	}
	else
	{
		pPage->SetVisibility(e3::EVisibility::Gone);
	}

	pPage->SetPositionType(e3::EPositionType::Absolute);
	pPage->SetLeft(0);
	pPage->SetWidth("100%");
	pPage->SetHeight("100%");
}