#include "MDRadioBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDRadioBase::MDRadioBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(e3::Dim("22", "33", "50", "22", "20", "20"));
        this->SetHeight(e3::Dim("22", "33", "50", "20", "20", "20"));
        this->SetShapeType((e3::EShapeType)1);
        this->SetBorderSize(e3::Dim("5", "5", "10", "2", "2", "2"));
        this->SetMargin(e3::Dim("(8", "8", "25", "(8", "8", "25"));
        this->SetBorderColor(glm::vec4(96, 2, 238, 255));
    mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetAspectRatio(1.000000);
        mRipple->SetHeight(40.000000);
        mRipple->SetShapeType((e3::EShapeType)1);
    mCheck = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mCheck);
        mCheck->SetWidth(e3::Dim("10", "15", "25", "10", "10", "10"));
        mCheck->SetHeight(e3::Dim("10", "15", "25", "10", "10", "10"));
        mCheck->SetShapeType((e3::EShapeType)1);

}
