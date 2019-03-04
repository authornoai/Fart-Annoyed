#pragma once

#include "Vec2.h"

class RectF
{
public:
	RectF() = default;
	RectF(float in_left, float in_right, float in_top, float in_bottom);
	RectF(const Vec2& topLeftVec, const Vec2& bottomRightVec);
	RectF(const Vec2& topLeftVec, float width, float height);

	bool isOverlappingWith(const RectF& rect) const;
	static RectF FromCenter(const Vec2& center, float halfWidth, float halfHeight);
public:
	float left;
	float right;
	float top;
	float bottom;
};