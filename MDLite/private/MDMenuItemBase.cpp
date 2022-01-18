#include "MDMenuItemBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDMenuItemBase::MDMenuItemBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        this->SetOverflow((e3::EOverflow)0);
        this->SetWidth("100%");
        this->SetHeight(e3::Dim("50", "50", "120", "50", "50", "50"));
    mHover = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mHover);
        mHover->SetHeight("100%");
        mHover->SetScaling((e3::EScaling)2);
        mHover->SetPositionType((e3::EPositionType)1);

}
