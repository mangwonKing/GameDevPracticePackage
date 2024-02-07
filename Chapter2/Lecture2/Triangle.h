#pragma once
#include "GeometricObj.h"

namespace jm {
	class Triangle : public GeometricObj
	{
	public:
		void draw()
		{
			beginTransformation();
			{
				translate(_pos);
				drawFilledTriangle(_colors, _size);
			}
			endTransformation();
		}
	};
	
}


