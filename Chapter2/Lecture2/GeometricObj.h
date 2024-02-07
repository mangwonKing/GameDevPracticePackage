#pragma once

#include "Game2D.h"
namespace jm {
	class GeometricObj
	{
	public:
		void init(const vec2& pos ,const RGB& colors)
		{
			_pos = pos;
			_colors = colors;
		}

		void draw()
		{
			beginTransformation();
			{
				translate(_pos);
				drawGeometricObj();
			}
			endTransformation();
		}
		virtual void drawGeometricObj() const
		{

		}
	
	public:
		vec2 _pos;
		RGB _colors;
		

	};
}


