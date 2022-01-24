#include "MDTextBase.h"

#include <e3/ViewFactory.h>
#include "MDLiteValues.h"

MDTextBase::MDTextBase(e3::Element* pParent)
	: e3::Text(pParent)
{
        this->SetFont(GoogleFonts::Roboto());

}
