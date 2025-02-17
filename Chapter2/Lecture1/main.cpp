#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"

namespace jm
{
	class House
	{
	public:
		House() : _pos({ 0,0 }), _angle(0.0f),_roofColor(Colors::red)
		{

		}
		void draw()
		{
			// draw a house
			beginTransformation();
			{
				translate(_pos);
				rotate(_angle);
				// wall
				drawFilledBox(Colors::yellow, 0.2f, 0.2f);

				// roof
				drawFilledTriangle(_roofColor, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });
				drawWiredTriangle(_roofColor, { -0.13f, 0.1f }, { 0.13f, 0.1f }, { 0.0f, 0.2f });

				// window
				drawFilledBox(Colors::skyblue, 0.1f, 0.1f);
				drawWiredBox(Colors::gray, 0.1f, 0.1f);
				drawLine(Colors::gray, { 0.0f, -0.05f }, Colors::gray, { 0.0f, 0.05f });
				drawLine(Colors::gray, { -0.05f, 0.0f }, Colors::gray, { 0.05f, 0.0f });

			}
			endTransformation();
		}
		void setPos(const vec2& pos)
		{
			_pos = pos;
		}
		void setAngle(const float& angle)
		{
			_angle = angle;
		}
		void setRoofColor(const RGB& roofColor)
		{
			_roofColor = roofColor;
		}
	private:
		vec2 _pos;
		float _angle;
		RGB _roofColor;

	};
	void drawHouse(const RGB& roofColor,const vec2& pos, const float& angle = 0.0f)
	{

		
	}
	class Example : public Game2D
	{
	public:
		void update() override
		{
			House left_house, center_house, right_house;
			left_house.setPos({ -0.5,0.0 });
			right_house.setPos({ 0.5,0.0 });

			left_house.setAngle(30);
			right_house.setAngle(-30);

			left_house.setRoofColor(Colors::blue);
			right_house.setRoofColor(Colors::gold);

			left_house.draw();
			center_house.draw();
			right_house.draw();

			/*drawHouse(Colors::red,{ -0.5f,0 });
			drawHouse(Colors::blue,{0,0});
			drawHouse(Colors::gray,{0.5f,0});*/
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
