
#ifndef __MDButtonBase_H__
#define __MDButtonBase_H__

#include <e3/ViewFactory.h>
#include "MDColors.h"
#include <MDText.h>
#include "MDInkWell.h"


class MDButtonBase : public MDInkWell
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDButtonBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mIconCont = nullptr;
MDText* mLabel = nullptr;
e3::Element* mHover = nullptr;


};

#endif // __MDButtonBase_H__

