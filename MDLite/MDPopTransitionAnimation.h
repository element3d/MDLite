#ifndef __MD_POP_TRANSITION_ANIMATION__
#define __MD_POP_TRANSITION_ANIMATION__

class MDPopTransitionAnimation : public e3::Animation
{
public:
	MDPopTransitionAnimation(e3::Element* pElement) : e3::Animation()
	{
		SetDuration(0.2);
		AddOnValueCallback([pElement](float v) {
			pElement->SetTranslation(glm::vec3(0, (v) * pElement->GetGeometry().height, 0));
			pElement->SetOpacity(1 - v);
		});
		AddOnEndCallback([]() {

		});
	}
};

#endif // !__MD_POP_TRANSITION_ANIMATION__
