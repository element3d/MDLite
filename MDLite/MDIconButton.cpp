#include "MDIconButton.h"
#include <e3/Application.h>

MDIconButton::MDIconButton(e3::Element* pParent)
	: MDIconButtonBase(pParent)
{

}

MDIconButton::~MDIconButton()
{
	mDestroyed = true;
	if (mRippleAnimation) mRippleAnimation->Stop();
}

void MDIconButton::SetName(const std::string& name)
{
	mIcon->SetName(name);
}

void MDIconButton::SetColor(const glm::vec4& color)
{
	// mIcon->SetColor(color);
	// mHasOwnColor = true;
}

void MDIconButton::SetColor(MDColor* pColor)
{
	mIcon->SetColor(pColor);
	mIconColor = pColor;
}

void MDIconButton::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDIconButtonBase::OnMouseEnter(pEvent);
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
#include "_MDUtils.h"

void MDIconButton::OnMouseHover(e3::MouseEvent* pEvent)
{
	glm::vec4 iconColor = mIcon->GetColor();
	bool b = _MDUtils::IsColorBright(iconColor);
	if (!b)
		mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 0.04 * 255));
	else
		mBackground->SetBackgroundColor(glm::vec4(255, 255, 255, 0.08 * 255));
	MDIconButtonBase::OnMouseHover(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Hand);
}

void MDIconButton::OnMouseLeave(e3::MouseEvent* pEvent)
{
	mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 0));
	MDIconButtonBase::OnMouseLeave(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Arrow);
	/*delete mColor;
	mColor = mMainColor;*/
}

bool MDIconButton::OnClick(e3::MouseEvent* pEvent)
{
	glm::vec4 iconColor = mIcon->GetColor();
//	mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 0));

	bool b = _MDUtils::IsColorBright(iconColor);
	if (!b)
		mRipple->SetBackgroundColor(glm::vec4(0, 0, 0, 0.16 * 255));
	else
		mRipple->SetBackgroundColor(glm::vec4(255, 255, 255, 0.32 * 255));

	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();
	mRippleAnimation->Start(0.1, [this](float v) {
		mRipple->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
	}, [this]() {
		mRippleAnimation = nullptr;
		_DismissRipple();
	});

	return 	MDIconButtonBase::OnClick(pEvent);
}

void MDIconButton::_DismissRipple()
{
	if (mDestroyed) return;
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();
	glm::vec4 color = mRipple->GetBackgroundColor();

	mRippleAnimation->Start(0.2, [this, color](float v) {
		mRipple->SetBackgroundColor(glm::vec4(color.r, color.g, color.b, (1 - v) * color.a));
	}, [this]() {
		mRippleAnimation = nullptr;
	});
}

void MDIconButton::Render()
{
	//if (mIconColor) mIcon->SetColor(*mIconColor);
	MDIconButtonBase::Render();
}