#include "MDTabBarBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDTabBarBase::MDTabBarBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetOrientation((e3::EOrientation)0);
        this->SetOverflow((e3::EOverflow)0);
        e3::ShadowParams ShadowParams;
        ShadowParams.Color = glm::vec4(100.000000, 100.000000, 100.000000, 255.000000);
        ShadowParams.BlurSize = 20;
        ShadowParams.Opacity = 1;
        ShadowParams.Scale = 1.0;
        ShadowParams.Offset = glm::ivec2(0, 10);
        SetShadow(ShadowParams);
    e3::Element* pElement1 = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(pElement1);
        pElement1->SetOrientation((e3::EOrientation)1);
        pElement1->SetAlignItemsHor((e3::EAlignment)0);
        pElement1->SetWidth("100%");
    mContent = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement1->AddElement(mContent);
        mContent->SetOverflow((e3::EOverflow)2);
        mContent->SetOrientation((e3::EOrientation)0);
        mContent->SetWidth("100%");
        mContent->SetScaling((e3::EScaling)1);
    mSelection = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    pElement1->AddElement(mSelection);
        mSelection->SetPositionType((e3::EPositionType)1);
        mSelection->SetLeft(0);
        mSelection->SetBottom(0);
        mSelection->SetBackgroundColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mSelection->SetWidth("100%");
        mSelection->SetHeight(e3::Dim("2", "2", "4", "2", "2", "2"));
        mSelection->SetScaling((e3::EScaling)2);

}
