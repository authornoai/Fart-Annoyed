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

		const Vec2 ballPos = ball.GetCenter();
		if (rect.left < ballPos.x &&
			ballPos.x < rect.right)
		{
			ball.ReboundY();
		}
		else
		{
			ball.ReboundX();
		}

		isDestroyed = true;
		return true;
	}
	return false;
}

void Brick::Draw(Graphics & graph) const
{
	if (!isDestroyed)
	{
		graph.DrawRect(rect.GetExpanded(-padding), color);
	}
}
