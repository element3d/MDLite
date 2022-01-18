#include "MDSliderBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDSliderBase::MDSliderBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(e3::Dim("300", "300", "600", "300", "300", "300"));
        this->SetHeight(e3::Dim("20", "30", "50", "20", "20", "20"));
    mBackground = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mBackground);
        mBackground->SetWidth("100%");
        mBackground->SetHeight(6);
        mBackground->SetBorderRadius(glm::vec4(0.500000, 0.500000, 0.500000, 0.500000));
        mBackground->SetBackgroundColor(glm::vec4(96, 2, 238, 255));
    mValue = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mValue);
        mValue->SetPositionType((e3::EPositionType)1);
        mValue->SetLeft(0);
        mValue->SetHeight("30%");
        mValue->SetBorderRadius(glm::vec4(0.500000, 0.500000, 0.500000, 0.500000));
    mDivisions = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mDivisions);
        mDivisions->SetPositionType((e3::EPositionType)1);
        mDivisions->SetAlignItemsHor((e3::EAlignment)3);
        mDivisions->SetLeft(0);
        mDivisions->SetWidth("100%");
        mDivisions->SetHeight(6);
    mHoverCircle = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mHoverCircle);
        mHoverCircle->SetPositionType((e3::EPositionType)1);
        mHoverCircle->SetLeft(0);
        mHoverCircle->SetOpacity(0.000000);
        mHoverCircle->SetAspectRatio(1.000000);
        mHoverCircle->SetHeight("100%");
        mHoverCircle->SetShapeType((e3::EShapeType)1);
    mInfo = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mInfo);
        mInfo->SetPositionType((e3::EPositionType)1);
        mInfo->SetLeft(0);
        mInfo->SetOrientation((e3::EOrientation)1);
        mInfo->SetVisibility((e3::EVisibility)1);
    mInfoShape = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mInfo->AddElement(mInfoShape);
        mInfoShape->SetBackgroundColor(glm::vec4(100.000000, 100.000000, 100.000000, 255.000000));
        mInfoShape->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        mInfoText = e3::ViewFactory::CreateText();
        mInfoShape->AddElement(mInfoText);
        mInfoText->SetFontSize(16);
        mInfoText->SetTextColor(glm::vec4(255.000000, 255.000000, 255.000000, 255.000000));
        mInfoText->SetMarginLeft(16);
        mInfoText->SetMarginRight(16);
        mInfoText->SetMarginTop(8);
        mInfoText->SetMarginBottom(8);
    mInfoTriangle = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    mInfo->AddElement(mInfoTriangle);
        mInfoTriangle->SetShapeType((e3::EShapeType)4);
        mInfoTriangle->SetWidth(16);
        mInfoTriangle->SetHeight(8);
        mInfoTriangle->SetBackgroundColor(glm::vec4(100.000000, 100.000000, 100.000000, 255.000000));
    mCircle = e3::ViewFactory::CreateShape( e3::EOrientation::Horizontal);
    AddElement(mCircle);
        mCircle->SetPositionType((e3::EPositionType)1);
        mCircle->SetLeft(0);
        mCircle->SetAspectRatio(1.000000);
        mCircle->SetOpacity(1.000000);
        mCircle->SetHeight("100%");
        mCircle->SetShapeType((e3::EShapeType)1);
        mCircle->SetBackgroundColor(glm::vec4(96, 2, 238, 255));

}
