
#ifndef MDElement_H_
#define MDElement_H_

#include "private/MDElementBase.h"
#include "MDTheme.h"

class E3_EXPORT MDElement : public MDElementBase
{
public:
	MDElement(e3::Element* pParent = nullptr);

	void SetBackgroundColor(MDColor* pColor);
	void SetBorderColor(MDColor* pColor);

	void SetBackgroundColor(const glm::vec4& color);
	void SetBorderColor(const glm::vec4& color);

	virtual void Render() override;
private:
	MDColor* mBackgroundColor = nullptr;
	MDColor* mBorderColor = nullptr;
};

#endif // MDElement_H_

