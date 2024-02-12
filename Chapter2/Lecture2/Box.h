#pragma once
#include "GeometricObj.h"

namespace jm {
	class Box : public GeometricObj
	{
	public:
		Box(const vec2& pos, const RGB& colors, const float& width, const float& height,
			const float& angle = 0)
		{
			init(pos, colors, width,height, angle);
		}
		~Box()
		{
			std::cout << "box ¼Ò¸ê\n";
		}
		void init(const vec2& pos, const RGB& colors, 
			const float& width, const float& height, const float& angle)
		{
			GeometricObj::init(pos,colors,angle);
			_width = width;
			_height = height;
		}
		void drawGeometricObj() override
		{
			drawFilledBox(_colors, _width, _height);
		}
	public:
		float _width;
		float _height;
	};
}

