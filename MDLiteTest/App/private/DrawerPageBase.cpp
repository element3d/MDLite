#include "DrawerPageBase.h"

#include <e3/ViewFactory.h>
#include ".\MDLiteTestValues.h"

DrawerPageBase::DrawerPageBase(e3::Element* pParent)
	: MDElement(pParent)
{
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
        pCustomView2->SetAlignItemsHor((e3::EAlignment)0);
        mDrawerButton = new MDAppBarAction();
        pCustomView2->AddElement(mDrawerButton);
        mDrawerButton->SetName(_s(menu));
        mDrawerButton->SetColor(glm::vec4(255));
                MDAppBarTitle* pCustomView3 = new MDAppBarTitle();
        pCustomView2->AddElement(pCustomView3);
        pCustomView3->SetText("Drawer");
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView1->AddElement(pElement2);
        pElement2->SetWidth("100%");
        pElement2->SetHeight("100%");
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetScaling((e3::EScaling)1);
        mDrawer = new MDDrawer();
        pCustomView1->AddElement(mDrawer);
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mDrawer->AddElement(pElement3);
        pElement3->SetWidth(e3::Dim("80%", "80%", "80%", "60%", "60%", "60%"));
        pElement3->SetHeight("100%");
        pElement3->SetOverflow((e3::EOverflow)0);
        pElement3->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        pElement3->SetAlignItemsVer((e3::EAlignment)0);
        pElement3->SetOrientation((e3::EOrientation)1);
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement3->AddElement(pElement4);
        pElement4->SetWidth("100%");
        pElement4->SetHeight("30%");
        pElement4->SetBackgroundColor(MDColors::Primary::Get());
        mItem1 = new MDListTile();
        pElement3->AddElement(mItem1);
        mItem1->SetLeading(new MDIcon("favorite", 18, MDColors::Grey::Get()));
        mItem1->SetTitle(_s(Item One));
        mItem2 = new MDListTile();
        pElement3->AddElement(mItem2);
        mItem2->SetLeading(new MDIcon("comment", 18, MDColors::Grey::Get()));
        mItem2->SetTitle(_s(Item Two));

}
