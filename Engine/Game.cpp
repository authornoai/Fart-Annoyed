/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ball(Vec2(200, 200), Vec2(300, 300)),
	border( 0, 0, gfx.ScreenWidth, gfx.ScreenHeight),
	player( Vec2(400, 300), 50, 15),
	soundPad(L"Sounds\\arkpad.wav"),
	soundBrick(L"Sounds\\arkbrick.wav")
{

	const Color colors[4] = { Colors::Red, Colors::Green, Colors::Blue, Colors::Cyan };
	const Vec2 topLeft(40.0f, 40.0f);

	int index = 0;
	for (int y = 0; y < nBrickRows; ++y)
	{
		const Color c = colors[y];
		for (int x = 0; x < nBrickAcross; ++x)
		{
			bricks[index] = Brick(RectF(
			topLeft + Vec2(x * brickWidth, y * brickHeight), brickWidth, brickHeight), c);
			++index;
		}
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	const float dt = timer.Mark();
	ball.Update(dt);
	player.Update(wnd.kbd, dt);

	bool collisionHappend = false;
	float curColDist;
	int curColIndex;

	for (int i = 0; i < nBricks; ++i)
	{
		if (bricks[i].CheckBallCollision(ball))
		{
			const float newColDist = (ball.GetCenter() - bricks[i].GetCenter()).GetLengthSq();
			if (collisionHappend)
			{
				if (newColDist < curColDist)
				{
					curColDist = newColDist;
					curColIndex = i;
				}
			}
			else
			{
				curColDist = newColDist;
				curColIndex = i;
				collisionHappend = true;
			}
		}
	}

	if (collisionHappend)
	{
		bricks[curColIndex].ExecuteBallCollision(ball);
		soundBrick.Play();
	}

	player.DoWallCollision(border);
	
	if (ball.DoWallCollision(border) || 
		player.DoBallCollision(ball))
	{
		soundPad.Play();
	}
	
}

void Game::ComposeFrame()
{
	for(Brick& b : bricks)
	{
		b.Draw(gfx);
	}
	ball.Draw(gfx);
	player.Draw(gfx);
}
