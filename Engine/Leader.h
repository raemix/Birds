#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"

class Leader {
public:
	Leader() = default;
	Leader(const Vec2& pos_in, const Vec2& vel_in)
		:
		pos(pos_in),
		vel(vel_in)
	{}
	void Init(Vec2& pos, Vec2& vel);
	void Update(float dt);
	void Draw(Graphics& gfx);
	Vec2 Getpos();
private:
	Vec2 pos;
	Vec2 vel;
	Color c{ 0,255,0 };
	static constexpr float dim = 5.0f;

};