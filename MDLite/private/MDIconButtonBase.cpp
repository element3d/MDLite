#include "MDIconButtonBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDIconButtonBase::MDIconButtonBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(e3::Dim("20", "20", "156", "52", "52", "52"));
        this->SetHeight(e3::Dim("20", "20", "156", "52", "52", "52"));
    mBackground = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mBackground);
        mBackground->SetPositionType((e3::EPositionType)1);
        mBackground->SetWidth(e3::Dim("20", "20", "210", "70", "70", "70"));
        mBackground->SetAspectRatio(1.000000);
        mBackground->SetShapeType((e3::EShapeType)1);
        mBackground->SetOverflow((e3::EOverflow)0);
    mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mBackground->AddElement(mRipple);
        mRipple->SetWidth("100%");
        mRipple->SetAspectRatio(1.000000);
        mRipple->SetShapeType((e3::EShapeType)1);
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetMargin(0);

}
