
#ifndef __MDIconButtonBase_H__
#define __MDIconButtonBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>


class MDIconButtonBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDIconButtonBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mBackground = nullptr;
e3::Element* mRipple = nullptr;
MDIcon* mIcon = nullptr;


};

#endif // __MDIconButtonBase_H__

