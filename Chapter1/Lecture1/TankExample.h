#pragma once

#include "Game2D.h"
#include <iostream>
namespace jm
{
	class MyTank
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f); //ȸ����� ������ �ʿ�

		void draw()
		{
			beginTransformation();
			{
				translate(center);
				drawFilledBox(Colors::green, 0.25f, 0.1f); // body
				translate(-0.02f, 0.1f);
				drawFilledBox(Colors::blue, 0.15f, 0.09f); // turret
				translate(0.15f, 0.0f);
				drawFilledBox(Colors::red, 0.15f, 0.03f);  // barrel
			}
			endTransformation();
		}
	};

	class MyBullet
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		vec2 velocity = vec2(0.0f, 0.0f); // �ӵ�
		int tick = 0;
		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		bool update(const float& dt)
		{
			center += velocity * dt;
 			draw();
			tick++;
			if (tick > 100)
			{
				delete this;
				return false;
			}
			return true;
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyTank tank;

		MyBullet *bullet[100]; //�߻� �� ���� �־ ������
		int ammo = 0;
		//TODO: allow multiple bullets
		//TODO: delete bullets when they go out of the screen

	public:
		TankExample()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2)
		{}

		~TankExample()
		{
			for (int i = 0; i < ammo; i++)
			{
				if (bullet[i] != nullptr) delete bullet;
			}
			//if(bullet != nullptr) delete bullet;
		}

		void update() override
		{
			// move tank
			if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_RIGHT)) tank.center.x += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_UP)) tank.center.y += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_DOWN)) tank.center.y -= 0.5f * getTimeStep();
			
			// shoot a cannon ball
			if (isKeyPressedAndReleased(GLFW_KEY_SPACE))
			{
				bullet[ammo] = new MyBullet();
				bullet[ammo]->center = tank.center;
				bullet[ammo]->center.x += 0.2f;
				bullet[ammo]->center.y += 0.1f;
				bullet[ammo]->velocity = vec2(2.0f, 0.0f);
				ammo++;
				
			}
			for (int i = 0; i < ammo; i++)
			{
				if (bullet[i] != nullptr)
				{
					if (!bullet[i]->update(getTimeStep()))
					{
						ammo--;
					}
					
				}
			}

			//if (bullet != nullptr) bullet->update(getTimeStep());
			std::cout << ammo << "�� \n";
			// rendering
			tank.draw();
			for (int i = 0; i < ammo; i++)
			{
				if (bullet[i] != nullptr) bullet[i]->draw();
			}
			
		}
	};
}