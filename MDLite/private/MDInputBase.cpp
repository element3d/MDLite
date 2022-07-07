#include "MDInputBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDInputBase::MDInputBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetOrientation((e3::EOrientation)1);
        this->SetWidth(e3::Dim("300", "400", "600", "300", "300", "300"));
        mContainer = new MDElement();
        AddElement(mContainer);
        mContainer->SetOrientation((e3::EOrientation)1);
        mContainer->SetWidth("100%");
        mContainer->SetHeight(e3::Dim("60", "80", "150", "48", "48", "48"));
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mContainer->AddElement(pElement1);
        pElement1->SetWidth("100%");
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement1->AddElement(pElement2);
        pElement2->SetWidth(e3::Dim("10", "15", "20", "16", "16", "16"));
        pElement2->SetHeight(e3::Dim("17", "22", "40", "16", "16", "16"));
        mLabelText = e3::ViewFactory::CreateText();
        pElement1->AddElement(mLabelText);
        mLabelText->SetScaling((e3::EScaling)1);
        mLabelText->SetWidth("100%");
        mLabelText->SetTextAlignHor((e3::EAlignment)0);
        mLabelText->SetFontSize(e3::Dim("17", "22", "40", "16", "16", "16"));
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mContainer->AddElement(pElement3);
        pElement3->SetWidth("100%");
        mPrefixText = e3::ViewFactory::CreateText();
        pElement3->AddElement(mPrefixText);
        mPrefixText->SetVisibility((e3::EVisibility)2);
        mPrefixText->SetFontSize("16dp");
        mPrefixText->SetMarginLeft(e3::Dim("10", "15", "20", "16", "16", "16"));
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement4);
        pElement4->SetWidth("100%");
        pElement4->SetHeight("20dp");
        pElement4->SetScaling((e3::EScaling)1);
        pElement4->SetMarginLeft(e3::Dim("10", "15", "20", "16", "16", "16"));
        mInput = e3::ViewFactory::CreateInput();
        pElement4->AddElement(mInput);
        mInput->SetWidth("100%");
        mInput->SetHeight("20dp");
        mInput->SetScaling((e3::EScaling)1);
        mInput->SetFontSize(e3::Dim("17", "22", "40", "16", "16", "16"));
        mHintText = e3::ViewFactory::CreateText();
        pElement4->AddElement(mHintText);
        mHintText->SetWidth("100%");
        mHintText->SetHeight("20dp");
        mHintText->SetPositionType((e3::EPositionType)1);
        mHintText->SetTextAlignHor((e3::EAlignment)0);
        mHintText->SetFontSize(e3::Dim("17", "22", "40", "16", "16", "16"));
        mUnderline = new MDDivider();
        mContainer->AddElement(mUnderline);
        mUnderline->SetWidth("100%");
        mUnderline->SetPositionType((e3::EPositionType)1);
        mUnderline->SetBottom(0);
        mUnderline->SetHeight(e3::Dim("2", "2", "4", "2", "2", "2"));

}
