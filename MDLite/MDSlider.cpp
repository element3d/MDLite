#include "MDSlider.h"
#include "MDColors.h"

MDSlider::MDSlider(e3::Element* pParent)
	: MDSliderBase(pParent)
{
	// MDColor primary = GetTheme()->ColorPrimary;
	mCircle->SetBackgroundColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
	glm::vec4 primary = MDColors::Primary::Get();
	mBackground->SetBackgroundColor(glm::vec4(primary.r, primary.g, primary.b, 50));
	glm::vec4 hoverColor = /*GetTheme()->ColorPrimary*/MDColors::Primary::Get();
	hoverColor.w = 30;
	mHoverCircle->SetBackgroundColor(hoverColor);
	mValue->SetBackgroundColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
	//mInfo->SetVisibility(e3::EVisibility::Hidden);
	//mInfo->SetBackgroundColor(MDColors::Grey::Get("700"));
	//mInfoShape->SetBackgroundColor(MDColors::Grey::Get("700"));
	//mInfoTriangle->SetBackgroundColor(MDColors::Grey::Get("700"));

	//mInfoTriangle->SetRotation(180, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	/*Material::AddOnThemeChangeCallback([this](const MDTheme* pTheme) {
	mTheme = pTheme;
	mCircle->SetBackgroundColor(pTheme->ColorPrimary);
	glm::vec4 hoverColor = pTheme->ColorPrimary;
	hoverColor.w = 30;
	mHoverCircle->SetBackgroundColor(hoverColor);
	mValue->SetBackgroundColor(pTheme->ColorPrimary);
	});*/

}

/*void MDSlider::SetParent(e3::Element* pParent)
{
	MDSliderBase::SetParent(pParent);
	mCircle->SetBackgroundColor(GetTheme()->ColorPrimary);
	glm::vec4 hoverColor = GetTheme()->ColorPrimary;
	hoverColor.w = 30;
	mHoverCircle->SetBackgroundColor(hoverColor);
	mValue->SetBackgroundColor(GetTheme()->ColorPrimary);
}*/

MDSlider::~MDSlider()
{
	if (mHoverAnimation) mHoverAnimation->Stop();
	if (mInfoAnimation) mInfoAnimation->Stop();
}

void MDSlider::SetOnChangeCallback(OnChangeCallback c)
{
	mOnChangeCallback = c;
}

void MDSlider::Render()
{
	mCircle->SetBackgroundColor(*MDTheme::Get()->PrimaryColor);
	glm::vec4 primary = *MDTheme::Get()->PrimaryColor;
	mBackground->SetBackgroundColor(glm::vec4(primary.r, primary.g, primary.b, 50));
	glm::vec4 hoverColor = *MDTheme::Get()->PrimaryColor;
	hoverColor.w = 30;
	mHoverCircle->SetBackgroundColor(hoverColor);
	mValue->SetBackgroundColor(*MDTheme::Get()->PrimaryColor);

	MDSliderBase::Render();
}

void MDSlider::SetDivisions(int divisiions)
{
	mNumDivisions = divisiions;

	mDivisions->Clear();
	for (int i = 0; i < divisiions; ++i)
	{
		e3::Element* pD = new e3::Element();
		pD->SetHeight(2);
		pD->SetAspectRatio(1);
		pD->SetShapeType(e3::EShapeType::Circle);
		pD->SetBackgroundColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
		mDivisions->AddElement(pD);
	}
}

int MDSlider::GetDivisions()
{
	return mNumDivisions;
}

void MDSlider::OnMouseMove(e3::MouseEvent* pEvent)
{
	if (mNumDivisions > 0)
	{
		float sliderWidth = pEvent->GetX() - GetGeometry().x - mCircle->GetGeometry().width / 2.0f + mCircle->GetGeometry().width / 2.0f;
		int i = 0;
		for (e3::Element* pDivisions : mDivisions->GetChildren())
		{
			if (pDivisions->GetGeometry().x >= pEvent->GetX())
			{
				--i;
				break;
			}
			++i;
		}
		i = std::min(i, mNumDivisions - 2);
		i = std::max(0, i);
		float d1 = pEvent->GetX() - mDivisions->GetChildren()[i]->GetGeometry().x;
		float d2 = mDivisions->GetChildren()[i + 1]->GetGeometry().x - pEvent->GetX();

		if (d1 < d2)
			mSliderWidth = mDivisions->GetChildren()[i]->GetGeometry().x - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
		else
		{
			mSliderWidth = mDivisions->GetChildren()[i + 1]->GetGeometry().x - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
			i = i + 1;
		}
		for (int j = 0; j < i; ++j) mDivisions->GetChildren()[j]->SetBackgroundColor(glm::vec4(255));
		for (int j = i; j < mDivisions->GetNumChildren(); ++j) mDivisions->GetChildren()[j]->SetBackgroundColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
	}
	else
	{
		mSliderWidth = pEvent->GetX() - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
	}
	mValue->SetWidth(mSliderWidth + mCircle->GetGeometry().width / 2.0f);
	mCircle->SetTranslation(glm::vec3(mSliderWidth, 0, 0));
	auto geo = mCircle->GetGeometry();
	auto hg = mHoverCircle->GetGeometry();
	mHoverCircle->SetTranslation(glm::vec3(mSliderWidth - (hg.height - geo.height) / 2, 0, 0));
	// info
	mSliderValue = ((mSliderWidth + mCircle->GetGeometry().width / 2.0f) / GetGeometry().width) * 100;

	if (mNumDivisions)
	{
		//_ShowInfo();
		auto ig = mInfo->GetGeometry();
		mInfo->SetTranslation(glm::vec3(mSliderWidth + mCircle->GetGeometry().width / 2.0f - mInfoShape->GetRect().width / 2.0f, -mInfoShape->GetRect().height, 0));
		mInfoText->SetText(std::to_string(mSliderValue));
	}

	if (mOnChangeCallback) mOnChangeCallback(mSliderValue);
}

void MDSlider::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDSliderBase::OnMouseEnter(pEvent);
	mCircle->SetTranslation(glm::vec3(mSliderWidth, 0, 0));
}

void MDSlider::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDSliderBase::OnMouseLeave(pEvent);
}

bool MDSlider::OnMouseDown(e3::MouseEvent* pEvent)
{
	if (mNumDivisions > 0)
	{
		float sliderWidth = pEvent->GetX() - GetGeometry().x - mCircle->GetGeometry().width / 2.0f + mCircle->GetGeometry().width / 2.0f;
		int i = 0;
		for (e3::Element* pDivisions : mDivisions->GetChildren())
		{
			if (pDivisions->GetGeometry().x >= pEvent->GetX())
			{
				--i;
				break;
			}
			++i;
		}
		i = std::max(0, i);
		i = std::min(mNumDivisions - 2, i);
		float d1 = pEvent->GetX() - mDivisions->GetChildren()[i]->GetGeometry().x;
		float d2 = mDivisions->GetChildren()[i + 1]->GetGeometry().x - pEvent->GetX();

		if (d1 < d2)
			mSliderWidth = mDivisions->GetChildren()[i]->GetGeometry().x - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
		else
		{
			mSliderWidth = mDivisions->GetChildren()[i + 1]->GetGeometry().x - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
			i = i + 1;
		}
		for (int j = 0; j < i; ++j) mDivisions->GetChildren()[j]->SetBackgroundColor(glm::vec4(255));
		for (int j = i; j < mDivisions->GetNumChildren(); ++j) mDivisions->GetChildren()[j]->SetBackgroundColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
	}
	else
	{
		mSliderWidth = pEvent->GetX() - GetGeometry().x - mCircle->GetGeometry().width / 2.0f;
	}
	mValue->SetWidth(mSliderWidth + mCircle->GetGeometry().width / 2.0f);
	mCircle->SetTranslation(glm::vec3(mSliderWidth, 0, 0));
	auto hg = mHoverCircle->GetGeometry();
	auto geo = mCircle->GetGeometry();

	mSliderValue = ((mSliderWidth + mCircle->GetGeometry().width / 2.0f) / GetGeometry().width) * 100;

	mHoverCircle->SetTranslation(glm::vec3(mSliderWidth - (hg.height - geo.height) / 2, 0, 0));
	// info
	if (mNumDivisions)
	{
		mInfoText->SetText(std::to_string(mSliderValue));
		_ShowInfo();
		auto ig = mInfo->GetGeometry();
		//mInfo->SetTranslation(glm::vec3(mSliderWidth + mCircle->GetGeometry().width / 2.0f - mInfoShape->GetRect().width / 2.0f, -mInfoShape->GetRect().height, 0));

	}

	if (!mHoverAnimation)
		mHoverAnimation = new e3::Animation();

	mHoverCircle->SetOpacity(1.0);

	mHoverAnimation->Start(0.1, [this](float value) {
		auto geo = mCircle->GetGeometry();
		mHoverCircle->SetHeight((1 + 1.5 * value) * geo.height);
		auto hg = mHoverCircle->GetGeometry();
		mHoverCircle->SetTranslation(glm::vec3(mSliderWidth - (hg.height - geo.height) / 2, 0, 0));
	}, [this]() {
		mHoverAnimation = nullptr;
	});

	//mInfoText->SetText(std::to_string(mSliderValue));
	if (mOnChangeCallback) mOnChangeCallback(mSliderValue);
	return MDSliderBase::OnMouseDown(pEvent);
}

bool MDSlider::OnMouseUp(e3::MouseEvent* pEvent)
{
	if (!mHoverAnimation)
		mHoverAnimation = new e3::Animation();

	_HideInfo();

	mHoverAnimation->Start(0.1, [this](float value) {
		auto geo = mCircle->GetGeometry();
		//mHoverCircle->SetOpacity(1 - value);
		mHoverCircle->SetHeight((1 + 1.5 * (1 - value)) * geo.height);
		auto hg = mHoverCircle->GetGeometry();
		mHoverCircle->SetTranslation(glm::vec3(mSliderWidth - (hg.height - geo.height) / 2, 0, 0));
	}, [this]() {
		mHoverAnimation = nullptr;
		mHoverCircle->SetOpacity(0.0);
	});

	return MDSliderBase::OnMouseUp(pEvent);
}

void MDSlider::SetTranslation(const glm::vec3 &pos)
{
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;

	glm::vec4 circletr(0, 0, 0, 1);
	circletr = mCircle->GetTranslation() * circletr;

	glm::vec4 hovertr(0, 0, 0, 1);
	hovertr = mHoverCircle->GetTranslation() * hovertr;

	e3::Element::SetTranslation(glm::vec3(pos));

	{
		glm::vec4 diff = circletr - tr;
		mCircle->SetTranslation(pos + glm::vec3(diff));
	}
	{
		glm::vec4 diff = hovertr - tr;
		mHoverCircle->SetTranslation(pos + glm::vec3(hovertr));
	}
}

void MDSlider::_ShowInfo()
{
	mInfo->SetVisibility(e3::EVisibility::Visible);
	auto ig = mInfo->GetGeometry();
	if (!mInfoAnimation)
		mInfoAnimation = new e3::Animation();
	mInfoAnimation->Start(0.2, [this](float value) {
		mInfo->SetTranslation(glm::vec3(mSliderWidth + mCircle->GetGeometry().width / 2.0f - mInfoShape->GetRect().width / 2.0f, -mInfoShape->GetRect().height, 0));
		mInfo->SetScale(glm::vec3(value, value, 1), e3::ETransformAlignment::Bottom);
	}, [this]() {
		mInfoAnimation = nullptr;
	});
}

void MDSlider::_HideInfo()
{
	auto ig = mInfo->GetGeometry();
	mInfo->SetTranslation(glm::vec3(mSliderWidth + mCircle->GetGeometry().width / 2.0f - mInfoShape->GetRect().width / 2.0f, -mInfoShape->GetRect().height, 0));
	if (!mInfoAnimation)
		mInfoAnimation = new e3::Animation();

	mInfoAnimation->Start(0.2, [this](float value) {
		mInfo->SetScale(glm::vec3(1 - value, 1 - value, 1), e3::ETransformAlignment::Bottom);
	}, [this]() {
		mInfoAnimation = nullptr;
		mInfo->SetVisibility(e3::EVisibility::Gone);
	});
}
