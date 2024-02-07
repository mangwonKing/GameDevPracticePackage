#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include "Triangle.h"
#include "Circle.h"

namespace jm
{
	class Example : public Game2D
	{
	public:
		Example()
			: Game2D()
		{
			my_tri._colors = Colors::green;
			my_tri._pos = { -0.5,-0.05 };
			my_tri._size = 0.3f;

			my_cir._colors = Colors::red;
			my_cir._pos = { 0,0 };
			my_cir._size = 0.3f;
		}
		Triangle my_tri;
		Circle my_cir;
		void update() override
		{
			// yellow triangle
			
			my_tri.draw();
			// red circle
			my_cir.draw();

			//// blue box
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
