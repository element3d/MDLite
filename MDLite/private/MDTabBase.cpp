#include "MDTabBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDTabBase::MDTabBase(e3::Element* pParent)
	: MDInkWell(pParent)
{
        this->SetOrientation((e3::EOrientation)1);
        this->SetOverflow((e3::EOverflow)0);
        this->SetHeight(e3::Dim("144", "144", "144", "48", "48", "48"));
        this->SetBackgroundColor(MDColors::Primary::Get());
        mTopIcon = new MDIcon();
        AddElement(mTopIcon);
        mTopIcon->SetVisibility((e3::EVisibility)2);
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement1);
        pElement1->SetPaddingLeft(e3::Dim("20", "20", "40", "20", "20", "20"));
        pElement1->SetPaddingRight(e3::Dim("20", "20", "40", "20", "20", "20"));
        pElement1->SetPaddingTop(e3::Dim("10", "10", "40", "10", "10", "10"));
        pElement1->SetPaddingBottom(e3::Dim("10", "10", "40", "10", "10", "10"));
        mLeadingIcon = new MDIcon();
        pElement1->AddElement(mLeadingIcon);
        mLeadingIcon->SetMargin(0);
        mLabel = e3::ViewFactory::CreateText();
        pElement1->AddElement(mLabel);
        mLabel->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mLabel->SetFontStyle((e3::EFontStyle)2);
        mLabel->SetFontSize(e3::Dim("20", "20", "40", "14", "14", "14"));
    mHover = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mHover);
        mHover->SetHeight("100%");
        mHover->SetScaling((e3::EScaling)2);
        mHover->SetPositionType((e3::EPositionType)1);

}
