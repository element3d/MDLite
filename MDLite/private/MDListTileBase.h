
#ifndef __MDListTileBase_H__
#define __MDListTileBase_H__

#include <e3/ViewFactory.h>


class MDListTileBase : public e3::Element
{
public:
    struct __Id
    {
        
    };

    struct Id
    {
        
    };

    MDListTileBase(e3::Element* pParent = nullptr);

 
protected:
	e3::Element* mLeading = nullptr;
e3::Element* mTitleBody = nullptr;
e3::Element* mTrailing = nullptr;


};

#endif // __MDListTileBase_H__

