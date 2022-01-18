
#ifndef Main_H_
#define Main_H_

#include "private/MainBase.h"

class E3_EXPORT Main : public MainBase
{
public:
	Main(e3::Element* pParent = nullptr);

	MDTheme* mDarkTheme = nullptr;
};

#endif // Main_H_

