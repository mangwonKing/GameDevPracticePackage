#pragma once

#include "Game2D.h"

namespace jm
{
	class MyTank
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f); //회전기능 있을때 필요

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
		vec2 velocity = vec2(0.0f, 0.0f); // 속도

		void draw()
		{
			beginTransformation();
			translate(center);
			drawFilledRegularConvexPolygon(Colors::yellow, 0.02f, 8);
			drawWiredRegularConvexPolygon(Colors::gray, 0.02f, 8);
			endTransformation();
		}

		void update(const float& dt)
		{
			center += velocity * dt;
			draw();
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyTank tank;

		MyBullet *bullet[10]; //발사 될 때만 있어서 포인터
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
				if (bullet[i] != nullptr)bullet[i]->update(getTimeStep());
			}

			//if (bullet != nullptr) bullet->update(getTimeStep());

			// rendering
			tank.draw();
			for (int i = 0; i < ammo; i++)
			{
				if (bullet[i] != nullptr) bullet[i]->draw();
			}
			
		}
	};
}