#pragma once
#include "GeometricObj.h"

namespace jm {
	class Triangle : public GeometricObj
	{
	public:

		void drawGeometricObj()const override
		{
			drawFilledTriangle(_colors, _size);
		}
	};
	
}


