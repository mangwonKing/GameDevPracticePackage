#pragma once
#include "GeometricObj.h"

namespace jm {
	class Triangle : public GeometricObj
	{
	public:
		Triangle(const vec2& pos, const RGB& colors, const float& size,
			const float& angle)
		{
			init(pos,colors,size,angle);
		}
		~Triangle()
		{
			std::cout << "triangle ¼Ò¸ê\n";
		}
		void init(const vec2& pos, const RGB& colors, const float& size,
			const float& angle)
		{
			GeometricObj::init(pos, colors,angle);
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


