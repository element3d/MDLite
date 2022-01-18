#include "MDNavigationRailItem.h"
#include <e3/Application.h>

MDNavigationRailItem::MDNavigationRailItem(e3::Element* pParent)
	: MDNavigationRailItemBase(pParent)
{
	mTitle->SetTextColor(glm::vec4(0));
	mIcon->SetColor(MDTheme::Get()->NavigationRailTheme.UnselectedItemColor);
}

void MDNavigationRailItem::SetTitle(const std::string& title, bool translate)
{
	mTitle->SetText(title, translate);
}

void MDNavigationRailItem::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);
}

void MDNavigationRailItem::Select()
{
	if (mSelected) return;
	mSelected = true;
	mIcon->SetColor(MDTheme::Get()->NavigationRailTheme.SelectedItemColor);
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.2, [this](float v) {
		mContainer->SetTranslation(glm::vec3(0, (1 - v) * mTitle->GetFontSize() / 2.0, 0));
		glm::vec4 selectedColor = *MDTheme::Get()->NavigationRailTheme.SelectedItemColor;
		mTitle->SetTextColor(glm::vec4(glm::vec3(selectedColor), v * 255));
		//mTitle->SetOpacity(v);
	}, [this]() {
		mAnimation = nullptr;
	});
}

void MDNavigationRailItem::Unselect()
{
	if (!mSelected) return;
	mSelected = false;
	mIcon->SetColor(MDTheme::Get()->NavigationRailTheme.UnselectedItemColor);

	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.2, [this](float v) {
		mContainer->SetTranslation(glm::vec3(0, v * mTitle->GetFontSize() / 2.0, 0));
		//float opacity = mSelected ? v : 1 - v;
		//mTitle->SetOpacity(opacity);
		glm::vec4 selectedColor = *MDTheme::Get()->NavigationRailTheme.SelectedItemColor;
		mTitle->SetTextColor(glm::vec4(glm::vec3(selectedColor), (1 - v) * 255));
	}, [this]() {
		mAnimation = nullptr;
	});
}
#include "_MDUtils.h"
bool MDNavigationRailItem::OnClick(e3::MouseEvent* pEvent)
{
	//mSelected = !mSelected;
	if (!mSelected) Select();
	else Unselect();

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

	return MDNavigationRailItemBase::OnClick(pEvent);
}

void MDNavigationRailItem::_DismissRipple()
{
	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();
	glm::vec4 color = mRipple->GetBackgroundColor();

	mRippleAnimation->Start(0.2, [this, color](float v) {
		mRipple->SetBackgroundColor(glm::vec4(color.r, color.g, color.b, (1 - v) * color.a));
	}, [this]() {
		mRippleAnimation = nullptr;
	});
}

void MDNavigationRailItem::Render()
{
	//	mIcon->SetColor(MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor);
	//mTitle->SetTextColor(MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor);
	MDNavigationRailItemBase::Render();
}

void MDNavigationRailItem::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDNavigationRailItemBase::OnMouseEnter(pEvent);
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

void MDNavigationRailItem::OnMouseHover(e3::MouseEvent* pEvent)
{
	mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 12));
	MDNavigationRailItemBase::OnMouseHover(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Hand);
}

void MDNavigationRailItem::OnMouseLeave(e3::MouseEvent* pEvent)
{
	mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 0));
	MDNavigationRailItemBase::OnMouseLeave(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Arrow);
	/*delete mColor;
	mColor = mMainColor;*/
}