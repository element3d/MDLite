#include "MDInput.h"

MDInput::MDInput(e3::Element* pParent)
	: MDInputBase(pParent)
{
	mInput->SetOnFocusInCallback([this]() {
		Focus();
	});
	mInput->SetOnFocusOutCallback([this]() {
		Unfocus();
	});
	mLabelText->SetTranslation(glm::vec3(0, e3::Dim("10dp"), 0));
	mPrefixText->SetTextColor(glm::vec4(0));
	mHintText->SetVisibility(e3::EVisibility::Hidden);
	mContainer->SetBackgroundColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.03 * 255));
	mInput->SetOnChangeCallback([this](const std::string& text) {
		if (text.size()) mHintText->SetVisibility(e3::EVisibility::Hidden);
		else mHintText->SetVisibility(e3::EVisibility::Visible);
	});
}

void MDInput::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDInputBase::OnMouseEnter(pEvent);
	if (!mFocused)
		mContainer->SetBackgroundColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.06 * 255));
}

void MDInput::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDInputBase::OnMouseLeave(pEvent);

	mContainer->SetBackgroundColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.03 * 255));
}

void MDInput::SetLabelText(const std::string& labelText, bool translate)
{
	mLabelText->SetText(labelText, translate);
}

void MDInput::SetHintText(const std::string& hint, bool translate) 
{
	mHintText->SetText(hint, translate);
}

void MDInput::SetText(const std::string& text, bool translate)
{
	mInput->SetText(text);
}

void MDInput::SetPrefixText(const std::string& text, bool translate)
{
	mPrefixText->SetText(text, translate);
	if (!text.size()) mPrefixText->SetVisibility(e3::EVisibility::Hidden);
	else if (mPrefixText->GetText().size()) mPrefixText->SetVisibility(e3::EVisibility::Visible);
}

void MDInput::Focus()
{
	ALOGE("FOCUS %s\n", mHintText->GetText().c_str());
	glm::vec4 tr(0, 0, 0, 1);
	tr = GetTranslation() * tr;
	mPrefixText->SetTextColor(glm::vec4(0, 0, 0, 255));
	mLabelText->SetTranslation(glm::vec3(0, e3::Dim(-10, -15, -20, 0, 0, 0), 0));
	if (mPrefixText->GetText().size()) mPrefixText->SetVisibility(e3::EVisibility::Visible);
	//mHintText->SetTranslation(glm::vec3(tr.x, tr.y + e3::Dim(-10, -15, -20, -15, -15, -15), 0));
	mLabelText->SetScale(glm::vec3(0.7, 0.7, 1.0), e3::ETransformAlignment::Left);
//	mHintText->SetTextColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
	//mUnderline->SetBackgroundColor(/*GetTheme()->ColorPrimary*/MDColors::Primary::Get());
	//SetBackgroundColor(MDColors::Grey::Get("100"));
	mFocused = true;
	if (mInput->GetText().size())
	{
		// mInput->SetVisibility(e3::EVisibility::Visible);
		mHintText->SetVisibility(e3::EVisibility::Hidden);
	}
	else 
	{
		// mInput->SetVisibility(e3::EVisibility::Hidden);
		mHintText->SetVisibility(e3::EVisibility::Visible);
	}
}

void MDInput::Unfocus() 
{
	ALOGE("UNFOCUS %s\n", mHintText->GetText().c_str());
	mFocused = false;
	mHintText->SetVisibility(e3::EVisibility::Hidden);
	if (!mInput->GetText().size())
	{
		glm::vec4 tr(0, 0, 0, 1);
		tr = GetTranslation() * tr;
		mLabelText->SetTranslation(glm::vec3(0, e3::Dim("10dp"), 0));
		mLabelText->SetScale(glm::vec3(1.0, 1.0, 1.0), e3::ETransformAlignment::Center);
		mPrefixText->SetVisibility(e3::EVisibility::Hidden);

	}
	else 
	{
		if (mPrefixText->GetText().size()) mPrefixText->SetVisibility(e3::EVisibility::Visible);
	}

	//mHintText->SetTextColor(glm::vec4(0, 0, 0, 255));
	// mLabelText->SetTextColor(MDColors::Grey::Get("800"));
	//mUnderline->SetBackgroundColor(MDColors::Grey::Get("500"));
	// e3::Input::Unfocus();
}

bool MDInput::OnMouseDown(e3::MouseEvent* pEvent)
{
	// const MDTheme* pTheme = GetTheme();

	// e3::Input::Focus();
	mInput->Focus();
	return MDInputBase::OnMouseDown(pEvent);
}

bool MDInput::OnMouseUp(e3::MouseEvent* pEvent)
{

	return MDInputBase::OnMouseUp(pEvent);
}

void MDInput::Render()
{
	mInput->SetTextColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.87 * 255));
	if (mFocused)
	{
		mUnderline->SetBackgroundColor(MDTheme::Get()->PrimaryColor);
		mLabelText->SetTextColor(*MDTheme::Get()->PrimaryColor);
	}
	else 
	{
		mUnderline->SetBackgroundColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.6 * 255));
		mLabelText->SetTextColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.6 * 255));
	}
	mInput->SetHintColor(glm::vec4(glm::vec3(*MDTheme::Get()->OnSurface), 0.6 * 255));
	return MDInputBase::Render();
}