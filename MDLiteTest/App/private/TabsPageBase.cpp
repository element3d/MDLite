#include "TabsPageBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteTestValues.h"

TabsPageBase::TabsPageBase(e3::Element* pParent)
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
        pCustomView2->SetText("Tabs");
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement2->AddElement(pElement3);
        pElement3->SetWidth("100%");
        pElement3->SetHeight("100%");
        pElement3->SetOrientation((e3::EOrientation)1);
        pElement3->SetScaling((e3::EScaling)1);
        mTabBar = new MDTabBar();
        pElement3->AddElement(mTabBar);
        mTabBar->SetWidth("100%");
        mTabBar->SetIsScrollable(false);
                MDTab* pCustomView3 = new MDTab();
        mTabBar->AddElement(pCustomView3);
        pCustomView3->SetLeadingIcon(_s(favorite));
        pCustomView3->SetTextLabel(_s(RED));
                MDTab* pCustomView4 = new MDTab();
        mTabBar->AddElement(pCustomView4);
        pCustomView4->SetLeadingIcon(_s(favorite));
        pCustomView4->SetTextLabel(_s(ORANGE));
                MDTab* pCustomView5 = new MDTab();
        mTabBar->AddElement(pCustomView5);
        pCustomView5->SetLeadingIcon(_s(favorite));
        pCustomView5->SetTextLabel(_s(GREEN));
        mTabBarView = new MDTabBarView();
        pElement3->AddElement(mTabBarView);
        mTabBarView->SetTabBar(mTabBar);
        mTabBarView->SetWidth("100%");
        mTabBarView->SetHeight("100%");
        mTabBarView->SetScaling((e3::EScaling)1);
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mTabBarView->AddElement(pElement4);
        e3::Text* pText1 = e3::ViewFactory::CreateText();
        pElement4->AddElement(pText1);
        pText1->SetText("RED");
        pText1->SetFontSize("30dp");
    e3::Element* pElement5 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mTabBarView->AddElement(pElement5);
        e3::Text* pText2 = e3::ViewFactory::CreateText();
        pElement5->AddElement(pText2);
        pText2->SetText("Orange");
        pText2->SetFontSize("30dp");
    e3::Element* pElement6 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mTabBarView->AddElement(pElement6);
        e3::Text* pText3 = e3::ViewFactory::CreateText();
        pElement6->AddElement(pText3);
        pText3->SetText("GREEN");
        pText3->SetFontSize("30dp");

}
