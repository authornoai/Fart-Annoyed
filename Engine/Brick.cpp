#include "Brick.h"

Brick::Brick(RectF in_rect, Color in_color) :
	rect(in_rect),
	color(in_color)
{
}

bool Brick::DoBallCollision(Ball & ball) 
{
	if (!isDestroyed && rect.isOverlappingWith(ball.GetRect()))
	{
		isDestroyed = true;
		ball.ReboundY();
		return true;
	}
	return false;
}

void Brick::Draw(Graphics & graph) const
{
	if (!isDestroyed)
	{
		graph.DrawRect(rect, color);
	}
}
