#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include <vector>

//#include "Triangle.h"
//#include "Circle.h"
//#include "Box.h"
#include "GeometricObj.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		std::vector<GeometricObj*> obj;

		Example()
			: Game2D()
		{
			obj.push_back(GeometricObj::makeTriangle({ -0.5,-0.05 }, Colors::green, 0.3f));
			obj.push_back(GeometricObj::makeCircle({ 0.0,0.0 }, Colors::red, 0.15f));
			obj.push_back(GeometricObj::makeBox({ 0.5,0.0 }, Colors::blue, 0.2f, 0.4f));
			obj.push_back(GeometricObj::makeStar({ 0.0,-0.5 }, Colors::olive, 0.25f, 0.15f));
		}
		
		void update() override
		{
			for (auto& o : obj)
			{
				o->draw();
				o->_angle += 5;
			}
		}
		~Example()
		{
			for (auto& o : obj)
			{
				delete o;
			}
		}
	};
}

int main(void)
{
	jm::Example().run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::PrimitivesGallery().run();

	return 0;
}
