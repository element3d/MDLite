#include "MDBottomSheetBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDBottomSheetBase::MDBottomSheetBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth("100%");
        this->SetHeight("100%");
        this->SetPositionType((e3::EPositionType)1);
        this->SetBottom(0);
        this->SetVisibility((e3::EVisibility)1);
        this->SetAlignItemsVer((e3::EAlignment)1);
        this->SetOverflow((e3::EOverflow)0);

}
