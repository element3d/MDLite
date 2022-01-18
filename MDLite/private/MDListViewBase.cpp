#include "MDListViewBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDListViewBase::MDListViewBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetOverflow((e3::EOverflow)2);
        this->SetWidth("100%");
        this->SetHeight("100%");
        this->SetOrientation((e3::EOrientation)1);
        this->SetScaling((e3::EScaling)1);

}
