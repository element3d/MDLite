#include "MDAppBarTitleBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDAppBarTitleBase::MDAppBarTitleBase(e3::Element* pParent)
	: MDText(pParent)
{
        this->SetFontSize(e3::Dim("54", "54", "54", "18", "18", "18"));
        this->SetFontStyle((e3::EFontStyle)2);
        this->SetMarginLeft(e3::Dim("60", "60", "60", "20", "20", "20"));

}
