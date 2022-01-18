
#ifndef __MDCheckboxBase_H__
#define __MDCheckboxBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>


class MDCheckboxBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDCheckboxBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mRipple = nullptr;
MDIcon* mIcon = nullptr;


};

#endif // __MDCheckboxBase_H__

