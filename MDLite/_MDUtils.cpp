#include "_MDUtils.h"

glm::vec3 _MDUtils::RGBtoHSL(const glm::vec3& color)
{
	unsigned int r = (unsigned int)color.r;
	unsigned int g = (unsigned int)color.g;
	unsigned int b = (unsigned int)color.b;

	double r_percent = ((double)r) / 255;
	double g_percent = ((double)g) / 255;
	double b_percent = ((double)b) / 255;

	double max_color = 0;
	if ((r_percent >= g_percent) && (r_percent >= b_percent))
		max_color = r_percent;
	if ((g_percent >= r_percent) && (g_percent >= b_percent))
		max_color = g_percent;
	if ((b_percent >= r_percent) && (b_percent >= g_percent))
		max_color = b_percent;

	double min_color = 0;
	if ((r_percent <= g_percent) && (r_percent <= b_percent))
		min_color = r_percent;
	if ((g_percent <= r_percent) && (g_percent <= b_percent))
		min_color = g_percent;
	if ((b_percent <= r_percent) && (b_percent <= g_percent))
		min_color = b_percent;

	double L = 0;
	double S = 0;
	double H = 0;

	L = (max_color + min_color) / 2;

	if (max_color == min_color)
	{
		S = 0;
		H = 0;
	}
	else
	{
		if (L < .50)
		{
			S = (max_color - min_color) / (max_color + min_color);
		}
		else
		{
			S = (max_color - min_color) / (2 - max_color - min_color);
		}
		if (max_color == r_percent)
		{
			H = (g_percent - b_percent) / (max_color - min_color);
		}
		if (max_color == g_percent)
		{
			H = 2 + (b_percent - r_percent) / (max_color - min_color);
		}
		if (max_color == b_percent)
		{
			H = 4 + (r_percent - g_percent) / (max_color - min_color);
		}
	}
	glm::vec3 hsl;
	hsl.g = (unsigned int)(S * 100);
	hsl.b = (unsigned int)(L * 100) / 100.0f;
	H = H * 60;
	if (H < 0)
		H += 360;
	hsl.r = (unsigned int)H;
	return hsl;
}

bool _MDUtils::IsColorBright(const glm::vec4& color)
{
	glm::vec3 hsl = RGBtoHSL(glm::vec3(color));
	return hsl.b >= 0.5;
}