#include "AppBarPageBase.h"

#include <e3/ViewFactory.h>
#include "./MDLiteTestValues.h"

AppBarPageBase::AppBarPageBase(e3::Element* pParent)
	: MDElement(pParent)
{
    mMenuBody = new MDMenuBody();
                MDMenuItem* pCustomView1 = new MDMenuItem();
        mMenuBody->AddElement(pCustomView1);
                MDListTile* pCustomView2 = new MDListTile();
        pCustomView1->AddElement(pCustomView2);
        pCustomView2->SetTitle(_s(menu 1));
                MDMenuItem* pCustomView3 = new MDMenuItem();
        mMenuBody->AddElement(pCustomView3);
        pCustomView3->SetEnabled(false);
                MDListTile* pCustomView4 = new MDListTile();
        pCustomView3->AddElement(pCustomView4);
        pCustomView4->SetTitle(_s(menu 2));
        this->SetOrientation((e3::EOrientation)1);
        this->SetAlignItemsVer((e3::EAlignment)0);
        this->SetBackgroundColor(MDTheme::Get()->Background);
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement1);
        pElement1->SetWidth("100%");
        pElement1->SetHeight(e3::Dim("0", "0", "0", "40", "40", "40"));
        pElement1->SetAlignItemsHor((e3::EAlignment)0);
        mBack = new MDIconButton();
        pElement1->AddElement(mBack);
        mBack->SetColor(MDTheme::Get()->OnBackground);
        mBack->SetName(_s(arrow_back));
                MDScaffold* pCustomView5 = new MDScaffold();
        AddElement(pCustomView5);
        pCustomView5->SetMarginTop(e3::Dim("0", "0", "0", "50", "50", "50"));
        pCustomView5->SetWidth(e3::Dim("100%", "100%", "100%", "500", "500", "500"));
        pCustomView5->SetHeight(e3::Dim("100%", "100%", "100%", "700", "700", "700"));
        pCustomView5->SetOrientation((e3::EOrientation)1);
        pCustomView5->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
                MDAppBar* pCustomView6 = new MDAppBar();
        pCustomView5->AddElement(pCustomView6);
        pCustomView6->SetAlignItemsHor((e3::EAlignment)3);
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView6->AddElement(pElement2);
                MDAppBarAction* pCustomView7 = new MDAppBarAction();
        pElement2->AddElement(pCustomView7);
        pCustomView7->SetName(_s(menu));
        pCustomView7->SetColor(glm::vec4(255));
                MDAppBarTitle* pCustomView8 = new MDAppBarTitle();
        pElement2->AddElement(pCustomView8);
        pCustomView8->SetText("App bar");
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView6->AddElement(pElement3);
                MDAppBarAction* pCustomView9 = new MDAppBarAction();
        pElement3->AddElement(pCustomView9);
        pCustomView9->SetName(_s(menu));
        pCustomView9->SetColor(glm::vec4(255));
                MDAppBarAction* pCustomView10 = new MDAppBarAction();
        pElement3->AddElement(pCustomView10);
        pCustomView10->SetName(_s(menu));
        pCustomView10->SetColor(glm::vec4(255));
                MDMenu* pCustomView11 = new MDMenu();
        pElement3->AddElement(pCustomView11);
        pCustomView11->SetBody(mMenuBody);
                MDAppBarAction* pCustomView12 = new MDAppBarAction();
        pCustomView11->AddElement(pCustomView12);
        pCustomView12->SetName(_s(more_vert));
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView5->AddElement(pElement4);
        pElement4->SetWidth("100%");
        pElement4->SetHeight("100%");
        pElement4->SetOrientation((e3::EOrientation)1);
        pElement4->SetScaling((e3::EScaling)1);

}
