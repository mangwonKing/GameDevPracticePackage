#include "GeometricObj.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
#include "Star.h"

namespace jm 
{
	GeometricObj* jm::GeometricObj::makeTriangle(const vec2& pos, const RGB& colors, const float& size)
	{
		return new Triangle(pos,colors,size);
	}

	GeometricObj* jm::GeometricObj::makeCircle(const vec2& pos, const RGB& colors, const float& size, const float& angle)
	{
		return new Circle(pos,colors,size);
	}

	GeometricObj* jm::GeometricObj::makeBox(const vec2& pos, const RGB& colors, const float& width, const float& height)
	{
		return new Box(pos,colors,width,height);
	}
	GeometricObj* GeometricObj::makeStar(const vec2& pos, const RGB& colors, const float& outer, const float& inner)
	{
		return new Star(pos,colors,outer,inner);
	}
}