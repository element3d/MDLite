#include "MDElement.h"

MDElement::MDElement(e3::Element* pParent)
	: MDElementBase(pParent)
{

}

void MDElement::SetBackgroundColor(MDColor* pColor)
{
	mBackgroundColor = pColor;
	e3::Element::SetBackgroundColor(*pColor);
}

void MDElement::SetBorderColor(MDColor* pColor)
{
	mBorderColor = pColor;
	e3::Element::SetBorderColor(*pColor);
}

void MDElement::SetBackgroundColor(const glm::vec4& color)
{
	e3::Element::SetBackgroundColor(color);
}

void MDElement::SetBorderColor(const glm::vec4& color)
{
	e3::Element::SetBorderColor(color);
}

void MDElement::Render()
{
	if (mBackgroundColor) e3::Element::SetBackgroundColor(*mBackgroundColor);
	if (mBorderColor) 
	{
		e3::Element::SetBorderColor(*mBorderColor);
	}
	MDElementBase::Render();
}