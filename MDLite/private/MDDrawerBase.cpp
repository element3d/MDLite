#include "MDDrawerBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDDrawerBase::MDDrawerBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth("100%");
        this->SetHeight("100%");
        this->SetPositionType((e3::EPositionType)1);
        this->SetLeft(0);
        this->SetVisibility((e3::EVisibility)1);
        this->SetAlignItemsHor((e3::EAlignment)0);
        this->SetOverflow((e3::EOverflow)0);

}
