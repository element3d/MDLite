#include "MDInkWellBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDInkWellBase::MDInkWellBase(e3::Element* pParent)
	: MDElement(pParent)
{
        this->SetOverflow((e3::EOverflow)0);
    mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetWidth(e3::Dim("20", "20", "40", "80", "80", "80"));
        mRipple->SetAspectRatio(1.000000);
        mRipple->SetShapeType((e3::EShapeType)1);
        mRipple->SetLeft(0);
        mRipple->SetTop(0);
        mRipple->SetBackgroundColor(glm::vec4(0.000000, 0.000000, 0.000000, 0.000000));

}
