#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Ball
{
public:
	Ball(Vec2 position, Vec2 vel);

	void Draw(Graphics& graph) const;
	void Update(float dt);

private:
	Vec2 position;
	Vec2 velocity;
	static constexpr float radius = 7.0f;

};