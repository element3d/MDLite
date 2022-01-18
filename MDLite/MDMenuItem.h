
#ifndef MDMenuItem_H_
#define MDMenuItem_H_

#include "private/MDMenuItemBase.h"

class E3_EXPORT MDMenuItem : public MDMenuItemBase
{
public:
	MDMenuItem(e3::Element* pParent = nullptr);

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;
};

#endif // MDMenuItem_H_

