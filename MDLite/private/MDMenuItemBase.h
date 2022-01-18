
#ifndef __MDMenuItemBase_H__
#define __MDMenuItemBase_H__

#include <e3/ViewFactory.h>
#include "MDInkWell.h"


class MDMenuItemBase : public MDInkWell
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDMenuItemBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mHover = nullptr;


};

#endif // __MDMenuItemBase_H__

