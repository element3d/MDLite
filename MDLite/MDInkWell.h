
#ifndef MDInkWell_H_
#define MDInkWell_H_

#include "private/MDInkWellBase.h"
#include "MDTheme.h"
#include "MDPushTransitionAnimation.h"
#include "MDPopTransitionAnimation.h"

class E3_EXPORT MDInkWell : public MDInkWellBase
{
public:
	MDInkWell(e3::Element* pParent = nullptr);
	~MDInkWell();

	//void SetBackgroundColor(const glm::vec4& color);

	virtual bool OnMouseDown(e3::MouseEvent* pEvent) override;
	virtual bool OnMouseUp(e3::MouseEvent* pEvent) override;
	virtual void OnMouseHover(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

private:
	void _DismissRipple();

private:
	e3::Animation* mRippleAnimation = nullptr;
	e3::Animation* mRippleDismissAnimation = nullptr;
	
};

#endif // MDInkWell_H_

