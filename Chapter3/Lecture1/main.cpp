#include "Game2D.h"
#include "Examples/PrimitivesGallery.h"
#include "RandomNumberGenerator.h"
#include <vector>
#include <memory>

namespace jm
{
	class RigidCircle
	{
	public:
		vec2 pos;
		vec2 vel; // 속도
		float radius = 0.1f;

		void draw()
		{
			beginTransformation();
			{
				translate(pos);
				drawFilledCircle(Colors::hotpink, radius - 1e-3f);
				setLineWidth(2.0f);
				drawWiredCircle(Colors::black, radius); // 테두리
			}
			endTransformation();
		}

		void update(const float & dt)
		{
			static const vec2 gravity = vec2(0.0f,-9.8f); // 중력가속도 
			static const float coef_res = 0.3f; // coefficient of restitution , 얼마나 강하게 팅겨저 나올지
			static const float coef_friction = 0.99f; // friction (not physical)


			// numerical integration 수치 적분 / 속도에 따라 시간에 따라서 위치가 변하는 연산 
			vel += gravity * dt; //중력 반영
			pos += vel * dt; // 속도 *시간 을 더해주는 것 (서서히 속도만큼 이동)
			
			// wall collision, friction 벽에 부딫히는 경우 , 마찰력에 의해 속도가 줄어드는 경우
			if (1.0f - pos.x <= radius) //right wall
			{
				pos.x = 1.0f - radius;
				if(vel.x >= 0.0f)//안전장치
					vel.x *= -coef_res;
			}
			if (pos.y <= -1.0f + radius) //floor
			{
				pos.y = -1.0f + radius;

				if (vel.y <= 0.0f)//안전장치
					vel.y *= -coef_res;

				vel.x *= coef_friction; // 마찰력
			}
			if (pos.x <= -1.0f +radius) //left wall
			{
				pos.x =  -1.0f + radius;
				if (vel.x <= 0.0f)//안전장치
					vel.x *= -coef_res;
			}
			
		}
	};

	class Example : public Game2D
	{
	public:
		RigidCircle rigid_body;

		Example()
			: Game2D()
		{
			reset(); 
		}

		void reset()
		{
			// Initial position and velocity 위치,속도 초기값
			rigid_body.pos = vec2(-0.8f, 0.3f);
			rigid_body.vel = vec2(10.0f, 0.0f); // 초당 속도임
		}

		void drawWall() // 벽
		{
			setLineWidth(5.0f);
			drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { 1.0f, -1.0f });
			drawLine(Colors::blue, { 1.0f, -1.0f }, Colors::blue, { 1.0f, 1.0f });
			drawLine(Colors::blue, { -1.0f, -1.0f }, Colors::blue, { -1.0f, 1.0f });
		}

		void update() override
		{
			// physics update , 업데이트 패턴 이라고도 함
			rigid_body.update(getTimeStep() * 0.4f); //느리게 볼 수 있게 , 조정하면  빠르게도 가능

			// draw
			drawWall();
			rigid_body.draw();

			// reset button , 편의상 만든 리셋 기능
			if (isKeyPressedAndReleased(GLFW_KEY_R)) reset();
		}
	};
}

int main(void)
{
	jm::Example().run();

	return 0;
}
