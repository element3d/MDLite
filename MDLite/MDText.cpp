#include "MDText.h"

MDText::MDText(e3::Element* pParent)
	: MDTextBase(pParent)
{

}

void MDText::SetTextColor(MDColor* pColor)
{
	MDTextBase::SetTextColor(*pColor);
	mTextColor = pColor;
}

void MDText::SetTextColor(const glm::vec4& color)
{
	MDTextBase::SetTextColor(color);
}

void MDText::Render()
{
	if (mTextColor) MDTextBase::SetTextColor(*mTextColor);
	MDTextBase::Render();
}