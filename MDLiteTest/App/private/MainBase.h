
#ifndef __MainBase_H__
#define __MainBase_H__

#include <e3/ViewFactory.h>
#include "MDColors.h"
#include "MDIcon.h"
#include <MDSwitch.h>
#include <MDText.h>
#include <MDCol.h>
#include <MDRow.h>
#include <MainMenuItem.h>
#include "MDElement.h"


class MainBase : public MDElement
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MainBase(e3::Element* pParent = nullptr);

 
protected:
	MDSwitch* mDarkModeSwitch = nullptr;
MainMenuItem* mAppBarPage = nullptr;
MainMenuItem* mButtonPage = nullptr;
MainMenuItem* mBottomNavBarPage = nullptr;
MainMenuItem* mDrawerPage = nullptr;
MainMenuItem* mBottomSheetPage = nullptr;
MainMenuItem* mNavRailPage = nullptr;
MainMenuItem* mDialogPage = nullptr;
MainMenuItem* mMenuPage = nullptr;
MainMenuItem* mProgressIndicatorsPage = nullptr;
MainMenuItem* mSelectionControlsPage = nullptr;
MainMenuItem* mSlidersPage = nullptr;
MainMenuItem* mTabsPage = nullptr;
MainMenuItem* mTextFieldsPage = nullptr;
MainMenuItem* mListPage = nullptr;
MainMenuItem* mSnackbarPage = nullptr;


};

#endif // __MainBase_H__

