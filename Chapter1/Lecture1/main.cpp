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

			//사람얼굴 그리기
			
			rotate(time * 45.0f);// 얼굴 전체 돌리기 ,, 이게 종속되는 개념인가..?

			drawFilledCircle(Colors::silver, 0.35f);// 얼굴
			beginTransformation();
			translate(0.0f, -0.125f);
			
			drawFilledTriangle(Colors::gold, 0.125f);//  부리
			endTransformation();
			beginTransformation(); // 눈
			translate(0.125f, 0.125f);
			drawFilledCircle(Colors::black, 0.05f);
			endTransformation();
			beginTransformation();
			translate(-0.125f, 0.125f);
			drawFilledCircle(Colors::black, 0.05f);
			endTransformation();
			time += this->getTimeStep();


			/*rotate(time * 90.0f);
			translate(0.5f, 0.0f);
			rotate(time * 90.0f);
			scale(2.0f, 0.25f);
			drawWiredBox(Colors::gold, 0.5f, 0.5f);
			*/
			

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
