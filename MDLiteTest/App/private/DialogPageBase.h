
#ifndef __DialogPageBase_H__
#define __DialogPageBase_H__

#include <e3/ViewFactory.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDButton.h>
#include <MDDialog.h>
#include <MDTextButton.h>


class DialogPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    DialogPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDIconButton* mBack = nullptr;
MDButton* mDialogButton = nullptr;
MDDialog* mDialog = nullptr;


};

#endif // __DialogPageBase_H__

