#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"

namespace jm
{

	void drawHouse(const RGB& roofColor,const vec2& pos, const float& angle = 0.0f)
	{

		// draw a house
		beginTransformation();
		{
			translate(pos);
			rotate(angle);
			// wall
			drawFilledBox(Colors::yellow, 0.2f, 0.2f);

			// roof
			drawFilledTriangle(roofColor, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });
			drawWiredTriangle(roofColor, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });

			// window
			drawFilledBox(Colors::skyblue, 0.1f, 0.1f);
			drawWiredBox(Colors::gray, 0.1f, 0.1f);
			drawLine(Colors::gray, { 0.0f, -0.05f }, Colors::gray, { 0.0f, 0.05f });
			drawLine(Colors::gray, { -0.05f, 0.0f }, Colors::gray, { 0.05f, 0.0f });

		}
		endTransformation();
	}
	class Example : public Game2D
	{
	public:
		void update() override
		{
			drawHouse(Colors::red,{ -0.5f,0 });
			drawHouse(Colors::blue,{0,0});
			drawHouse(Colors::gray,{0.5f,0});
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
