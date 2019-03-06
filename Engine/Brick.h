#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF in_rect, Color in_color);

	bool DoBallCollision(Ball& ball);
	void Draw(Graphics& graph) const;
private:
	Color color;
	RectF rect;
	bool isDestroyed = false;
};