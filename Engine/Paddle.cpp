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
	graph.DrawRect(GetRect(), wingColor);
	RectF nonWingRect = GetRect();
	nonWingRect.left += wingWidth;
	nonWingRect.right -= wingWidth;
	graph.DrawRect(nonWingRect, color);
}

bool Paddle::DoBallCollision(Ball & ball)
{
	bool result = false;
	if (!isCooldown)
	{
		const RectF rect = GetRect();
		if (GetRect().isOverlappingWith(ball.GetRect()))
		{
			const Vec2 ballPos = ball.GetCenter();
			if (std::signbit(ball.GetVelocity().x) == std::signbit((ballPos - pos).x))
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
			result = true;
			isCooldown = true;
		}
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

void Paddle::ResetCooldown()
{
	isCooldown = false;
}
