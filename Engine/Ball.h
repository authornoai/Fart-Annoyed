#pragma once

#include "Graphics.h"
#include "RectF.h"

class Ball
{
public:
	Ball(Vec2 position, Vec2 vel);

	void Draw(Graphics& graph) const;
	void Update(float dt);

	bool DoWallCollision(const RectF& wall);
	void ReboundX();
	void ReboundY();

	RectF GetRect() const;
	Vec2 GetVelocity() const;
	Vec2 GetPosition() const;
	Vec2 GetCenter() const;

private:
	Vec2 position;
	Vec2 velocity;
	static constexpr float radius = 7.0f;

};