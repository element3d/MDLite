
#ifndef __MDSwitchBase_H__
#define __MDSwitchBase_H__

#include <e3/ViewFactory.h>


class MDSwitchBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDSwitchBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mBack = nullptr;
e3::Element* mCircle = nullptr;
e3::Element* mRipple = nullptr;


};

#endif // __MDSwitchBase_H__

