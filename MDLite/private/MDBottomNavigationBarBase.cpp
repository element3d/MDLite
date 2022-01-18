#include "MDBottomNavigationBarBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDBottomNavigationBarBase::MDBottomNavigationBarBase(e3::Element* pParent)
	: MDElement(pParent)
{
        this->SetWidth("100%");
        this->SetHeight(e3::Dim("60", "60", "168", "56", "56", "56"));
        this->SetOverflow((e3::EOverflow)0);

}
