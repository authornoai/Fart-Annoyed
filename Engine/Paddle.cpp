#include "Paddle.h"


Paddle::Paddle(const Vec2 & in_pos, float in_halfWidth, float in_halfHeight)
	:
	pos(in_pos),
	halfWidth(in_halfWidth),
	halfHeigth(in_halfHeight)
{
}

void Paddle::Draw(Graphics & graph) const
{
	graph.DrawRect(GetRect(), color);
}

bool Paddle::DoBallCollision(Ball & ball) const
{
	bool result = false;

	if (GetRect().isOverlappingWith(ball.GetRect()))
	{
		ball.ReboundY();
		result = true;
	}

	return result;
}

bool Paddle::DoWallCollision(const RectF & walls)
{
	const RectF rect = GetRect();
	if (rect.left < walls.left)
	{
		pos.x += walls.left - rect.left;
		return true;
	}
	else if (rect.right > walls.right)
	{
		pos.x -= rect.right - walls.right;
		return true;
	}
	return false;
}

void Paddle::Update(const Keyboard& kbd, float dt)
{
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		pos.x -= speed * dt;
	}
	else if (kbd.KeyIsPressed(VK_RIGHT))
	{
		pos.x += speed * dt;
	}
}

RectF Paddle::GetRect() const
{
	return RectF::FromCenter(pos, halfWidth, halfHeigth);
}
