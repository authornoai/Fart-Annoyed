#pragma once

#include "Graphics.h"
#include "Vec2.h"

class Paddle
{
private:
	Color color = Colors::White;
	const float halfWidht;
	const float halfHeight;
	Vec2 pos;
};