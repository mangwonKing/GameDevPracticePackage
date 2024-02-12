#pragma once
#include "GeometricObj.h"

namespace jm {
	class Circle : public GeometricObj
	{
	public:
		Circle(const vec2& pos, const RGB& colors, const float& size,
			const float& angle = 0)
		{
			init(pos, colors, size,angle);
		}
		~Circle()
		{
			std::cout << "circle ¼Ò¸ê \n";
		}
		void init(const vec2& pos, const RGB& colors, const float& size,
			const float& angle = 0)
		{
			GeometricObj::init(pos, colors,angle);
			_size = size;
		}
		void drawGeometricObj() override
		{
			drawFilledCircle(_colors, _size);
		}
	public:
		float _size;
	};
}

