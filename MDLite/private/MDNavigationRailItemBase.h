
#ifndef __MDNavigationRailItemBase_H__
#define __MDNavigationRailItemBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>
#include <MDText.h>


class MDNavigationRailItemBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDNavigationRailItemBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mBackground = nullptr;
e3::Element* mRipple = nullptr;
e3::Element* mContainer = nullptr;
MDIcon* mIcon = nullptr;
MDText* mTitle = nullptr;


};

#endif // __MDNavigationRailItemBase_H__

