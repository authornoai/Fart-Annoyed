#include "Ball.h"
#include "SpriteCodex.h"

Ball::Ball(Vec2 pos, Vec2 vel)
	: 
	position(pos),
	velocity(vel)
{
}

void Ball::Draw(Graphics & graph)
{
	SpriteCodex::DrawBall(position, graph);
}
