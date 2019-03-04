#pragma once

#include "Graphics.h"
#include "RectF.h"

class Brick
{
public:
	Brick(RectF in_rect, Color in_color);

	void Draw(Graphics& graph) const;
private:
	Color color;
	RectF rect;
	bool isDestroyed = false;
};