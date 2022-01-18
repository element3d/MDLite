
#ifndef __MenuPageBase_H__
#define __MenuPageBase_H__

#include <e3/ViewFactory.h>
#include <MDMenuBody.h>
#include <MDMenuItem.h>
#include <MDListTile.h>
#include <MDMenu.h>
#include <MDIconButton.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDInkWell.h>


class MenuPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MenuPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDMenuBody* mContextMenuBody = nullptr;
MDMenuBody* mMenuBody1 = nullptr;
MDMenu* mContextMenu = nullptr;
MDIconButton* mBack = nullptr;


};

#endif // __MenuPageBase_H__

