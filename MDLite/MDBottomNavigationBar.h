
#ifndef MDBottomNavigationBar_H_
#define MDBottomNavigationBar_H_

#include "private/MDBottomNavigationBarBase.h"
#include "MDBottomNavigationBarItem.h"
#include "MDTheme.h"

class E3_EXPORT MDBottomNavigationBar : public MDBottomNavigationBarBase
{
public:
	MDBottomNavigationBar(e3::Element* pParent = nullptr);

	virtual void Render() override;
	virtual void AddElement(e3::Element* pItem) override;
};

#endif // MDBottomNavigationBar_H_

