#include "MDAppBarAction.h"

MDAppBarAction::MDAppBarAction(e3::Element* pParent)
	: MDAppBarActionBase(pParent)
{
	SetColor(MDTheme::Get()->AppBarTheme.IconColor);
}
