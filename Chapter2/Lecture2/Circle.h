#pragma once
#include "GeometricObj.h"

namespace jm {
	class Circle : public GeometricObj
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				translate(_pos);
				drawFilledCircle(_colors, _size);
			}
			endTransformation();
		}
	};
}

