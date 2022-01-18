#include "MDButtonBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDButtonBase::MDButtonBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetHeight(e3::Dim("35", "55", "100", "36", "36", "36"));
        this->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        this->SetOverflow((e3::EOverflow)0);
        this->SetBackgroundColor(MDTheme::Get()->PrimaryColor);
    mIconCont = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mIconCont);
        mLabel = new MDText();
        AddElement(mLabel);
        mLabel->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mLabel->SetFontStyle((e3::EFontStyle)2);
        mLabel->SetTextColor(MDTheme::Get()->OnPrimary);
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
