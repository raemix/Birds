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
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	rng( rd()),
	xDist( 0,770 ),
	yDist( 0, 570 )
{
	std::uniform_real_distribution<float> vDist(-1.0f, 1.0f);
	leader.Init(Vec2(xDist(rng), yDist(rng)), Vec2(vDist( rng ), vDist( rng ) ) );
	std::uniform_real_distribution<float> MaxSpeed(0.60f, 1.0f);
	flock.reserve(nBirds);
	for (int i = 0; i < nBirds; ++i)
	{
		flock.emplace_back( Vec2( xDist( rng ), yDist( rng ) ), Vec2( 0, 0 ), MaxSpeed( rng) , Vec2( vDist( rng ), vDist( rng ) ) );
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
	float dt = 1;

	leader.Update(dt);
	for (int i = 0; i < nBirds; i++) {
		flock[i].Update(dt, leader.Getpos());
	}
}

void Game::ComposeFrame()
{
	leader.Draw(gfx);
	for (int i = 0; i < nBirds; i++) {
		flock[i].Draw(gfx);
	}
}
