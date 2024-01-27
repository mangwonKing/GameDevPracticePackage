#include "Game2D.h"
#include "PrimitivesGallery.h"
#include "TankExample.h"
#include "FaceExample.h"
#include "WalkingPerson.h"
#include "SolarSystem.h"

namespace jm
{
	class RotatingStarExample :public Game2D
	{
		float time = 0.0f;
	public:
		

		void update() override
		{
			setLineWidth(3.0f);

			rotate(time * 30.0f);
			drawFilledStar(Colors::gold, 0.25f,0.125f);
			//지구 만들기
			beginTransformation();

			rotate(time *30.0f); //속도 조절 
			translate(0.75f,0.0f);
			drawFilledCircle(Colors::blue, 0.125f);
			//달 만들기
			rotate(time * 30.0f); //속도 조절 
			translate(0.25f, 0.0f);
			drawFilledCircle(Colors::gray, 0.05f);
		
			endTransformation();
			
			/*rotate(time * 90.0f);
			translate(0.5f, 0.0f);
			rotate(time * 90.0f);
			scale(2.0f, 0.25f);
			drawWiredBox(Colors::gold, 0.5f, 0.5f);
			*/
			time += this->getTimeStep();

		}
	};
}



int main(void)
{
	////jm::MouseExample().init("This is my digital canvas!", 1000, 1000, false).run();
	//jm::Game2D().init("This is my digital canvas!", 1280, 960, false).run();
	jm::RotatingStarExample().init("RotatinStarExample!", 1280, 960, false).run(); //true 누르면 풀 스크린
	//jm::PrimitivesGallery().init("Primitive Gallery", 1280, 960, false).run();
	//jm::SolarSystem().run();
	//jm::FaceExample().run();
	//jm::WalkingPerson().run();
	//jm::TankExample().run();

	return 0;
}
