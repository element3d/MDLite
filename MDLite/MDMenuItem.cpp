#include "MDMenuItem.h"

MDMenuItem::MDMenuItem(e3::Element* pParent)
	: MDMenuItemBase(pParent)
{

}

void MDMenuItem::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDMenuItemBase::OnMouseEnter(pEvent);
	mHover->SetWidth(GetGeometry().width);
	mHover->SetHeight(GetGeometry().height);
	mHover->SetBackgroundColor(glm::vec4(0, 0, 0, 10));
}

void MDMenuItem::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDMenuItemBase::OnMouseLeave(pEvent);
	mHover->SetBackgroundColor(glm::vec4(255, 255, 255, 0));
}