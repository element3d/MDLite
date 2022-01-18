
#ifndef MDIconButton_H_
#define MDIconButton_H_

#include "private/MDIconButtonBase.h"
#include "MDTheme.h"

class E3_EXPORT MDIconButton : public MDIconButtonBase
{
public:
	MDIconButton(e3::Element* pParent = nullptr);
	~MDIconButton();

	void SetName(const std::string& name);
	void SetColor(const glm::vec4& color);
	void SetColor(MDColor* pColor);

	virtual void OnMouseHover(e3::MouseEvent* pEvent) override;
	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;
	virtual void Render() override;
	virtual bool OnClick(e3::MouseEvent* pEvent) override;

private:
	void _DismissRipple();

private:
	bool mDestroyed = false;
	MDColor* mIconColor = nullptr;
	e3::Animation* mRippleAnimation = nullptr;
};

#endif // MDIconButton_H_

