#include "Bird.h"

void Bird::Init(const Vec2& in_pos)
{
	pos = in_pos;
}

void Bird::Update(float in_dt)
{
	float dt = in_dt;

	pos += vel * dt;

	const float right = pos.x + dim;

	if (pos.x < 0) {
		pos.x = 0;
		vel.x = -vel.x;
	}
	else if (right > Graphics::ScreenWidth) {
		pos.x = Graphics::ScreenWidth - 1 - dim;
		vel.x = -vel.x;
	}

	const float bottom = pos.y + dim;

	if (pos.y < 0) {
		pos.y = 0;
		vel.y = -vel.y;
	}
	else if (bottom > Graphics::ScreenHeight) {
		pos.y = Graphics::ScreenHeight - 1 - dim;
		vel.y = -vel.y;
	}
}

void Bird::Draw(Graphics & gfx)
{
	gfx.DrawRectByDim((int)pos.x, (int)pos.y, (int)dim, (int)dim, c);
}
