#pragma once

#include "Graphics.h"
#include "RectF.h"
#include "Ball.h"

class Brick
{
public:
	Brick() = default;
	Brick(RectF in_rect, Color in_color);

	bool CheckBallCollision(const Ball& ball) const;
	void ExecuteBallCollision(Ball& ball);
	void Draw(Graphics& graph) const;

	Vec2 GetCenter() const;
private:
	Color color;
	RectF rect;
	bool isDestroyed = false;
	static constexpr float padding = 3.f;
};