#include "MDSnackbarBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDSnackbarBase::MDSnackbarBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth("98%");
        this->SetHeight(e3::Dim("50", "50", "140", "50", "50", "50"));
        this->SetBackgroundColor(glm::vec4(0.000000, 0.000000, 0.000000, 255.000000));
        this->SetBorderRadius(glm::vec4(5.000000, 5.000000, 5.000000, 5.000000));
        this->SetPositionType((e3::EPositionType)1);
        this->SetOverflow((e3::EOverflow)0);
        this->SetBottom(20);

}
