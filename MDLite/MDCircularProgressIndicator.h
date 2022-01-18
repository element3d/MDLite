
#ifndef MDCircularProgressIndicator_H_
#define MDCircularProgressIndicator_H_

#include "private/MDCircularProgressIndicatorBase.h"
#include "MDTheme.h"

class E3_EXPORT MDCircularProgressIndicator : public MDCircularProgressIndicatorBase
{
public:
	MDCircularProgressIndicator(e3::Element* pParent = nullptr);
	~MDCircularProgressIndicator();

	void SetValue(float value);
	float GetValue();

	virtual void Render() override;
private:
	void AnimateRotation(float sec);
	void AnimateStartAngle(float sec);
	void AnimateEndAngle(float sec);
private:
	e3::Animation* mRotationAnimation = nullptr;
	e3::Animation* mStartAngleAnimation = nullptr;
	e3::Animation* mEndAngleAnimation = nullptr;
	bool mDestroyed = false;
};

#endif // MDCircularProgressIndicator_H_

