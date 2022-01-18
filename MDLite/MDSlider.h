
#ifndef MDSlider_H_
#define MDSlider_H_

#include "private/MDSliderBase.h"
#include "MDTheme.h"

class E3_EXPORT MDSlider : public MDSliderBase
{
	typedef std::function<void(int value)> OnChangeCallback;

public:
	MDSlider(e3::Element* pParent = nullptr);
	~MDSlider();

	void SetDivisions(int divisiions);
	int GetDivisions();

	void SetOnChangeCallback(OnChangeCallback c);

	virtual void Render() override;

public:
	virtual void OnMouseMove(e3::MouseEvent*) override;

	virtual void OnMouseEnter(e3::MouseEvent*) override;
	virtual void OnMouseLeave(e3::MouseEvent*) override;

	virtual bool OnMouseDown(e3::MouseEvent*) override;
	virtual bool OnMouseUp(e3::MouseEvent*) override;

	virtual void SetTranslation(const glm::vec3 &pos) override;
	//virtual void SetParent(e3::Element* pParent) override;
private:
	void _ShowInfo();
	void _HideInfo();

private:
	// const MDTheme* mTheme = nullptr;
	e3::Animation* mHoverAnimation = nullptr;
	e3::Animation* mInfoAnimation = nullptr;
	float mSliderWidth = 0.0f;
	int mSliderValue = 0.0f;
	int mNumDivisions = 0;
	OnChangeCallback mOnChangeCallback;
};

#endif // MDSlider_H_

