#include "MDAppBarTitle.h"

MDAppBarTitle::MDAppBarTitle(e3::Element* pParent)
	: MDAppBarTitleBase(pParent)
{
	SetTextColor(MDTheme::Get()->AppBarTheme.TextColor);
}

void MDAppBarTitle::Render()
{
//	SetTextColor(MDTheme::Get()->AppBarTheme.TextColor);
	MDAppBarTitleBase::Render();
}