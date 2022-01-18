#ifndef __MDRADIO_GROUP__
#define __MDRADIO_GROUP__

#include <e3.h>
#include <vector>
#include "MDCheckable.h"

class E3_EXPORT MDRadioGroup 
{
public:
	MDRadioGroup();

	void AddItem(MDCheckable* pItem);

private:
	std::vector<MDCheckable*> mItems;
};

#endif // !__MDRADIO_GROUP__
