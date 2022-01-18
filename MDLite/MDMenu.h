
#ifndef MDMenu_H_
#define MDMenu_H_

#include "private/MDMenuBase.h"

class E3_EXPORT MDMenu : public MDMenuBase
{
public:
	MDMenu(e3::Element* pParent = nullptr);

	virtual void Expand() override;
};

#endif // MDMenu_H_

