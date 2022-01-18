
#ifndef __MDRadioBase_H__
#define __MDRadioBase_H__

#include <e3/ViewFactory.h>


class MDRadioBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDRadioBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mRipple = nullptr;
e3::Element* mCheck = nullptr;


};

#endif // __MDRadioBase_H__

