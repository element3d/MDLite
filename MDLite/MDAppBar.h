
#ifndef MDAppBar_H_
#define MDAppBar_H_

#include "private/MDAppBarBase.h"
#include "MDTheme.h"

class E3_EXPORT MDAppBar : public MDAppBarBase
{
public:
	MDAppBar(e3::Element* pParent = nullptr);

	virtual void Render() override;
};

#endif // MDAppBar_H_

