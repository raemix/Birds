#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"

class Bird {
public:
	Bird(const Vec2& pos, const Vec2& vel, float MaxSpeed, const Vec2& Offset);
	void Init(const Vec2& pos);
	void Update(float dt, const Vec2& pos);
	void Draw(Graphics& gfx);
	void FollowTheLeader(Vec2& vel, Vec2& in_pos);
private:
	Vec2 pos;
	Vec2 vel;
	float MaxSpeed;
	Vec2 offset;
	Color c{ 255,0,0 };
	static constexpr float dim = 3.0f;

};