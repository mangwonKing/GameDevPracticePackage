#pragma once
#include "Game2D.h"

namespace jm {
	class Circle
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				drawFilledCircle(Colors::red, 0.15f);
			}
			endTransformation();
		}
		vec2 _pos;
		RGB _colors;
		float _size;
	};
}

