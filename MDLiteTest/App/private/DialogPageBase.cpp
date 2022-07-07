#include "DialogPageBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteTestValues.h"

DialogPageBase::DialogPageBase(e3::Element* pParent)
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
        pCustomView2->SetAlignItemsHor((e3::EAlignment)0);
                MDAppBarTitle* pCustomView3 = new MDAppBarTitle();
        pCustomView2->AddElement(pCustomView3);
        pCustomView3->SetText("Dialog");
    e3::Element* pElement2 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pCustomView1->AddElement(pElement2);
        pElement2->SetWidth("100%");
        pElement2->SetHeight("100%");
        pElement2->SetOrientation((e3::EOrientation)1);
        pElement2->SetScaling((e3::EScaling)1);
        mDialogButton = new MDButton();
        pElement2->AddElement(mDialogButton);
        mDialogButton->SetLabel(_s(SHOW DIALOG));
        mDialog = new MDDialog();
        pCustomView1->AddElement(mDialog);
        mDialog->SetWidth(e3::Dim("840", "840", "840", "280", "280", "280"));
        mDialog->SetHeight(e3::Dim("450", "450", "450", "150", "150", "150"));
    e3::Element* pElement3 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mDialog->AddElement(pElement3);
        pElement3->SetHeight("100%");
        pElement3->SetWidth("100%");
        pElement3->SetScaling((e3::EScaling)1);
    e3::Element* pElement4 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mDialog->AddElement(pElement4);
        pElement4->SetWidth("100%");
        pElement4->SetAlignItemsHor((e3::EAlignment)1);
                MDTextButton* pCustomView4 = new MDTextButton();
        pElement4->AddElement(pCustomView4);
        pCustomView4->SetLabel(_s(CANCEL));
                MDTextButton* pCustomView5 = new MDTextButton();
        pElement4->AddElement(pCustomView5);
        pCustomView5->SetLabel(_s(DISCARD));

}
