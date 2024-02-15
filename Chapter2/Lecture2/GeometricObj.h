#pragma once

#include "Game2D.h"
namespace jm {
	class GeometricObj
	{
	public:
		virtual ~GeometricObj()
		{}
		void init(const vec2& pos ,const RGB& colors, const float& angle = 0)
		{
			_pos = pos;
			_colors = colors;
			_angle = angle;
		}

		void draw()
		{
			beginTransformation();
			{
				translate(_pos);
				rotate(_angle);
				drawGeometricObj();
			}
			endTransformation();
		}
		virtual void drawGeometricObj() = 0;
		
		static GeometricObj* makeTriangle(const vec2& pos, const RGB& colors, const float& size);
		static GeometricObj* makeCircle(const vec2& pos, const RGB& colors, const float& size,
			const float& angle = 0);
		static GeometricObj* makeBox(const vec2& pos, const RGB& colors, const float& width, const float& height);
		static GeometricObj* makeStar(const vec2& pos, const RGB& colors, const float& outer, const float& inner);
	
	public:
		vec2 _pos;
		RGB _colors;
		float _angle;

	};
}


