#include "MDTextButton.h"

MDTextButton::MDTextButton(e3::Element* pParent)
	: MDTextButtonBase(pParent)
{
	mLabel->SetTextColor(MDTheme::Get()->PrimaryColor);
}

void MDTextButton::SetIcon(MDIcon* pIcon)
{
	pIcon->SetMarginLeft(16);
	pIcon->SetMarginRight(0);
	pIcon->SetWidth(14);
	pIcon->SetHeight(14);
	pIcon->SetColor(MDTheme::Get()->PrimaryColor);
	mIconCont->AddElement(pIcon);
}

void MDTextButton::SetLabel(const std::string& label, bool translate)
{
	mLabel->SetVisibility(e3::EVisibility::Visible);
	mLabel->SetText(label, translate);
}

void MDTextButton::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDTextButtonBase::OnMouseEnter(pEvent);
	mHover->SetWidth(GetGeometry().width);
	mHover->SetHeight(GetGeometry().height);
	mHover->SetBackgroundColor(glm::vec4(glm::vec3(*MDTheme::Get()->PrimaryColor), 10));
}

void MDTextButton::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDTextButtonBase::OnMouseLeave(pEvent);
	mHover->SetBackgroundColor(glm::vec4(255, 255, 255, 0));
}

void MDTextButton::Render()
{
	/*mLabel->SetTextColor(*MDTheme::Get()->PrimaryColor);
	if (mIconCont->GetNumChildren())
	{
		MDIcon* pIcon = (MDIcon*)mIconCont->GetChildren()[0];
		pIcon->SetColor(MDTheme::Get()->PrimaryColor);
	}*/
	MDTextButtonBase::Render();
}
