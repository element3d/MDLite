
#ifndef MDScaffold_H_
#define MDScaffold_H_

#include "private/MDScaffoldBase.h"
#include "MDTheme.h"

class E3_EXPORT MDScaffold : public MDScaffoldBase
{
public:
	MDScaffold(e3::Element* pParent = nullptr);

	virtual void Render() override;
};

#endif // MDScaffold_H_

