#include "MDBottomNavigationBarItem.h"
#include <e3/Application.h>

MDBottomNavigationBarItem::MDBottomNavigationBarItem(e3::Element* pParent)
	: MDBottomNavigationBarItemBase(pParent)
{
	mContainer->SetTranslation(glm::vec3(0, mTitle->GetFontSize() / 2.0, 0));
	mTitle->SetTextColor(glm::vec4(0));
	mIcon->SetColor(MDTheme::Get()->BottomNavigationBarTheme.UnselectedItemColor);
	//mTitle->SetTextColor(MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor);
}

void MDBottomNavigationBarItem::SetTitle(const std::string& title, bool translate)
{
	mTitle->SetText(title, translate);
}

void MDBottomNavigationBarItem::SetIcon(const std::string& iconName)
{
	mIcon->SetName(iconName);
}

void MDBottomNavigationBarItem::Select()
{
	if (mSelected) return;
	mSelected = true;
	mIcon->SetColor(MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor);
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.2, [this](float v) {
		mContainer->SetTranslation(glm::vec3(0, (1 - v) * mTitle->GetFontSize() / 2.0, 0));
		glm::vec4 selectedColor = *MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor;
		mTitle->SetTextColor(glm::vec4(glm::vec3(selectedColor), v * 255));
		//mTitle->SetOpacity(v);
	}, [this]() {
		mAnimation = nullptr;
	});
}

void MDBottomNavigationBarItem::Unselect()
{
	if (!mSelected) return;
	mSelected = false;
	mIcon->SetColor(MDTheme::Get()->BottomNavigationBarTheme.UnselectedItemColor);

	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.2, [this](float v) {
		mContainer->SetTranslation(glm::vec3(0, v * mTitle->GetFontSize() / 2.0, 0));
		//float opacity = mSelected ? v : 1 - v;
		//mTitle->SetOpacity(opacity);
		glm::vec4 selectedColor = *MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor;
		mTitle->SetTextColor(glm::vec4(glm::vec3(selectedColor), (1 - v) * 255));
	}, [this]() {
		mAnimation = nullptr;
	});
}
#include "_MDUtils.h"
bool MDBottomNavigationBarItem::OnClick(e3::MouseEvent* pEvent)
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

	return MDBottomNavigationBarItemBase::OnClick(pEvent);
}

void MDBottomNavigationBarItem::_DismissRipple()
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

void MDBottomNavigationBarItem::Render()
{
//	mIcon->SetColor(MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor);
	//mTitle->SetTextColor(MDTheme::Get()->BottomNavigationBarTheme.SelectedItemColor);
	MDBottomNavigationBarItemBase::Render();
}

void MDBottomNavigationBarItem::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDBottomNavigationBarItemBase::OnMouseEnter(pEvent);
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

void MDBottomNavigationBarItem::OnMouseHover(e3::MouseEvent* pEvent)
{
	mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 12));
	MDBottomNavigationBarItemBase::OnMouseHover(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Hand);
}

void MDBottomNavigationBarItem::OnMouseLeave(e3::MouseEvent* pEvent)
{
	mBackground->SetBackgroundColor(glm::vec4(0, 0, 0, 0));
	MDBottomNavigationBarItemBase::OnMouseLeave(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Arrow);
	/*delete mColor;
	mColor = mMainColor;*/
}