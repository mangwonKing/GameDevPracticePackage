#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"

namespace jm
{
	class MouseExample : public Game2D
	{
	public:
		void update() override
		{
			const vec2 mouse_pos = getCursorPos(true); //true -> 화면 좌표계 , false -> 윈도우 좌표계

			//왼쪽버튼을 누를때 원이 그려지게
			if (this->isMouseButtonPressed(GLFW_MOUSE_BUTTON_1) == true)
			{
			
				translate(mouse_pos);
				drawFilledCircle(Colors::gold, 0.2f);
			}
			if (this->isMouseButtonPressed(GLFW_MOUSE_BUTTON_2) == true)
			{

				translate(mouse_pos);
				drawFilledCircle(Colors::red, 0.2f);
			}
		}
	};
}



int main(void)
{
	jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	//jm::RotatingStarExample().init("RotatinStarExample!", 1280, 960, false).run(); //true 누르면 풀 스크린
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::SolarSystem().run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	//jm::TankExample().run();

	return 0;
}
