#include "MDColor.h"

MDColor::MDColor()
{
	r = g = b = a = 0;
}

/*MDColor::MDColor(const glm::vec4& color) : glm::vec4(color)
{
	//*this = color;
}*/

MDColor::MDColor(float v)
{
	r = g = b = a = v;
}

MDColor::MDColor(float _r, float _g, float _b, float _a)
{
	r = _r;
	g = _g;
	b = _b;
	a = _a;
}