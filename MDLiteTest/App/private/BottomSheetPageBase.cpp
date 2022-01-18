#include "BottomSheetPageBase.h"

#include <e3/ViewFactory.h>
#include "./MDLiteTestValues.h"

BottomSheetPageBase::BottomSheetPageBase(e3::Element* pParent)
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
                MDScaffold* pCustomView1 = new MDScaffold();
        AddElement(pCustomView1);
        pCustomView1->SetMarginTop(e3::Dim("0", "0", "0", "50", "50", "50"));
        pCustomView1->SetWidth(e3::Dim("100%", "100%", "100%", "500", "500", "500"));
        pCustomView1->SetHeight(e3::Dim("100%", "100%", "100%", "700", "700", "700"));
        pCustomView1->SetOrientation((e3::EOrientation)1);
        pCustomView1->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
                MDAppBar* pCustomView2 = new MDAppBar();
        pCustomView1->AddElement(pCustomView2);
        pCustomView2->SetAlignItemsHor((e3::EAlignment)3);
                MDAppBarTitle* pCustomView3 = new MDAppBarTitle();
        pCustomView2->AddElement(pCustomView3);
        pCustomView3->SetText("Bottom sheet");
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView1->AddElement(pElement2);
        pElement2->SetWidth("100%");
        pElement2->SetHeight("100%");
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetScaling((e3::EScaling)1);
        mShowButton = new MDButton();
        pElement2->AddElement(mShowButton);
        mShowButton->SetLabel(_s(SHOW BOTTOM SHEET));
        mBottomSheet = new MDBottomSheet();
        pCustomView1->AddElement(mBottomSheet);
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mBottomSheet->AddElement(pElement3);
        pElement3->SetHeight(300);
        pElement3->SetBackgroundColor(glm::vec4(255));
        pElement3->SetAlignItemsVer((e3::EAlignment)0);
        pElement3->SetOrientation((e3::EOrientation)1);
        e3::ShadowParams pElement3ShadowParams;
        pElement3ShadowParams.Color = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
        pElement3ShadowParams.BlurSize = 10;
        pElement3ShadowParams.Opacity = 1.0;
        pElement3ShadowParams.Scale = 1.0;
        pElement3ShadowParams.Offset = glm::ivec2(0, 10);
        pElement3->SetShadow(pElement3ShadowParams);
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement4);
        pElement4->SetWidth("100%");
        pElement4->SetHeight(70);
        e3::Text* pText1 = e3::ViewFactory::CreateText();
        pElement4->AddElement(pText1);
        pText1->SetText("Header");
        pText1->SetFontSize(18);
                MDDivider* pCustomView4 = new MDDivider();
        pElement3->AddElement(pCustomView4);
        pCustomView4->SetHeight(1);
        pCustomView4->SetBackgroundColor(glm::vec4(0, 0, 0, 50));
        mList = new MDListView();
        pElement3->AddElement(mList);

}
