#include "MenuPageBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteTestValues.h"

MenuPageBase::MenuPageBase(e3::Element* pParent)
	: e3::Element(pParent)
{
    mContextMenuBody = new MDMenuBody();
                MDMenuItem* pCustomView1 = new MDMenuItem();
        mContextMenuBody->AddElement(pCustomView1);
                MDListTile* pCustomView2 = new MDListTile();
        pCustomView1->AddElement(pCustomView2);
        pCustomView2->SetTitle(_s(menu 1));
                MDMenuItem* pCustomView3 = new MDMenuItem();
        mContextMenuBody->AddElement(pCustomView3);
        pCustomView3->SetEnabled(false);
                MDListTile* pCustomView4 = new MDListTile();
        pCustomView3->AddElement(pCustomView4);
        pCustomView4->SetTitle(_s(menu 2));
    mMenuBody1 = new MDMenuBody();
                MDMenuItem* pCustomView5 = new MDMenuItem();
        mMenuBody1->AddElement(pCustomView5);
                MDListTile* pCustomView6 = new MDListTile();
        pCustomView5->AddElement(pCustomView6);
        pCustomView6->SetTitle(_s(menu 1));
                MDMenuItem* pCustomView7 = new MDMenuItem();
        mMenuBody1->AddElement(pCustomView7);
        pCustomView7->SetEnabled(false);
                MDListTile* pCustomView8 = new MDListTile();
        pCustomView7->AddElement(pCustomView8);
        pCustomView8->SetTitle(_s(menu 2));
    mContextMenu = new MDMenu();
        mContextMenu->SetBody(mContextMenuBody);
                MDIconButton* pCustomView9 = new MDIconButton();
        mContextMenu->AddElement(pCustomView9);
        pCustomView9->SetName(_s(more_vert));
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
                MDAppBar* pCustomView10 = new MDAppBar();
        pElement2->AddElement(pCustomView10);
        pCustomView10->SetAlignItemsHor((e3::EAlignment)0);
                MDAppBarTitle* pCustomView11 = new MDAppBarTitle();
        pCustomView10->AddElement(pCustomView11);
        pCustomView11->SetText("Menus");
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement2->AddElement(pElement3);
        pElement3->SetWidth("100%");
        pElement3->SetHeight("100%");
        pElement3->SetOrientation((e3::EOrientation)1);
        pElement3->SetScaling((e3::EScaling)1);
        e3::Text* pText1 = e3::ViewFactory::CreateText();
        pElement3->AddElement(pText1);
        pText1->SetText("Context menu");
        pText1->SetFontSize(18);
        pText1->SetFontStyle((e3::EFontStyle)2);
        pText1->SetTextColor(MDColors::Grey::Get("800"));
                MDListTile* pCustomView12 = new MDListTile();
        pElement3->AddElement(pCustomView12);
        pCustomView12->SetMarginTop(10);
        pCustomView12->SetTitle(_s(An item with a context menu));
        pCustomView12->SetTrailing(mContextMenu);
        e3::Text* pText2 = e3::ViewFactory::CreateText();
        pElement3->AddElement(pText2);
        pText2->SetMarginTop(20);
        pText2->SetText("Simple menu");
        pText2->SetFontSize(18);
        pText2->SetFontStyle((e3::EFontStyle)2);
        pText2->SetTextColor(MDColors::Grey::Get("800"));
                MDMenu* pCustomView13 = new MDMenu();
        pElement3->AddElement(pCustomView13);
        pCustomView13->SetMarginTop(10);
        pCustomView13->SetBody(mMenuBody1);
                MDInkWell* pCustomView14 = new MDInkWell();
        pCustomView13->AddElement(pCustomView14);
        pCustomView14->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
                MDListTile* pCustomView15 = new MDListTile();
        pCustomView14->AddElement(pCustomView15);
        pCustomView15->SetTitle(_s(An item with a simple menu));

}
