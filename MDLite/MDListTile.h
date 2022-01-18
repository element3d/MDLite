
#ifndef MDListTile_H_
#define MDListTile_H_

#include "private/MDListTileBase.h"
#include "MDPopTransitionAnimation.h"
#include "MDPushTransitionAnimation.h"
class E3_EXPORT MDListTile : public MDListTileBase
{
public:
	MDListTile(e3::Element* pParent = nullptr);

	void SetLeading(e3::Element* pElement);
	void SetTitle(const std::string& title, bool translate = false);
	void SetSubtitle(const std::string& subtitle, bool translate = false);
	void SetTrailing(e3::Element* pElement);
};

#endif // MDListTile_H_

