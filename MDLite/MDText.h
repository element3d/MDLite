
#ifndef MDText_H_
#define MDText_H_

#include "private/MDTextBase.h"
#include "MDTheme.h"

class E3_EXPORT MDText : public MDTextBase
{
public:
	MDText(e3::Element* pParent = nullptr);

	void SetTextColor(MDColor* pColor);
	void SetTextColor(const glm::vec4& color);

public:
	virtual void Render() override;

private:
	MDColor* mTextColor = nullptr;
};

#endif // MDText_H_

