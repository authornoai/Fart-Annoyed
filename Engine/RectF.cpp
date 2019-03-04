#include "RectF.h"

RectF::RectF(float in_left, float in_right, float in_top, float in_bottom) :
	left(in_left),
	right(in_right),
	top(in_top),
	bottom(in_bottom)
{
}

RectF::RectF(const Vec2 & topLeftVec, const Vec2 & bottomRightVec) :
	RectF(topLeftVec.x, bottomRightVec.x, topLeftVec.y, bottomRightVec.y)
{
}

RectF::RectF(const Vec2 & topLeftVec, float width, float height) :
	RectF(topLeftVec, topLeftVec + Vec2(width, height))
{
}

bool RectF::isOverlappingWith(const RectF & rect) const
{
	return right > rect.left && left < rect.right
		&& top < rect.bottom && bottom > rect.top;
}

RectF RectF::FromCenter(const Vec2 & center, float halfWidth, float halfHeight)
{
	return RectF(center.x - halfWidth, center.x + halfWidth, center.y - halfHeight, center.y + halfHeight);
}
