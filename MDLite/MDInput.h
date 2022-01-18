
#ifndef MDInput_H_
#define MDInput_H_

#include "private/MDInputBase.h"
#include "MDColors.h"

class E3_EXPORT MDInput : public MDInputBase
{
public:
	MDInput(e3::Element* pParent = nullptr);

	void SetText(const std::string& text, bool translate = false);
	void SetLabelText(const std::string& labelText, bool translate = false);
	void SetHintText(const std::string& hintText, bool translate = false);
	void SetPrefixText(const std::string& prefixText, bool translate = false);
	void Focus();
	void Unfocus();

	virtual bool OnMouseDown(e3::MouseEvent* pEvent) override;
	virtual bool OnMouseUp(e3::MouseEvent* pEvent) override;

	virtual void OnMouseEnter(e3::MouseEvent* pEvent) override;
	virtual void OnMouseLeave(e3::MouseEvent* pEvent) override;

	virtual void Render() override;
};

#endif // MDInput_H_

