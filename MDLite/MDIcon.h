
#ifndef MDIcon_H_
#define MDIcon_H_

#include "private/MDIconBase.h"
#include "MDTheme.h"

class E3_EXPORT MDIcon : public MDIconBase
{
public:
	MDIcon(e3::Element* pParent = nullptr);
	MDIcon(const std::string& name, int size, const glm::vec4& color);

	void SetColor(MDColor* pColor);
	void SetColor(const glm::vec4& color);

public:
	void SetName(const std::string& name);
	std::string GetName();

	virtual void Render() override;
private:
	static void _InitIconMap();

private:
	static std::map<std::string, std::string> sIconMap;
	static std::map<std::string, std::string> sIconMapOutlined;
	MDColor* mColor = nullptr;
	std::string mName;
};

#endif // MDIcon_H_

