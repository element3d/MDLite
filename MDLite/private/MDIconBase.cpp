#include "MDIconBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDIconBase::MDIconBase(e3::Element* pParent)
	: e3::FontIcon(pParent)
{
        this->SetWidth(e3::Dim("20", "20", "50", "20", "20", "20"));
        this->SetHeight(e3::Dim("20", "20", "50", "20", "20", "20"));
        this->SetMargin(e3::Dim("16", "16", "50", "16", "16", "16"));

}
