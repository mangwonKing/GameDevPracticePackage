#pragma once
#include "GeometricObj.h"

namespace jm {
	class Circle : public GeometricObj
	{
	public:
		void drawGeometricObj() const override
		{
			drawFilledCircle(_colors, _size);
		}
	};
}

