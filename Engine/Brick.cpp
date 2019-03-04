#include "Brick.h"

Brick::Brick(RectF in_rect, Color in_color) :
	rect(in_rect),
	color(in_color)
{
}

void Brick::Draw(Graphics & graph) const
{
	graph.DrawRect(rect, color);
}
