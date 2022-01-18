#include "MDDialogBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDDialogBase::MDDialogBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth("100%");
        this->SetHeight("100%");
        this->SetBackgroundColor(glm::vec4(0, 0, 0, 80));
        this->SetPositionType((e3::EPositionType)1);
        mBody = new MDElement();
        AddElement(mBody);
        mBody->SetOverflow((e3::EOverflow)0);
        mBody->SetOrientation((e3::EOrientation)1);
        mBody->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        e3::ShadowParams mBodyShadowParams;
        mBodyShadowParams.Color = glm::vec4(50, 50, 50, 55);
        mBodyShadowParams.BlurSize = 5;
        mBodyShadowParams.Opacity = 0.5;
        mBodyShadowParams.Scale = 1.0;
        mBodyShadowParams.Offset = glm::ivec2(5, 5);
        mBody->SetShadow(mBodyShadowParams);

}
