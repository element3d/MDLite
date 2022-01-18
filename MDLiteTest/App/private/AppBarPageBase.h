
#ifndef __AppBarPageBase_H__
#define __AppBarPageBase_H__

#include <e3/ViewFactory.h>
#include <MDMenuBody.h>
#include <MDMenuItem.h>
#include <MDListTile.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarAction.h>
#include <MDAppBarTitle.h>
#include <MDMenu.h>
#include "MDElement.h"


class AppBarPageBase : public MDElement
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    AppBarPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDMenuBody* mMenuBody = nullptr;
MDIconButton* mBack = nullptr;


};

#endif // __AppBarPageBase_H__

