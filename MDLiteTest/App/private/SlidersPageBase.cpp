#include "SlidersPageBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteTestValues.h"

SlidersPageBase::SlidersPageBase(e3::Element* pParent)
	: e3::Element(pParent)
{
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
        pElement2->SetMarginTop(e3::Dim("0", "0", "0", "20", "20", "20"));
        pElement2->SetWidth(e3::Dim("100%", "100%", "100%", "500", "500", "500"));
        pElement2->SetHeight(e3::Dim("100%", "100%", "100%", "700", "700", "700"));
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
                MDAppBar* pCustomView1 = new MDAppBar();
        pElement2->AddElement(pCustomView1);
        pCustomView1->SetAlignItemsHor((e3::EAlignment)0);
                MDAppBarTitle* pCustomView2 = new MDAppBarTitle();
        pCustomView1->AddElement(pCustomView2);
        pCustomView2->SetText("Sliders");
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement2->AddElement(pElement3);
        pElement3->SetWidth("100%");
        pElement3->SetHeight("100%");
        pElement3->SetOrientation((e3::EOrientation)1);
        pElement3->SetScaling((e3::EScaling)1);
        mInput = new MDInput();
        pElement3->AddElement(mInput);
        mInput->SetWidth(e3::Dim("300", "300", "300", "100", "100", "100"));
        mSlider = new MDSlider();
        pElement3->AddElement(mSlider);
        mSlider->SetMarginTop(e3::Dim("90", "90", "90", "30", "30", "30"));
        mDivSlider = new MDSlider();
        pElement3->AddElement(mDivSlider);
        mDivSlider->SetDivisions(5);
        mDivSlider->SetMarginTop(e3::Dim("90", "90", "90", "30", "30", "30"));

}
