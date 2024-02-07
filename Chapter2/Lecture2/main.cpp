#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"
#include "Box.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		Example()
			: Game2D()
		{
			my_tri.init({ -0.5,-0.05 }, Colors::green, 0.3f,40.0f);
			my_cir.init({ 0.0,0.0 }, Colors::red, 0.15f);
			my_box.init({ 0.5,0.0 }, Colors::blue, 0.2f, 0.4f,90.0f);
		}
		Triangle my_tri;
		Circle my_cir;
		Box my_box;
		void update() override
		{
			my_tri.draw();
			my_cir.draw();
			my_box.draw();
			my_box._angle += 5;
			my_tri._angle += 5;
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
