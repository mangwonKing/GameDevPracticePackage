#pragma once
#include "GeometricObj.h"

namespace jm{
	class Star : public GeometricObj
	{
	public:
		Star(const vec2& pos, const RGB& colors, const float& outer, const float& inner)
		{
			init(pos, colors, outer, inner);
		}
		~Star()
		{
			std::cout << "star ¼Ò¸ê\n";
		}
		void init(const vec2& pos, const RGB& colors,
			const float& outer, const float& inner)
		{
			GeometricObj::init(pos, colors);
			_outer = outer;
			_inner = inner;
		}
		void drawGeometricObj() override
		{
			drawFilledStar(_colors, _outer, _inner);
		}
	public:
		float _outer;
		float _inner;
	};
};

