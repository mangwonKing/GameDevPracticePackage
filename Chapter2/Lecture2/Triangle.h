#pragma once
#include "Game2D.h"

namespace jm {
	class Triangle
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				translate(_pos);
				drawFilledTriangle(_colors, _size);
			}
			endTransformation();
		}

		vec2 _pos;
		RGB _colors;
		float _size;

	};
	
}


