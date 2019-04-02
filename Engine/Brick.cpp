#include "Brick.h"
#include <assert.h>

Brick::Brick(RectF in_rect, Color in_color) :
	rect(in_rect),
	color(in_color)
{
}

bool Brick::CheckBallCollision(const Ball & ball) const
{
	return !isDestroyed && rect.isOverlappingWith(ball.GetRect());
}

void Brick::ExecuteBallCollision(Ball & ball)
{
	assert(CheckBallCollision(ball));
	const Vec2 ballPos = ball.GetCenter();
	if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - GetCenter()).x))
	{
		ball.ReboundY();
	}
	else if (rect.left <= ballPos.x &&
		ballPos.x <= rect.right)
	{
		ball.ReboundY();
	}
	else
	{
		ball.ReboundX();
	}
	isDestroyed = true;
}

void Brick::Draw(Graphics & graph) const
{
	if (!isDestroyed)
	{
		graph.DrawRect(rect.GetExpanded(-padding), color);
	}
}

Vec2 Brick::GetCenter() const
{
	return rect.GetCenter();
}
