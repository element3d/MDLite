#include "MDCircularProgressIndicator.h"

MDCircularProgressIndicator::MDCircularProgressIndicator(e3::Element* pParent)
	: MDCircularProgressIndicatorBase(pParent)
{
	AnimateRotation(6);
	AnimateEndAngle(0.6);
}

MDCircularProgressIndicator::~MDCircularProgressIndicator()
{
	mDestroyed = true;
	if (mRotationAnimation) mRotationAnimation->Stop();
	if (mStartAngleAnimation) mStartAngleAnimation->Stop();
	if (mEndAngleAnimation) mEndAngleAnimation->Stop();
}

void MDCircularProgressIndicator::AnimateRotation(float sec)
{
	if (!mRotationAnimation) mRotationAnimation = new e3::Animation();

	mRotationAnimation->Start(sec, [this](float v) {
		Rotate(2, glm::vec3(0, 0, 1), e3::ETransformAlignment::Center);
	}, [sec, this]() {
		if (mDestroyed) return;
		mRotationAnimation = nullptr;
		AnimateRotation(sec);
	});
}

void MDCircularProgressIndicator::AnimateStartAngle(float sec)
{
	if (!mStartAngleAnimation) mStartAngleAnimation = new e3::Animation();

	float startAngle = GetStartAngle();
	float endAngle = GetEndAngle();
	if (endAngle < startAngle) endAngle += 360;
	mStartAngleAnimation->Start(sec, startAngle, endAngle, e3::EAnimation::EaseOutQuad, [this, startAngle](float v) {
		float endAngle = GetEndAngle();
		SetStartAngle(v);
	}, [sec, this]() {
		mStartAngleAnimation = nullptr;
		if (mDestroyed) return;
		AnimateEndAngle(sec);
	});
}

void MDCircularProgressIndicator::AnimateEndAngle(float sec)
{
	if (!mEndAngleAnimation) mEndAngleAnimation = new e3::Animation();

	mEndAngleAnimation->Start(sec, e3::EAnimation::EaseOutQuad, [this](float v) {
		float startAngle = GetStartAngle();
		SetEndAngle(int(startAngle + 270 * v));
	}, [sec, this]() {
		float endAngle = GetEndAngle();
		mEndAngleAnimation = nullptr;
		if (mDestroyed) return;
		//SetStartAngle(endAngle);
		AnimateStartAngle(sec);
	});
}

void MDCircularProgressIndicator::SetValue(float value)
{
	SetEndAngle(360 * value);
}

float MDCircularProgressIndicator::GetValue()
{
	return GetEndAngle() / 360.0;
}

void MDCircularProgressIndicator::Render()
{
	SetBackgroundColor(*MDTheme::Get()->PrimaryColor);
	MDCircularProgressIndicatorBase::Render();
}
