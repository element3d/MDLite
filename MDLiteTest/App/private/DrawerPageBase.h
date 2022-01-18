
#ifndef __DrawerPageBase_H__
#define __DrawerPageBase_H__

#include <e3/ViewFactory.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarAction.h>
#include <MDAppBarTitle.h>
#include <MDDrawer.h>
#include <MDListTile.h>
#include "MDElement.h"


class DrawerPageBase : public MDElement
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    DrawerPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDIconButton* mBack = nullptr;
MDAppBarAction* mDrawerButton = nullptr;
MDDrawer* mDrawer = nullptr;
MDListTile* mItem1 = nullptr;
MDListTile* mItem2 = nullptr;


};

#endif // __DrawerPageBase_H__

