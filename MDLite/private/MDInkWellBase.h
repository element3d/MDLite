
#ifndef __MDInkWellBase_H__
#define __MDInkWellBase_H__

#include <e3/ViewFactory.h>
#include "MDElement.h"


class MDInkWellBase : public MDElement
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDInkWellBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mRipple = nullptr;


};

#endif // __MDInkWellBase_H__

