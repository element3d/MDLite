
#ifndef __NavigationRailPageBase_H__
#define __NavigationRailPageBase_H__

#include <e3/ViewFactory.h>
#include <MDMenuBody.h>
#include <MDMenuItem.h>
#include <MDListTile.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDNavigationRail.h>
#include <MDNavigationRailItem.h>
#include <MDDivider.h>


class NavigationRailPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    NavigationRailPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDMenuBody* mMenuBody = nullptr;
MDIconButton* mBack = nullptr;


};

#endif // __NavigationRailPageBase_H__

