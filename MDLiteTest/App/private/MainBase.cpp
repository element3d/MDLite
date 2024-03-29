#include "MainBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteTestValues.h"

MainBase::MainBase(e3::Element* pParent)
	: MDElement(pParent)
{
        this->SetOrientation((e3::EOrientation)1);
        this->SetBackgroundColor(MDTheme::Get()->Background);
        this->SetOverflow((e3::EOverflow)2);
        this->SetAlignItemsHor((e3::EAlignment)2);
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement1);
        pElement1->SetWidth("100%");
        pElement1->SetHeight(50);
        pElement1->SetMarginTop(e3::Dim("10", "20", "30", "10", "10", "10"));
        mDarkModeSwitch = new MDSwitch();
        pElement1->AddElement(mDarkModeSwitch);
                MDText* pCustomView1 = new MDText();
        AddElement(pCustomView1);
        pCustomView1->SetMarginTop(e3::Dim("10", "20", "30", "10", "10", "10"));
        pCustomView1->SetText("MATERIAL");
        pCustomView1->SetFontSize(e3::Dim("150", "150", "150", "50", "50", "50"));
        pCustomView1->SetTextColor(MDTheme::Get()->OnBackground);
        pCustomView1->SetFontStyle((e3::EFontStyle)2);
                MDText* pCustomView2 = new MDText();
        AddElement(pCustomView2);
        pCustomView2->SetMarginTop(e3::Dim("10", "20", "30", "10", "10", "10"));
        pCustomView2->SetText("DESIGN");
        pCustomView2->SetFontSize(e3::Dim("90", "90", "90", "30", "30", "30"));
        pCustomView2->SetTextColor(MDTheme::Get()->OnBackground);
        pCustomView2->SetFontStyle((e3::EFontStyle)2);
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement2);
        pElement2->SetMarginTop(e3::Dim("30", "30", "30", "10", "10", "10"));
        pElement2->SetWidth(e3::Dim("100%", "100%", "100%", "400", "400", "400"));
        pElement2->SetOverflow((e3::EOverflow)0);
        pElement2->SetAlignItemsVer((e3::EAlignment)0);
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetBorderRadius(glm::vec4(20, 20, 0, 0));
                MDCol* pCustomView3 = new MDCol();
        pElement2->AddElement(pCustomView3);
                MDRow* pCustomView4 = new MDRow();
        pCustomView3->AddElement(pCustomView4);
        mAppBarPage = new MainMenuItem();
        pCustomView4->AddElement(mAppBarPage);
        mAppBarPage->SetIcon(_s(web_asset));
        mAppBarPage->SetTitle(_s(App bar));
        mButtonPage = new MainMenuItem();
        pCustomView4->AddElement(mButtonPage);
        mButtonPage->SetIcon(_s(crop_7_5));
        mButtonPage->SetTitle(_s(Кнопки));
                MDRow* pCustomView5 = new MDRow();
        pCustomView3->AddElement(pCustomView5);
        mBottomNavBarPage = new MainMenuItem();
        pCustomView5->AddElement(mBottomNavBarPage);
        mBottomNavBarPage->SetIcon(_s(video_label));
        mBottomNavBarPage->SetTitle(_s(Bottom navbar));
        mDrawerPage = new MainMenuItem();
        pCustomView5->AddElement(mDrawerPage);
        mDrawerPage->SetIcon(_s(menu));
        mDrawerPage->SetTitle(_s(Drawer));
                MDRow* pCustomView6 = new MDRow();
        pCustomView3->AddElement(pCustomView6);
        mBottomSheetPage = new MainMenuItem();
        pCustomView6->AddElement(mBottomSheetPage);
        mBottomSheetPage->SetIcon(_s(video_label));
        mBottomSheetPage->SetTitle(_s(Bottom sheet));
        mNavRailPage = new MainMenuItem();
        pCustomView6->AddElement(mNavRailPage);
        mNavRailPage->SetIcon(_s(video_label));
        mNavRailPage->SetTitle(_s(Navigation rail));
                MDRow* pCustomView7 = new MDRow();
        pCustomView3->AddElement(pCustomView7);
        mDialogPage = new MainMenuItem();
        pCustomView7->AddElement(mDialogPage);
        mDialogPage->SetIcon(_s(crop_square));
        mDialogPage->SetTitle(_s(Dialog));
        mMenuPage = new MainMenuItem();
        pCustomView7->AddElement(mMenuPage);
        mMenuPage->SetIcon(_s(more_vert));
        mMenuPage->SetTitle(_s(Menu));
                MDRow* pCustomView8 = new MDRow();
        pCustomView3->AddElement(pCustomView8);
        mProgressIndicatorsPage = new MainMenuItem();
        pCustomView8->AddElement(mProgressIndicatorsPage);
        mProgressIndicatorsPage->SetIcon(_s(refresh));
        mProgressIndicatorsPage->SetTitle(_s(Progress indicators));
        mSelectionControlsPage = new MainMenuItem();
        pCustomView8->AddElement(mSelectionControlsPage);
        mSelectionControlsPage->SetIcon(_s(check_box));
        mSelectionControlsPage->SetTitle(_s(Selection controls));
                MDRow* pCustomView9 = new MDRow();
        pCustomView3->AddElement(pCustomView9);
        mSlidersPage = new MainMenuItem();
        pCustomView9->AddElement(mSlidersPage);
        mSlidersPage->SetIcon(_s(linear_scale));
        mSlidersPage->SetTitle(_s(Sliders));
        mTabsPage = new MainMenuItem();
        pCustomView9->AddElement(mTabsPage);
        mTabsPage->SetIcon(_s(tab));
        mTabsPage->SetTitle(_s(Tabs));
                MDRow* pCustomView10 = new MDRow();
        pCustomView3->AddElement(pCustomView10);
        mTextFieldsPage = new MainMenuItem();
        pCustomView10->AddElement(mTextFieldsPage);
        mTextFieldsPage->SetIcon(_s(input));
        mTextFieldsPage->SetTitle(_s(Text fields));
        mListPage = new MainMenuItem();
        pCustomView10->AddElement(mListPage);
        mListPage->SetIcon(_s(list));
        mListPage->SetTitle(_s(List));
                MDRow* pCustomView11 = new MDRow();
        pCustomView3->AddElement(pCustomView11);
        mSnackbarPage = new MainMenuItem();
        pCustomView11->AddElement(mSnackbarPage);
        mSnackbarPage->SetIcon(_s(input));
        mSnackbarPage->SetTitle(_s(Snackbar));

}
