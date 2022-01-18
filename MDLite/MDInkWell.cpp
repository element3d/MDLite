#include "MDInkWell.h"
#include <e3/Application.h>

glm::vec3 RGBtoHSL(const glm::vec3& color)
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


MDInkWell::MDInkWell(e3::Element* pParent)
	: MDInkWellBase(pParent)
{

}

MDInkWell::~MDInkWell()
{
	if (mRippleAnimation) mRippleAnimation->Stop();
	if (mRippleDismissAnimation) mRippleDismissAnimation->Stop();
}

/*void MDInkWell::SetBackgroundColor(const glm::vec4& color)
{
	e3::Element::SetBackgroundColor(color);
}*/

bool MDInkWell::OnMouseUp(e3::MouseEvent* pEvent) 
{
	bool b = MDInkWellBase::OnMouseUp(pEvent);
	if (mRippleAnimation) mRippleAnimation->Stop();

	glm::vec3 scale = mRipple->GetScale();

	mRippleAnimation = new e3::Animation();
	mRippleAnimation->Start(0.1, scale.x, 1.0, [this](float v) {
		e3::Rect2f geo = GetGeometry();
	
		mRipple->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		e3::Rect2f rippleGeo = mRipple->GetGeometry();
	}, [this, pEvent]() {
		mRippleAnimation = nullptr;
		 _DismissRipple();
		//mRipple->SetBackgroundColor(glm::vec4(0));
		//mRipple->SetHeight(0);
	});

	return b;
}

bool MDInkWell::OnMouseDown(e3::MouseEvent* pEvent)
{
	bool b = MDInkWellBase::OnMouseDown(pEvent);

	if (!mRippleAnimation)
		mRippleAnimation = new e3::Animation();

	float x = pEvent->GetX();
	float y = pEvent->GetY();

	e3::Rect2f rippleGeo = mRipple->GetGeometry();

	// mRipple->Translate(glm::vec3(x - (rippleGeo.x + rippleGeo.width / 2.0f), y - (rippleGeo.y + rippleGeo.height / 2.0f), 0));

	glm::vec4 color;
	/*if (mMainColor) color = glm::vec4(mMainColor->r, mMainColor->g, mMainColor->b, mMainColor->a);
	else*/ color = GetBackgroundColor();
	glm::vec3 hsl = RGBtoHSL(glm::vec3(color));
	glm::vec4 rippleColor;
	if (hsl.b >= 0.5 || color.w <= 0) rippleColor = glm::vec4(0, 0, 0, 0.16 * 255);
	else rippleColor = glm::vec4(255, 255, 255, 0.32 * 255);

	/*mRippleAnimation->Start(0.4, [this, x, y, rippleColor](float v) {
		mRipple->SetWidth(2 * GetGeometry().width * v);
		mRipple->SetHeight(2 * GetGeometry().width * v);
		//	glm::vec4 c = glm::vec4(0, 0, 0, 25);//MDColors::Grey::Get("300");
		//c.w = (1 - v) * 150;
		mRipple->SetBackgroundColor(rippleColor);

		e3::Rect2f rippleGeo = mRipple->GetGeometry();
		e3::Rect2f geo = GetGeometry();
		//mRipple->SetTranslation(glm::vec3(x - (geo.x + geo.width / 2.0f), y - (geo.y + geo.height / 2.0f), 0));
		//mRipple->SetTranslation(glm::vec3(x - (rippleGeo.x + rippleGeo.width / 2.0f), y - (rippleGeo.y + rippleGeo.height / 2.0f), 0));
		mRipple->Translate(glm::vec3(x - (rippleGeo.x + rippleGeo.width / 2.0f), y - (rippleGeo.y + rippleGeo.height / 2.0f), 0));
	}, [this, pEvent]() {
		mRippleAnimation = nullptr;
		_DismissRipple();
		//mRipple->SetBackgroundColor(glm::vec4(0));
		//mRipple->SetHeight(0);
	});*/

	mRipple->SetWidth(3 * GetGeometry().width );
	mRipple->SetHeight(3 * GetGeometry().width);
	mRipple->SetBackgroundColor(rippleColor);
	e3::Rect2f geo = GetGeometry();
	//mRipple->SetTranslation(glm::vec3(-x + (rippleGeo.x + rippleGeo.width / 2.0f), -y + (rippleGeo.y + rippleGeo.height / 2.0f), 0));

	float dx = x - geo.x;
	float dy = y - geo.y;

	mRippleAnimation->Start(5.0, [this, dx, dy, rippleColor](float v) {
		e3::Rect2f geo = GetGeometry();
		float x = geo.x + dx;
		float y = geo.y + dy;
		mRipple->SetScale(glm::vec3(v, v, 1), e3::ETransformAlignment::Center);
		e3::Rect2f rippleGeo = mRipple->GetGeometry();
		mRipple->Translate(glm::vec3(x - (rippleGeo.x + rippleGeo.width / 2.0f), y - (rippleGeo.y + rippleGeo.height / 2.0f), 0));
	}, [this, pEvent]() {
		mRippleAnimation = nullptr;
		// _DismissRipple();
		//mRipple->SetBackgroundColor(glm::vec4(0));
		//mRipple->SetHeight(0);
	});

	return b;
}

void MDInkWell::OnMouseEnter(e3::MouseEvent* pEvent)
{
	MDInkWellBase::OnMouseEnter(pEvent);
	//mMainColor = mColor;

/*	glm::vec4 color;
	if (mColor) color = glm::vec4(mColor->r, mColor->g, mColor->b, mColor->a);
	else color = GetBackgroundColor();

	glm::vec3 hsl = RGBtoHSL(glm::vec3(color));
	glm::vec4 rippleColor;
	if (hsl.b >= 0.5) rippleColor = glm::vec4(0, 0, 0, 12);
	else rippleColor = glm::vec4(255, 255, 255, 25);

	glm::vec4 hoverColor = rippleColor;//GetTheme()->HoverColor;// (0, 0, 0, 10);

	//MDColor c;
	if (color.a > 0) c = glm::mix(hoverColor, color, 1 - hoverColor.a / 255);
	else c = hoverColor;
	//mColor = new MDColor(c);*/
}

void MDInkWell::OnMouseHover(e3::MouseEvent* pEvent)
{
	MDInkWellBase::OnMouseHover(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Hand);
}

void MDInkWell::OnMouseLeave(e3::MouseEvent* pEvent)
{
	MDInkWellBase::OnMouseLeave(pEvent);
	GetApplication()->SetCursor(e3::ECursor::Arrow);
	/*delete mColor;
	mColor = mMainColor;*/
}

void MDInkWell::_DismissRipple()
{
	if (!mRippleDismissAnimation)
		mRippleDismissAnimation = new e3::Animation();

	glm::vec4 color;
	//if (mMainColor) color = glm::vec4(mMainColor->r, mMainColor->g, mMainColor->b, mMainColor->a);
	/*else*/ color = GetBackgroundColor();

	glm::vec3 hsl = RGBtoHSL(glm::vec3(color));
	glm::vec4 rippleColor;
	if (hsl.b >= 0.5 || color.w <= 0) rippleColor = glm::vec4(0, 0, 0, 0.16 * 255);
	else rippleColor = glm::vec4(255, 255, 255, 0.32 * 255);

	mRippleDismissAnimation->Start(0.4, [this, rippleColor](float v) {
		//glm::vec4 c = /GetTheme()->HoverColor;//glm::vec4(0, 0, 0, 25);//MDColors::Grey::Get("300");
		glm::vec4 c = rippleColor;
		c.w = (1 - v) * /*GetTheme()->HoverColor.a*/rippleColor.a;
		mRipple->SetBackgroundColor(c);
	}, [this]() {
		mRippleDismissAnimation = nullptr;
		mRipple->SetBackgroundColor(glm::vec4(0));
		mRipple->SetHeight(0);
	});
}