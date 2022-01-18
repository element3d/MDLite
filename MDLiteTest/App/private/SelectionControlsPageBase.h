
#ifndef __SelectionControlsPageBase_H__
#define __SelectionControlsPageBase_H__

#include <e3/ViewFactory.h>
#include <MDRadioGroup.h>
#include <MDIconButton.h>
#include <MDAppBar.h>
#include <MDAppBarTitle.h>
#include <MDCheckbox.h>
#include <MDRadio.h>
#include <MDSwitch.h>


class SelectionControlsPageBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    SelectionControlsPageBase(e3::Element* pParent = nullptr);

 
protected:
	MDRadioGroup* mRadioGroup = nullptr;
MDIconButton* mBack = nullptr;
e3::Element* mCheckTest1 = nullptr;
e3::Element* mCheckTest2 = nullptr;
e3::Element* mCheckTest3 = nullptr;
MDCheckbox* mCheckbox1 = nullptr;
MDCheckbox* mCheckbox2 = nullptr;
MDCheckbox* mCheckbox3 = nullptr;
e3::Element* mRadioTest1 = nullptr;
e3::Element* mRadioTest2 = nullptr;
e3::Element* mRadioTest3 = nullptr;
MDRadio* mRadio1 = nullptr;
MDRadio* mRadio2 = nullptr;
MDRadio* mRadio3 = nullptr;
e3::Element* mSwitchTest1 = nullptr;
MDSwitch* mSwitch = nullptr;


};

#endif // __SelectionControlsPageBase_H__

