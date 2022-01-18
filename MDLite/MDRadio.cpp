#include "MDRadio.h"
#include "MDColors.h"

MDRadio::MDRadio(e3::Element* pParent)
	: MDRadioBase(pParent)
{
	mCheckDim = e3::Dim("12", "15", "25", "10", "10", "10");
	SetBorderColor(MDColors::Grey::Get());

	/*	Material::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
	mTheme = pTheme;
	SetBorderColor(MDColors::Grey::Get());
	});*/
}

bool MDRadio::OnClick(e3::MouseEvent* pEvent)
{
	if (!mChecked) Check();
	bool b = MDRadioBase::OnClick(pEvent);
	pEvent->Stop();
	return b;
}

void MDRadio::OnMouseEnter(e3::MouseEvent* pEvent)
{
	mRipple->SetBackgroundColor(glm::vec4(0, 0, 0, 10));
	return MDRadioBase::OnMouseEnter(pEvent);
}

void MDRadio::OnMouseLeave(e3::MouseEvent* pEvent)
{
	mRipple->SetBackgroundColor(glm::vec4(0, 0, 0, 0));
	return MDRadioBase::OnMouseLeave(pEvent);
}

void MDRadio::Check()
{
	if (mChecked) return;
	mChecked = true;
	//const MDTheme* pTheme = GetTheme();//mTheme ? mTheme : Material::GetTheme();

									   //mIsChecked = true;
	SetBorderColor(*MDTheme::Get()->PrimaryColor);
	mCheck->SetBackgroundColor(*MDTheme::Get()->PrimaryColor);

	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.1, [this/*, pTheme*/](float v) {
		mCheck->SetWidth(v * mCheckDim);
		mCheck->SetHeight(v * mCheckDim);
		mCheck->SetBackgroundColor(*MDTheme::Get()->PrimaryColor);
		SetBorderColor(glm::mix(MDColors::Grey::Get(), *MDTheme::Get()->PrimaryColor, v));
	}, [this]() {
		mAnimation = nullptr;
		MDCheckable::Check();
	});
}

void MDRadio::Uncheck()
{
	if (!mChecked) return;
	mChecked = false;
	//
	//const MDTheme* pTheme = GetTheme();//mTheme ? mTheme : Material::GetTheme();

	SetBorderColor(MDColors::Grey::Get());

	//mIsChecked = false;
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(0.1, [this/*, pTheme*/](float v) {
		mCheck->SetWidth((1 - v) * mCheckDim);
		mCheck->SetHeight((1 - v) * mCheckDim);
		SetBorderColor(glm::mix(MDColors::Grey::Get(), *MDTheme::Get()->PrimaryColor, 1 - v));
	}, [this]() {
		mAnimation = nullptr;
		mCheck->SetBackgroundColor(glm::vec4(0));
		MDCheckable::Uncheck();
	});
}

bool MDRadio::IsChecked()
{
	return mChecked;
}

