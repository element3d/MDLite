#include "MDNavigationRailItemBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDNavigationRailItemBase::MDNavigationRailItemBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(72);
        this->SetHeight(72);
        this->SetScaling((e3::EScaling)1);
        this->SetShapeType((e3::EShapeType)1);
        this->SetOrientation((e3::EOrientation)1);
    mBackground = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mBackground);
        mBackground->SetPositionType((e3::EPositionType)1);
        mBackground->SetWidth(e3::Dim("20", "20", "210", "70", "70", "70"));
        mBackground->SetAspectRatio(1.000000);
        mBackground->SetShapeType((e3::EShapeType)1);
        mBackground->SetOverflow((e3::EOverflow)0);
    mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mBackground->AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetWidth("100%");
        mRipple->SetAspectRatio(1.000000);
        mRipple->SetShapeType((e3::EShapeType)1);
    mContainer = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mContainer);
        mContainer->SetOrientation((e3::EOrientation)1);
        mIcon = new MDIcon();
        mContainer->AddElement(mIcon);
        mIcon->SetAspectRatio(1.000000);
        mIcon->SetHeight(e3::Dim("72", "72", "72", "24", "24", "24"));
        mIcon->SetMargin(0);
        mTitle = new MDText();
        mContainer->AddElement(mTitle);
        mTitle->SetFontSize(e3::Dim("14", "14", "36", "12", "12", "12"));
        mTitle->SetFontStyle((e3::EFontStyle)2);

}
