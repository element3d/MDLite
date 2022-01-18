#include "MDLinearProgressIndicator.h"

MDLinearProgressIndicator::MDLinearProgressIndicator(e3::Element* pParent)
	: MDLinearProgressIndicatorBase(pParent)
{
	Animate(1.5);
}

MDLinearProgressIndicator::~MDLinearProgressIndicator()
{
	mDestroyed = true;
	if (mAnimation) mAnimation->Stop();
}

void MDLinearProgressIndicator::Animate(float sec)
{
	if (!mAnimation) mAnimation = new e3::Animation();
	mAnimation->Start(sec/*, e3::EAnimation::EaseInExpo*/, [this](float v) {
		mValueElement->SetWidthPercent(std::max(1.0f, v * 100));
		mValueElement->SetTranslation(glm::vec3(v * GetGeometry().width, 0, 0));
	}, [this, sec]() {
		if (mDestroyed) return;
		mAnimation = nullptr;
		Animate(sec == 1.5 ? 1 : 1.5);
	});
}

void MDLinearProgressIndicator::SetValue(float value)
{
	mValueElement->SetWidthPercent(value * 100);
}

float MDLinearProgressIndicator::GetValue()
{
	return mValueElement->GetGeometry().width / GetGeometry().width;
}

void MDLinearProgressIndicator::Render()
{
	glm::vec4 color = *MDTheme::Get()->PrimaryColor;
	color.a = 150;
	SetBackgroundColor(color);
	mValueElement->SetBackgroundColor(*MDTheme::Get()->PrimaryColor);
	MDLinearProgressIndicatorBase::Render();
}