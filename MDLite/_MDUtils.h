#ifndef __MDUTILS__
#define __MDUTILS__

#include <glm/glm.hpp>

class _MDUtils 
{
public:
	static glm::vec3 RGBtoHSL(const glm::vec3& color);
	static bool IsColorBright(const glm::vec4& color);
};

#endif // !__MDUTILS__
