#pragma once
#include "GeometricObj.h"

namespace jm {
	class Box : public GeometricObj
	{
	public:
		Box(const vec2& pos, const RGB& colors, const float& width, const float& height)
		{
			init(pos, colors, width,height);
		}
		~Box()
		{
			std::cout << "box �Ҹ�\n";
		}
		void init(const vec2& pos, const RGB& colors, 
			const float& width, const float& height)
		{
			GeometricObj::init(pos,colors);
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

