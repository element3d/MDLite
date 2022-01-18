
#ifndef __SnackbarPageBase_H__
#define __SnackbarPageBase_H__

#include <e3/ViewFactory.h>
#include <MDMenuBody.h>
#include <MDMenuItem.h>
#include <MDListTile.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDButton.h>
#include <MDSnackbar.h>


class SnackbarPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    SnackbarPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDMenuBody* mMenuBody = nullptr;
MDIconButton* mBack = nullptr;
MDButton* mButton = nullptr;
MDSnackbar* mSnackbar = nullptr;


};

#endif // __SnackbarPageBase_H__

