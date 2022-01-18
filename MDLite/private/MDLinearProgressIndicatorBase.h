
#ifndef __MDLinearProgressIndicatorBase_H__
#define __MDLinearProgressIndicatorBase_H__

#include <e3/ViewFactory.h>
#include "MDColors.h"


class MDLinearProgressIndicatorBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDLinearProgressIndicatorBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mBack = nullptr;
e3::Element* mValueElement = nullptr;


};

#endif // __MDLinearProgressIndicatorBase_H__

