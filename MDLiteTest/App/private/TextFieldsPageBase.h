
#ifndef __TextFieldsPageBase_H__
#define __TextFieldsPageBase_H__

#include <e3/ViewFactory.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDInput.h>


class TextFieldsPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    TextFieldsPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDIconButton* mBack = nullptr;


};

#endif // __TextFieldsPageBase_H__

