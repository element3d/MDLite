#ifndef __MDCOLOR__
#define __MDCOLOR__

#include <e3.h>
#include <glm/glm.hpp>

class E3_EXPORT MDColor : public glm::vec4
{
public:
	MDColor();
	MDColor(float v);
	MDColor(float _r, float _g, float _b, float _a);

	MDColor(const glm::vec4 &color) //: glm::vec4(color)
	{
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}
};

#endif // __MDCOLOR__