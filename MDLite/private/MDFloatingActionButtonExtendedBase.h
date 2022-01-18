
#ifndef __MDFloatingActionButtonExtendedBase_H__
#define __MDFloatingActionButtonExtendedBase_H__

#include <e3/ViewFactory.h>
#include "MDInkWell.h"


class MDFloatingActionButtonExtendedBase : public MDInkWell
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDFloatingActionButtonExtendedBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mIconCont = nullptr;
e3::Element* mLabelCont = nullptr;
e3::Element* mHover = nullptr;


};

#endif // __MDFloatingActionButtonExtendedBase_H__

