#include "Leader.h"
#include <cstdlib>
#include "Graphics.h"
#include <cmath>

void Leader::Init(Vec2& in_pos, Vec2& in_vel)
{
	pos = in_pos;
	vel = in_vel;
	srand(0);
}

void Leader::Update(float dt)
{
	pos += vel * dt;

	const float right = pos.x + dim;


	if (pos.x <= 0) {
		pos.x = 0;
		vel.x = abs(vel.x);
	}
	else if (right >= float(Graphics::ScreenWidth)) {
		pos.x = float(Graphics::ScreenWidth) - 1 - dim;
		vel.x = abs(vel.x) * - 1;
	}

	const float bottom = pos.y + dim;

	if (pos.y < 0) {
		pos.y = 0;
		vel.y = abs(vel.y);
	}
	else if (bottom >= float(Graphics::ScreenHeight)) {
		pos.y = float(Graphics::ScreenHeight) - 1 - dim;
		vel.y = abs(vel.y) * - 1;
	}
	if (rand() % 200 == 87)
		vel.y += 1.0;
	if (rand() % 200 == 38)
		vel.x += 1.0;
	vel.Normalize();
	vel *= 2.5f;
}

void Leader::Draw(Graphics& gfx)
{
	gfx.DrawRectByDim((int)pos.x, (int)pos.y, (int)dim, (int)dim, c);
}

Vec2 Leader::Getpos()
{
	return pos;
}
