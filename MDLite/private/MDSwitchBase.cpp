#include "MDSwitchBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDSwitchBase::MDSwitchBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(e3::Dim("40", "55", "100", "36", "36", "36"));
        this->SetHeight(e3::Dim("20", "30", "60", "20", "20", "20"));
    mBack = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mBack);
        mBack->SetWidth("100%");
        mBack->SetHeight("70%");
        mBack->SetBorderRadius(glm::vec4(0.500000, 0.500000, 0.500000, 0.500000));
        mBack->SetBackgroundColor(glm::vec4(153.000000, 101.000000, 244.000000, 255.000000));
    mCircle = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mCircle);
        mCircle->SetPositionType((e3::EPositionType)1);
        mCircle->SetLeft(0.000000);
        mCircle->SetAspectRatio(1.000000);
        mCircle->SetHeight("100%");
        mCircle->SetBorderRadius(glm::vec4(0.500000, 0.500000, 0.500000, 0.500000));
        e3::ShadowParams mCircleShadowParams;
        mCircleShadowParams.Color = glm::vec4(100, 100, 100, 100);
        mCircleShadowParams.BlurSize = 2;
        mCircleShadowParams.Opacity = 1.0;
        mCircleShadowParams.Scale = 1.0;
        mCircleShadowParams.Offset = glm::ivec2(0, 1);
        mCircle->SetShadow(mCircleShadowParams);
    mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mCircle->AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetAspectRatio(1.000000);
        mRipple->SetHeight(40.000000);
        mRipple->SetShapeType((e3::EShapeType)1);

}
