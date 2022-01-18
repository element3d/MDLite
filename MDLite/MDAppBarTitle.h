
#ifndef MDAppBarTitle_H_
#define MDAppBarTitle_H_

#include "private/MDAppBarTitleBase.h"
#include "MDTheme.h"

class E3_EXPORT MDAppBarTitle : public MDAppBarTitleBase
{
public:
	MDAppBarTitle(e3::Element* pParent = nullptr);
	
	virtual void Render() override;
};

#endif // MDAppBarTitle_H_

