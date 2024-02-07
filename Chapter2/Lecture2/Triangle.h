#pragma once
#include "GeometricObj.h"

namespace jm {
	class Triangle : public GeometricObj
	{
	public:
		void init(const vec2& pos, const RGB& colors, const float& size)
		{
			GeometricObj::init(pos, colors);
			_size = size;
		}
		void drawGeometricObj() override
		{
			drawFilledTriangle(_colors, _size);
		}
	public:
		float _size;
	};
	
}


