#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 pos, Vec2 vel)
	: 
	position(pos),
	velocity(vel)
{
}

void Ball::Draw(Graphics & graph) const
{
	SpriteCodex::DrawBall(position, graph);
}

void Ball::Update(const float dt)
{
	position += velocity * dt;
}

bool Ball::DoWallCollision(const RectF & wall)
{
	bool result = false;

	const RectF rect = GetRect();

	if (rect.left < wall.left)
	{
		result = true;
		position.x += wall.left - rect.left;
		ReboundX();
	}
	else if(rect.right > wall.right)
	{
		result = true;
		position.x -= rect.right - wall.right;
		ReboundX();
	}
	else if (rect.top < wall.top)
	{
		result = true;
		position.y += wall.top - rect.top;
		ReboundY();
	}
	else if (rect.bottom > wall.bottom)
	{
		result = true;
		position.y -= rect.bottom - wall.bottom;
		ReboundY();
	}

	return result;
}

void Ball::ReboundX()
{
	velocity.x = -velocity.x;
}

void Ball::ReboundY()
{
	velocity.y = -velocity.y;
}

RectF Ball::GetRect() const
{
	return RectF::FromCenter(position, radius, radius);
}

Vec2 Ball::GetVelocity() const
{
	return velocity;
}

Vec2 Ball::GetPosition() const
{
	return position;
}

Vec2 Ball::GetCenter() const
{
	return position + Vec2(radius/2, radius/2);
}
