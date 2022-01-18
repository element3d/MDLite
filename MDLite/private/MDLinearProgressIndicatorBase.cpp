#include "MDLinearProgressIndicatorBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDLinearProgressIndicatorBase::MDLinearProgressIndicatorBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetHeight(e3::Dim("12", "12", "12", "4", "4", "4"));
        this->SetBackgroundColor(MDColors::Primary::Get("100"));
        this->SetOverflow((e3::EOverflow)0);
    mBack = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mBack);
        mBack->SetWidth("100%");
        mBack->SetHeight("100%");
    mValueElement = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mValueElement);
        mValueElement->SetWidth("100%");
        mValueElement->SetHeight("100%");
        mValueElement->SetPositionType((e3::EPositionType)1);
        mValueElement->SetBackgroundColor(MDColors::Primary::Get());
        mValueElement->SetLeft(0);

}
