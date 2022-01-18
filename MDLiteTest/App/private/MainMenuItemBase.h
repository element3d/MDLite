
#ifndef __MainMenuItemBase_H__
#define __MainMenuItemBase_H__

#include <e3/ViewFactory.h>
#include <MDIcon.h>
#include <MDText.h>
#include "MDInkWell.h"


class MainMenuItemBase : public MDInkWell
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MainMenuItemBase(e3::Element* pParent = nullptr);

 
protected:
	MDIcon* mIcon = nullptr;
MDText* mTitle = nullptr;


};

#endif // __MainMenuItemBase_H__

