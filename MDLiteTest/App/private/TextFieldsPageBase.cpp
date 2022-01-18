#include "TextFieldsPageBase.h"

#include <e3/ViewFactory.h>
#include "./MDLiteTestValues.h"

TextFieldsPageBase::TextFieldsPageBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetOrientation((e3::EOrientation)1);
        this->SetAlignItemsVer((e3::EAlignment)0);
        this->SetBackgroundColor(glm::vec4(200, 200, 200, 255));
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement1);
        pElement1->SetWidth("100%");
        pElement1->SetHeight(40);
        pElement1->SetAlignItemsHor((e3::EAlignment)0);
        mBack = new MDIconButton();
        pElement1->AddElement(mBack);
        mBack->SetName(_s(arrow_back));
                MDScaffold* pCustomView1 = new MDScaffold();
        AddElement(pCustomView1);
        pCustomView1->SetMarginTop(20);
        pCustomView1->SetWidth(500);
        pCustomView1->SetHeight(700);
        pCustomView1->SetOrientation((e3::EOrientation)1);
                MDAppBar* pCustomView2 = new MDAppBar();
        pCustomView1->AddElement(pCustomView2);
        pCustomView2->SetAlignItemsHor((e3::EAlignment)0);
        e3::Text* pText1 = e3::ViewFactory::CreateText();
        pCustomView2->AddElement(pText1);
        pText1->SetText("Sliders");
        pText1->SetFontSize(18);
        pText1->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        pText1->SetFontStyle((e3::EFontStyle)2);
        pText1->SetMarginLeft(40);
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView1->AddElement(pElement2);
        pElement2->SetWidth("100%");
        pElement2->SetHeight("100%");
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetScaling((e3::EScaling)1);
                MDInput* pCustomView3 = new MDInput();
        pElement2->AddElement(pCustomView3);
        pCustomView3->SetLabelText(_s(Name*));
        pCustomView3->SetHintText(_s(What do people call you?));
                MDInput* pCustomView4 = new MDInput();
        pElement2->AddElement(pCustomView4);
        pCustomView4->SetMarginTop(20);
        pCustomView4->SetLabelText(_s(Phone number*));
        pCustomView4->SetHintText(_s(Where can we reach you?));
        pCustomView4->SetPrefixText(_s(+1));

}
