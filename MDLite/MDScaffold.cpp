#include "MDScaffold.h"

MDScaffold::MDScaffold(e3::Element* pParent)
	: MDScaffoldBase(pParent)
{
	SetBackgroundColor(MDTheme::Get()->ScaffoldBackgroundColor);
}

void MDScaffold::Render()
{
//	SetBackgroundColor(MDTheme::Get()->ScaffoldBackgroundColor);
	MDScaffoldBase::Render();
}