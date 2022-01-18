#include "MDListTileBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDListTileBase::MDListTileBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth("100%");
        this->SetHeight(e3::Dim("50", "50", "150", "50", "50", "50"));
    mLeading = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mLeading);
        mLeading->SetMarginLeft(e3::Dim("(20", "20", "60", "(20", "20", "60"));
        mLeading->SetMarginRight(e3::Dim("(20", "20", "60", "(20", "20", "60"));
    mTitleBody = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mTitleBody);
        mTitleBody->SetWidth("100%");
        mTitleBody->SetHeight("100%");
        mTitleBody->SetScaling((e3::EScaling)1);
        mTitleBody->SetMarginLeft(e3::Dim("(20", "20", "60", "(20", "20", "60"));
        mTitleBody->SetAlignItemsHor((e3::EAlignment)0);
        mTitleBody->SetOrientation((e3::EOrientation)1);
    mTrailing = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mTrailing);

}
