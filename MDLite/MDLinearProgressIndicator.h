
#ifndef MDLinearProgressIndicator_H_
#define MDLinearProgressIndicator_H_

#include "private/MDLinearProgressIndicatorBase.h"
#include "MDTheme.h"

class E3_EXPORT MDLinearProgressIndicator : public MDLinearProgressIndicatorBase
{
public:
	MDLinearProgressIndicator(e3::Element* pParent = nullptr);
	~MDLinearProgressIndicator();

	void SetValue(float value);
	float GetValue();

	virtual void Render() override;

private:
	void Animate(float sec);

private:
	e3::Animation* mAnimation = nullptr;
	bool mDestroyed = false;
};

#endif // MDLinearProgressIndicator_H_

