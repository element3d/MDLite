#include "MDNavigationRailBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDNavigationRailBase::MDNavigationRailBase(e3::Element* pParent)
	: MDElement(pParent)
{
        this->SetWidth(e3::Dim("60", "60", "168", "72", "72", "72"));
        this->SetHeight("100%");
        this->SetOrientation((e3::EOrientation)1);
        this->SetOverflow((e3::EOverflow)0);

}
