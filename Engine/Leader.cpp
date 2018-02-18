#include "Leader.h"

#include "Graphics.h"

void Leader::Init(Vec2& in_pos, Vec2& in_vel)
{
	pos = in_pos;
	vel = in_vel;
}

void Leader::Update(float dt)
{
	pos += vel * dt;

	const float right = pos.x + dim;


	if (pos.x < 0) {
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if (right > float(Graphics::ScreenWidth)) {
		pos.x = float(Graphics::ScreenWidth) - 1 - dim;
		vel.x = -vel.x;
	}

	const float bottom = pos.y + dim;

	if (pos.y < 0) {
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if (bottom > float(Graphics::ScreenHeight)) {
		pos.y = float(Graphics::ScreenHeight) - 1 - dim;
		vel.y = -vel.y;
	}
}

void Leader::Draw(Graphics& gfx)
{
	gfx.DrawRectByDim((int)pos.x, (int)pos.y, (int)dim, (int)dim, c);
}

Vec2 Leader::Getpos()
{
	return pos;
}
