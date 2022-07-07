#include "MDOutlinedButtonBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDOutlinedButtonBase::MDOutlinedButtonBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetHeight(e3::Dim("35", "55", "100", "36", "36", "36"));
        this->SetBorderColor(MDColors::Primary::Get());
        this->SetBorderRadius(glm::vec4(10.000000, 10.000000, 10.000000, 10.000000));
        this->SetBorderSize(1);
    mIconCont = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mIconCont);
        mLabel = e3::ViewFactory::CreateText();
        AddElement(mLabel);
        mLabel->SetFontStyle((e3::EFontStyle)2);
        mLabel->SetMarginRight(e3::Dim("20", "20", "30", "16", "16", "16"));
        mLabel->SetMarginLeft(e3::Dim("20", "20", "30", "16", "16", "16"));
        mLabel->SetFontSize(e3::Dim("18", "22", "40", "16", "16", "16"));
        mLabel->SetTextColor(glm::vec4(96, 2, 238, 255));
    mHover = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mHover);
        mHover->SetHeight("100%");
        mHover->SetScaling((e3::EScaling)2);
        mHover->SetPositionType((e3::EPositionType)1);

}
