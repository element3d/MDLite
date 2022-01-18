#include "SelectionControlsPageBase.h"

#include <e3/ViewFactory.h>
#include ".\MDLiteTestValues.h"

SelectionControlsPageBase::SelectionControlsPageBase(e3::Element* pParent)
	: e3::Element(pParent)
{
    mRadioGroup = new MDRadioGroup();
        this->SetOrientation((e3::EOrientation)1);
        this->SetAlignItemsVer((e3::EAlignment)0);
        this->SetBackgroundColor(glm::vec4(200, 200, 200, 255));
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement1);
        pElement1->SetWidth("100%");
        pElement1->SetHeight(e3::Dim("0", "0", "0", "40", "40", "40"));
        pElement1->SetAlignItemsHor((e3::EAlignment)0);
        mBack = new MDIconButton();
        pElement1->AddElement(mBack);
        mBack->SetName(_s(arrow_back));
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement2);
        pElement2->SetMarginTop(e3::Dim("0", "0", "0", "50", "50", "50"));
        pElement2->SetWidth(e3::Dim("100%", "100%", "100%", "500", "500", "500"));
        pElement2->SetHeight(e3::Dim("100%", "100%", "100%", "700", "700", "700"));
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
                MDAppBar* pCustomView1 = new MDAppBar();
        pElement2->AddElement(pCustomView1);
        pCustomView1->SetAlignItemsHor((e3::EAlignment)0);
                MDAppBarTitle* pCustomView2 = new MDAppBarTitle();
        pCustomView1->AddElement(pCustomView2);
        pCustomView2->SetText("Selection controls");
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement2->AddElement(pElement3);
        pElement3->SetWidth("100%");
        pElement3->SetHeight("100%");
        pElement3->SetOrientation((e3::EOrientation)1);
        pElement3->SetScaling((e3::EScaling)1);
        e3::Text* pText1 = e3::ViewFactory::CreateText();
        pElement3->AddElement(pText1);
        pText1->SetText("MDCheckbox");
        pText1->SetFontSize(18);
        pText1->SetFontStyle((e3::EFontStyle)2);
        pText1->SetTextColor(MDColors::Grey::Get("800"));
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement4);
        pElement4->SetMarginTop(20);
    mCheckTest1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement4->AddElement(mCheckTest1);
        mCheckTest1->SetWidth(40);
        mCheckTest1->SetHeight(5);
        mCheckTest1->SetBackgroundColor(MDColors::Grey::Get());
        mCheckTest1->SetMarginRight(10);
    mCheckTest2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement4->AddElement(mCheckTest2);
        mCheckTest2->SetWidth(40);
        mCheckTest2->SetHeight(5);
        mCheckTest2->SetBackgroundColor(MDColors::Grey::Get());
        mCheckTest2->SetMarginRight(10);
    mCheckTest3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement4->AddElement(mCheckTest3);
        mCheckTest3->SetWidth(40);
        mCheckTest3->SetHeight(5);
        mCheckTest3->SetBackgroundColor(MDColors::Grey::Get());
    e3::Element* pElement5 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement5);
        mCheckbox1 = new MDCheckbox();
        pElement5->AddElement(mCheckbox1);
        mCheckbox2 = new MDCheckbox();
        pElement5->AddElement(mCheckbox2);
        mCheckbox3 = new MDCheckbox();
        pElement5->AddElement(mCheckbox3);
        e3::Text* pText2 = e3::ViewFactory::CreateText();
        pElement3->AddElement(pText2);
        pText2->SetText("MDRadio");
        pText2->SetMarginTop(40);
        pText2->SetFontSize(18);
        pText2->SetFontStyle((e3::EFontStyle)2);
        pText2->SetTextColor(MDColors::Grey::Get("800"));
    e3::Element* pElement6 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement6);
        pElement6->SetMarginTop(20);
    mRadioTest1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement6->AddElement(mRadioTest1);
        mRadioTest1->SetWidth(40);
        mRadioTest1->SetHeight(5);
        mRadioTest1->SetBackgroundColor(MDColors::Grey::Get());
        mRadioTest1->SetMarginRight(10);
    mRadioTest2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement6->AddElement(mRadioTest2);
        mRadioTest2->SetWidth(40);
        mRadioTest2->SetHeight(5);
        mRadioTest2->SetBackgroundColor(MDColors::Grey::Get());
        mRadioTest2->SetMarginRight(10);
    mRadioTest3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement6->AddElement(mRadioTest3);
        mRadioTest3->SetWidth(40);
        mRadioTest3->SetHeight(5);
        mRadioTest3->SetBackgroundColor(MDColors::Grey::Get());
    e3::Element* pElement7 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement7);
        mRadio1 = new MDRadio();
        pElement7->AddElement(mRadio1);
        mRadio1->SetGroup(mRadioGroup);
        mRadio2 = new MDRadio();
        pElement7->AddElement(mRadio2);
        mRadio2->SetGroup(mRadioGroup);
        mRadio3 = new MDRadio();
        pElement7->AddElement(mRadio3);
        mRadio3->SetGroup(mRadioGroup);
        e3::Text* pText3 = e3::ViewFactory::CreateText();
        pElement3->AddElement(pText3);
        pText3->SetText("MDSwitch");
        pText3->SetMarginTop(40);
        pText3->SetFontSize(18);
        pText3->SetFontStyle((e3::EFontStyle)2);
        pText3->SetTextColor(MDColors::Grey::Get("800"));
    e3::Element* pElement8 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement8);
        pElement8->SetMarginTop(20);
    mSwitchTest1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement8->AddElement(mSwitchTest1);
        mSwitchTest1->SetWidth(40);
        mSwitchTest1->SetHeight(5);
        mSwitchTest1->SetBackgroundColor(MDColors::Grey::Get());
        mSwitchTest1->SetMarginRight(10);
        mSwitch = new MDSwitch();
        pElement3->AddElement(mSwitch);
        mSwitch->SetMarginTop(20);

}