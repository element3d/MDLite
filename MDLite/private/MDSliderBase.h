
#ifndef __MDSliderBase_H__
#define __MDSliderBase_H__

#include <e3/ViewFactory.h>


class MDSliderBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDSliderBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mBackground = nullptr;
e3::Element* mValue = nullptr;
e3::Element* mDivisions = nullptr;
e3::Element* mHoverCircle = nullptr;
e3::Element* mInfo = nullptr;
e3::Element* mInfoShape = nullptr;
e3::Text* mInfoText = nullptr;
e3::Element* mInfoTriangle = nullptr;
e3::Element* mCircle = nullptr;


};

#endif // __MDSliderBase_H__

