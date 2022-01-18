
#ifndef __MDInputBase_H__
#define __MDInputBase_H__

#include <e3/ViewFactory.h>
#include <MDElement.h>
#include <MDDivider.h>


class MDInputBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDInputBase(e3::Element* pParent = nullptr);

 
protected:
	MDElement* mContainer = nullptr;
e3::Text* mLabelText = nullptr;
e3::Text* mPrefixText = nullptr;
e3::Input* mInput = nullptr;
e3::Text* mHintText = nullptr;
MDDivider* mUnderline = nullptr;


};

#endif // __MDInputBase_H__

