#include "MDCheckbox.h"
#include "MDColors.h"

MDCheckbox::MDCheckbox(e3::Element* pParent)
	: MDCheckboxBase(pParent)
{
	mChecked = false;
	mIcon->SetOpacity(0);
	SetBorderColor(MDColors::Grey::Get());
}


bool MDCheckbox::OnClick(e3::MouseEvent* pEvent)
{
	if (!mChecked) Check();
	else Uncheck();

	return MDCheckboxBase::OnClick(pEvent);
}

void MDCheckbox::OnMouseEnter(e3::MouseEvent* pEvent)
{
	mRipple->SetBackgroundColor(glm::vec4(0, 0, 0, 10));
	return MDCheckboxBase::OnMouseEnter(pEvent);
}

void MDCheckbox::OnMouseLeave(e3::MouseEvent* pEvent)
{
	mRipple->SetBackgroundColor(glm::vec4(0, 0, 0, 0));
	return MDCheckboxBase::OnMouseLeave(pEvent);
}

void MDCheckbox::Check()
{
	mChecked = true;
	if (mAnimation) return;
	mAnimation = new e3::Animation();

	//mTheme ? mTheme : Material::GetTheme();
	/*glm::vec4 bgColor = ;
	switch (pTheme->ColorScheme)
	{
	case EMDColorScheme::Red:
	bgColor = MDColors::Red::Get("200");
	break;
	case EMDColorScheme::DeepPurple:
	{
	bgColor = MDColors::DeepPurple::Get("200");
	break;
	}
	case EMDColorScheme::Grey:
	bgColor = MDColors::Grey::Get("200");
	break;
	default:
	break;
	}*/

	mAnimation->Start(0.2, [this /*bgColor,*/](float v) {
		//const MDTheme* pTheme = GetTheme();
		e3::Rect2f geo = GetGeometry();
		SetBackgroundColor(glm::mix(glm::vec4(0), *MDTheme::Get()->PrimaryColor, v));
		glm::vec4 bc = MDColors::Grey::Get();
		SetBorderColor(glm::vec4(glm::vec3(bc), 255 * (1 - v)));
		mIcon->SetOpacity(v);
		//SetBorderColor(glm::mix(glm::vec4(200, 200, 200, 255), mTheme->ColorPrimary, v));
	}, [this]() {
		mAnimation = nullptr;
		if (mOnChangeCallback) mOnChangeCallback(true);
	});
}

void MDCheckbox::Uncheck()
{
	mChecked = false;
	if (mAnimation) return;
	mAnimation = new e3::Animation();

	//const MDTheme* pTheme = GetTheme();//mTheme ? mTheme : Material::GetTheme();
									   /*glm::vec4 bgColor;
									   switch (pTheme->ColorScheme)
									   {
									   case EMDColorScheme::Red:
									   bgColor = MDColors::Red::Get("200");
									   break;
									   case EMDColorScheme::DeepPurple:
									   {
									   bgColor = MDColors::DeepPurple::Get("200");
									   break;
									   }
									   case EMDColorScheme::Grey:
									   bgColor = MDColors::Grey::Get("200");
									   break;
									   default:
									   break;
									   }*/

	mAnimation->Start(0.2, [this /*bgColor,*/ /*pTheme*/](float v) {
		e3::Rect2f geo = GetGeometry();
		SetBackgroundColor(glm::mix(glm::vec4(0), /*pTheme->ColorPrimary*/*MDTheme::Get()->PrimaryColor, 1 - v));
		SetBorderColor(glm::mix(MDColors::Grey::Get(), /*pTheme->ColorPrimary*/*MDTheme::Get()->PrimaryColor, 1 - v));
		mIcon->SetOpacity(1 - v);
	}, [this]() {
		mAnimation = nullptr;
		if (mOnChangeCallback) mOnChangeCallback(false);
	});
}

bool MDCheckbox::IsChecked()
{
	return mChecked;
}

void MDCheckbox::SetChecked(bool checked)
{
	if (checked) Check();
	else Uncheck();
}

void MDCheckbox::SetOnChangeCallback(OnChangeCallback c)
{
	mOnChangeCallback = c;
}

void MDCheckbox::Render()
{
	MDCheckboxBase::Render();
}

//void MDCheckbox::UpdateTheme()
//{
	//MDTheme* pTheme = GetTheme();
	/*SetBackgroundColor(pTheme->SecondaryColor);
	mIcon->SetColor(pTheme->OnSecondary);
	mLabel->SetTextColor(pTheme->OnSecondary);*/
	//MDCheckboxBase::UpdateTheme();
//}