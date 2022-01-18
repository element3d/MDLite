#include "MDCheckboxBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDCheckboxBase::MDCheckboxBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(e3::Dim("25", "30", "48", "24", "24", "24"));
        this->SetAspectRatio(1.000000);
        this->SetBorderSize(2);
        this->SetBorderRadius(glm::vec4(0.000000, 0.000000, 0.000000, 0.000000));
        this->SetMargin(8);
    mRipple = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mRipple);
        mRipple->SetPositionType((e3::EPositionType)1);
        mRipple->SetAspectRatio(1.000000);
        mRipple->SetHeight(40);
        mRipple->SetShapeType((e3::EShapeType)1);
        mIcon = new MDIcon();
        AddElement(mIcon);
        mIcon->SetName(_s(done));
        mIcon->SetColor(MDTheme::Get()->OnPrimary);
        mIcon->SetWidth(e3::Dim("18", "18", "30", "18", "18", "18"));
        mIcon->SetAspectRatio(1.000000);

}
