#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"
#include <vector>

namespace jm
{
	class Example : public Game2D
	{
	public:
		Example()
			: Game2D()
		{
			auto* my_tri = new Triangle({ -0.5,-0.05 }, Colors::green, 0.3f, 40.0f);
			auto* my_cir = new Circle({ 0.0,0.0 }, Colors::red, 0.15f);
			auto* my_box = new Box({ 0.5,0.0 }, Colors::blue, 0.2f, 0.4f, 90.0f);

			obj.push_back(my_tri);
			obj.push_back(my_cir);
			obj.push_back(my_box);
		}

		std::vector<GeometricObj*> obj;
		
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
