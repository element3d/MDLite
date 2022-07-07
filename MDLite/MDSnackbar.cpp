#include "MDSnackbar.h"

MDSnackbar::MDSnackbar(e3::Element* pParent)
	: MDSnackbarBase(pParent)
{
	SetOpacity(0);
}

MDSnackbar::~MDSnackbar()
{
	if (mHideTimeout) mHideTimeout->Stop();
	if (mAnimation) mAnimation->Stop();
	if (mHideAnimation) mHideAnimation->Stop();
}

void MDSnackbar::Show()
{
	if (!mAnimation)
		mAnimation = new e3::Animation();
	mAnimation->Start(0.2, 0, 1, [this](float v) {
		SetOpacity(v);
	}, [this]() {
		mAnimation = nullptr;
	});

	if (!mHideTimeout)
		mHideTimeout = new e3::Timeout();

	/*mHideTimeout->Start(5, [this]() {
		Hide();
		mHideTimeout = nullptr;
	});*/
}

void MDSnackbar::Hide()
{
	if (!mAnimation)
		mAnimation = new e3::Animation();
	mAnimation->Start(0.2, 0, 1, [this](float v) {
		SetOpacity(1 - v);
	}, [this]() {
		mAnimation = nullptr;
	});
}