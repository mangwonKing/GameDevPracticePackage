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
			my_tri.init({ -0.5,-0.05 }, Colors::green, 0.3f);
			my_cir.init({ 0.0,0.0 }, Colors::red, 0.15f);
			my_box.init({ 0.5,0.0 }, Colors::blue, 0.2f, 0.3f);
		}
		Triangle my_tri;
		Circle my_cir;
		Box my_box;
		void update() override
		{
			// yellow triangle
			
			my_tri.draw();
			// red circle
			my_cir.draw();

			//// blue box
			my_box.draw();
			//beginTransformation();
			//{
			//	translate(vec2{ 0.5f, 0.0f });
			//	drawFilledBox(Colors::blue, 0.25f, 0.3f);
			//}
			//endTransformation();
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
