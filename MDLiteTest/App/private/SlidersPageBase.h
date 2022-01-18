
#ifndef __SlidersPageBase_H__
#define __SlidersPageBase_H__

#include <e3/ViewFactory.h>
#include <MDIconButton.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDInput.h>
#include <MDSlider.h>


class SlidersPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    SlidersPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDIconButton* mBack = nullptr;
MDInput* mInput = nullptr;
MDSlider* mSlider = nullptr;
MDSlider* mDivSlider = nullptr;


};

#endif // __SlidersPageBase_H__

