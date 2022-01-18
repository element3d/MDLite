
#ifndef __MDFloatingActionButtonBase_H__
#define __MDFloatingActionButtonBase_H__

#include <e3/ViewFactory.h>
#include "MDInkWell.h"


class MDFloatingActionButtonBase : public MDInkWell
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDFloatingActionButtonBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mHover = nullptr;


};

#endif // __MDFloatingActionButtonBase_H__

