#include "MDTextButtonBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDTextButtonBase::MDTextButtonBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetHeight(e3::Dim("35", "55", "100", "36", "36", "36"));
        this->SetMargin(4);
        this->SetBorderRadius(glm::vec4(10.000000, 10.000000, 10.000000, 10.000000));
        this->SetOverflow((e3::EOverflow)0);
    mIconCont = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mIconCont);
        mLabel = new MDText();
        AddElement(mLabel);
        mLabel->SetFontStyle((e3::EFontStyle)2);
        mLabel->SetMarginRight(e3::Dim("20", "20", "30", "16", "16", "16"));
        mLabel->SetMarginLeft(e3::Dim("20", "20", "30", "16", "16", "16"));
        mLabel->SetFontSize(e3::Dim("18", "22", "40", "16", "16", "16"));
    mHover = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mHover);
        mHover->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        mHover->SetHeight("100%");
        mHover->SetScaling((e3::EScaling)2);
        mHover->SetPositionType((e3::EPositionType)1);

}
