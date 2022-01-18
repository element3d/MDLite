#ifndef __MD_PUSH_TRANSITION_ANIMATION__
#define __MD_PUSH_TRANSITION_ANIMATION__

class MDPushTransitionAnimation : public e3::Animation
{
public:
	MDPushTransitionAnimation(e3::Element* pElement) : e3::Animation()
	{
		Start(0.2, [this, pElement](float v) {
			pElement->SetTranslation(glm::vec3(0, (1 - v) * pElement->GetGeometry().height, 0));
			pElement->SetOpacity(v);
		}, []() {

		});
	}
};

#endif // !__MD_PUSH_TRANSITION_ANIMATION__
