#include "Bird.h"

Bird::Bird(const Vec2& in_pos, const Vec2& in_vel, float in_MaxSpeed, const Vec2& in_Offset)
{
	pos = in_pos;
	vel = in_vel;
	MaxSpeed = in_MaxSpeed;
	offset = in_Offset;
}

void Bird::Init(const Vec2& in_pos)
{
	pos = in_pos;
}

void Bird::Update(float in_dt, const Vec2& lin_pos)
{
	float dt = in_dt;
	Vec2 lpos = lin_pos;
	pos += vel * dt * MaxSpeed;

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
	FollowTheLeader(vel, lpos);
}

void Bird::Draw(Graphics & gfx)
{
	gfx.DrawRectByDim((int)pos.x, (int)pos.y, (int)dim, (int)dim, c);
}

void Bird::FollowTheLeader(Vec2& vel, Vec2& in_pos)
{
	vel -= pos - in_pos;
	vel += offset * 10;
	vel.Normalize();
}
