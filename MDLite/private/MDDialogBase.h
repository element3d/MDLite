
#ifndef __MDDialogBase_H__
#define __MDDialogBase_H__

#include <e3/ViewFactory.h>
#include <MDElement.h>


class MDDialogBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDDialogBase(e3::Element* pParent = nullptr);

 
protected:
	MDElement* mBody = nullptr;


};

#endif // __MDDialogBase_H__

