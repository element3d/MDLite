#include "MDFloatingActionButtonExtendedBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDFloatingActionButtonExtendedBase::MDFloatingActionButtonExtendedBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetHeight(e3::Dim("144", "144", "144", "48", "48", "48"));
        this->SetPadding(e3::Dim("20", "20", "60", "20", "20", "20"));
        this->SetBorderRadius(glm::vec4(0.500000, 0.500000, 0.500000, 0.500000));
        this->SetOverflow((e3::EOverflow)0);
        this->SetBackgroundColor(glm::vec4(96, 2, 238, 255));
        e3::ShadowParams ShadowParams;
        ShadowParams.Color = glm::vec4(100.000000, 100.000000, 100.000000, 255.000000);
        ShadowParams.BlurSize = 20;
        ShadowParams.Opacity = 1.0;
        ShadowParams.Scale = 1.0;
        ShadowParams.Offset = glm::ivec2(0, 10);
        SetShadow(ShadowParams);
    mIconCont = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mIconCont);
    mLabelCont = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mLabelCont);
    mHover = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mHover);
        mHover->SetHeight("100%");
        mHover->SetScaling((e3::EScaling)2);
        mHover->SetPositionType((e3::EPositionType)1);

}
