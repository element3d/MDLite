#include "MDCircularProgressIndicatorBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDCircularProgressIndicatorBase::MDCircularProgressIndicatorBase(e3::Element* pParent)
	: e3::Element(pParent)
{
        this->SetWidth(e3::Dim("144", "144", "144", "48", "48", "48"));
        this->SetAspectRatio(1.000000);
       // this->SetInnerRadius(e3::Dim("60", "60", "60", "20", "20", "20"));
        this->SetBackgroundColor(MDColors::Primary::Get());

}
