
#ifndef __BottomSheetPageBase_H__
#define __BottomSheetPageBase_H__

#include <e3/ViewFactory.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDButton.h>
#include <MDBottomSheet.h>
#include <MDDivider.h>
#include <MDListView.h>


class BottomSheetPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    BottomSheetPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDIconButton* mBack = nullptr;
MDButton* mShowButton = nullptr;
MDBottomSheet* mBottomSheet = nullptr;
MDListView* mList = nullptr;


};

#endif // __BottomSheetPageBase_H__

