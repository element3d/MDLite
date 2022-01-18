#include "MDButton.h"

MDButton::MDButton(e3::Element* pParent)
	: MDButtonBase(pParent)
{
	mLabel->SetTextColor(MDTheme::Get()->OnPrimary);
}

void MDButton::SetIcon(MDIcon* pIcon)
{
	pIcon->SetMarginLeft(16);
	pIcon->SetMarginRight(0);
	pIcon->SetWidth(14);
	pIcon->SetHeight(14);
	pIcon->SetColor(MDTheme::Get()->OnPrimary);
	mIconCont->AddElement(pIcon);
}

void MDButton::SetLabel(const std::string& label, bool translate)
{
	mLabel->SetVisibility(e3::EVisibility::Visible);
	mLabel->SetText(label, translate);
}

void MDButton::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDButtonBase::OnMouseEnter(pEvent);
	mHover->SetWidth(GetGeometry().width);
	mHover->SetHeight(GetGeometry().height);
	mHover->SetBackgroundColor(glm::vec4(255, 255, 255, 25));
	//mMainColor = mColor;

	/*	glm::vec4 color;
	if (mColor) color = glm::vec4(mColor->r, mColor->g, mColor->b, mColor->a);
	else color = GetBackgroundColor();

	glm::vec3 hsl = RGBtoHSL(glm::vec3(color));
	glm::vec4 rippleColor;
	if (hsl.b >= 0.5) rippleColor = glm::vec4(0, 0, 0, 12);
	else rippleColor = glm::vec4(255, 255, 255, 25);

	glm::vec4 hoverColor = rippleColor;//GetTheme()->HoverColor;// (0, 0, 0, 10);

	//MDColor c;
	if (color.a > 0) c = glm::mix(hoverColor, color, 1 - hoverColor.a / 255);
	else c = hoverColor;
	//mColor = new MDColor(c);*/
}

void MDButton::OnMouseLeave(e3::MouseEvent* pEvent) 
{
	MDButtonBase::OnMouseLeave(pEvent);
	mHover->SetBackgroundColor(glm::vec4(255, 255, 255, 0));
}

void MDButton::Render() 
{
	//SetBackgroundColor(MDTheme::Get()->PrimaryColor);
	MDButtonBase::Render();
}
