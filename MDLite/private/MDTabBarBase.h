
#ifndef __MDTabBarBase_H__
#define __MDTabBarBase_H__

#include <e3/ViewFactory.h>


class MDTabBarBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDTabBarBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mContent = nullptr;
e3::Element* mSelection = nullptr;


};

#endif // __MDTabBarBase_H__

