#pragma once

#include "Vec2.h"
#include "Colors.h"
#include "Graphics.h"

class Bird {
	Bird() = default;
public:

	void Init(const Vec2& pos);
	void Update(float dt);
	void Draw(Graphics& gfx);


private:
	Vec2 pos;
	Vec2 vel;
	Color c{ 100,255,100 };
	static constexpr float dim = 3.0f;



};