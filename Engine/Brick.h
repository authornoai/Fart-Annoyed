#pragma once

#include "Graphics.h"
#include "RectF.h"

class Brick
{
public:
	Brick(RectF in_rect, Color in_color);

	void Draw(Graphics& graph);
private:
	Color color;
	RectF rect;
	bool isDestroyed = false;
};