
#ifndef __ProgressIndicatorPageBase_H__
#define __ProgressIndicatorPageBase_H__

#include <e3/ViewFactory.h>
#include <MDIconButton.h>
#include <MDScaffold.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDLinearProgressIndicator.h>
#include <MDCircularProgressIndicator.h>


class ProgressIndicatorPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    ProgressIndicatorPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDIconButton* mBack = nullptr;
MDLinearProgressIndicator* mLinearIndicator = nullptr;
MDCircularProgressIndicator* mCircularIndicator = nullptr;


};

#endif // __ProgressIndicatorPageBase_H__

