#include "MDDrawer.h"

MDDrawer::MDDrawer(e3::Element* pParent)
	: MDDrawerBase(pParent)
{

}

bool MDDrawer::IsShown()
{
	return mIsShown;
}

void MDDrawer::AddElement(e3::Element* pElement)
{
	mContent = pElement;
	/*mContent->*/e3::Element::AddElement(pElement);
}


void MDDrawer::Show()
{
	Show(false);
}

void MDDrawer::ShowModal()
{
	SetVisibility(e3::EVisibility::Visible);
	SetWidth("100%");
	Show(true);
}

void MDDrawer::Hide()
{
	if (mAnimation) return;

	mIsShown = false;
	e3::Rect2f contentGeo = mContent->GetGeometry();
	mContent->SetTranslation(glm::vec3(0, 0, 0));
	float alpha = GetBackgroundColor().w;
	mAnimation = new e3::Animation();
	mAnimation->Start(0.25, [this, alpha](float v) {
		e3::Rect2f contentGeo = mContent->GetGeometry();
		mContent->SetTranslation(glm::vec3(-v * contentGeo.width, 0, 0));
		SetBackgroundColor(glm::vec4(0, 0, 0, (1 - v) * alpha));
	}, [this]() {
		mAnimation = nullptr;
		SetVisibility(e3::EVisibility::Gone);
	});
}

bool MDDrawer::OnClick(e3::MouseEvent* pEvent)
{
	glm::vec2 pos(pEvent->GetX(), pEvent->GetY());
	e3::Rect2f contentGeo = mContent->GetGeometry();
	if (contentGeo.contains(pos))
	{
		mContent->OnClick(pEvent);
		pEvent->Stop();
		return true;
	}

	Hide();
	pEvent->Stop();
	return true;
}

void MDDrawer::Show(bool showModal)
{
	if (mAnimation || !mContent) return;

	SetBackgroundColor(glm::vec4(0, 0, 0, 0));
	mIsShown = true;
	SetVisibility(e3::EVisibility::Visible);
	e3::Rect2f contentGeo = mContent->GetGeometry();
	mContent->SetTranslation(glm::vec3(-contentGeo.width, 0, 0));
	mAnimation = new e3::Animation();
	mAnimation->Start(0.25, [this, showModal](float v) {
		e3::Rect2f contentGeo = mContent->GetGeometry();
		mContent->SetTranslation(glm::vec3(-(1 - v) * contentGeo.width, 0, 0));
		if (showModal)
		{
			SetBackgroundColor(glm::vec4(0, 0, 0, 50 * v));
		}
	}, [this]() {
		mAnimation = nullptr;
	});
}