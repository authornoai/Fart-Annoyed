#pragma once

#include "Graphics.h"
#include "Ball.h"
#include "Keyboard.h"
#include "Vec2.h"

class Paddle
{
public:
	Paddle(const Vec2& in_pos, float in_halfWidth, float in_halfHeight);

	void Draw(Graphics& graph) const;
	bool DoBallCollision(Ball& ball);
	bool DoWallCollision(const RectF& walls);
	void Update(const Keyboard& kbd, float dt);
	RectF GetRect() const;

	void ResetCooldown();
private:
	Color color = Colors::White;
	const float halfWidth;
	const float halfHeigth;
	float speed = 300.0f;
	Vec2 pos;

	const float wingWidth = 15.0f;
	Color wingColor = Colors::Red;

	bool isCooldown = false;
};