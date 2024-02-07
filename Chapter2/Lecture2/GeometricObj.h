#pragma once

#include "Game2D.h"
namespace jm {
	class GeometricObj
	{
	public:
		void init(vec2 pos , RGB colors , float size)
		{
			_pos = pos;
			_colors = colors;
			_size = size;
		}

		/*void draw()
		{
			beginTransformation();
			{
				translate(_pos);
				drawFilledCircle(_colors, _size);
			}
			endTransformation();
		}*/
	
	public:
		vec2 _pos;
		RGB _colors;
		float _size;

	};
}


