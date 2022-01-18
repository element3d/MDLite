#include "MDDialog.h"

MDDialog::MDDialog(e3::Element* pParent)
	: MDDialogBase(pParent)
{
	SetVisibility(e3::EVisibility::Hidden);
}

void MDDialog::Show()
{
	mOpened = true;
	SetVisibility(e3::EVisibility::Visible);
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.1, [this](float v) {
		SetOpacity(v);
	}, [this]() {
		mAnimation = nullptr;
	});
}

void MDDialog::Hide()
{
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.1, [this](float v) {
		SetOpacity(1.0 - v);
	}, [this]() {
		SetVisibility(e3::EVisibility::Hidden);
		mOpened = false;
		mAnimation = nullptr;
	});
}

void MDDialog::Render()
{
	if (mOpened)
		mBody->SetBackgroundColor(MDTheme::Get()->DialogTheme.BackgroundColor);
	else
		mBody->SetBackgroundColor(glm::vec4(0));
	MDDialogBase::Render();
}

void MDDialog::SetWidth(const e3::Dim& dim)
{
	mBody->SetWidth(dim);
}

void MDDialog::SetHeight(const e3::Dim& dim)
{
	mBody->SetHeight(dim);
}

void MDDialog::AddElement(e3::Element* pElement)
{
	mBody->AddElement(pElement);
}

bool MDDialog::OnClick(e3::MouseEvent* pEvent)
{
	if (!mBody->GetGeometry().contains(glm::vec2(pEvent->GetX(), pEvent->GetY())))
	{
		Hide();
		return false;
	}
	return MDDialogBase::OnClick(pEvent);
}