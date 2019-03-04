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
