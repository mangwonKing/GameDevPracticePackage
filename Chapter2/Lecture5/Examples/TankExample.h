#pragma once

#include "Game2D.h"
#include <map>
#include <fstream>
namespace jm
{
	class Actor
	{
	public:
		virtual void moveUp(float dt) = 0;
		virtual void moveDown(float dt) = 0;
		virtual void moveRight(float dt) = 0;
		virtual void moveLeft(float dt) = 0;
	};

	class Command
	{
	public:
		virtual ~Command() {}
		virtual void execute(Actor& actor, float dt) = 0;
	};

	class UpCommand : public Command 
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveUp(dt);
		}
	};
	class DownCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveDown(dt);
		}
	};
	class RightCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveRight(dt);
		}
	};
	class LeftCommand : public Command
	{
	public:
		virtual void execute(Actor& actor, float dt) override
		{
			actor.moveLeft(dt);
		}
	};
	class MyTank : public Actor
	{
	public:
		vec2 center = vec2(0.0f, 0.0f);
		//vec2 direction = vec2(1.0f, 0.0f, 0.0f);

		void moveUp(float dt) override
		{
			center.y += 0.5f * dt;
		}
		void moveDown(float dt) override
		{
			center.y -= 0.5f * dt;
		}
		void moveRight(float dt) override
		{
			center.x += 0.5f * dt;
		}
		void moveLeft(float dt) override
		{
			center.x -= 0.5f * dt;
		}

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

	class InputHandler
	{
	public:
		Command * button_up = nullptr;
		Command* button_down = nullptr;
		Command* button_right = nullptr;
		Command* button_left = nullptr;

		std::map<int, Command *> key_command_map;

		InputHandler()
		{
			button_up = new UpCommand;
			button_down = new DownCommand;
			button_right = new RightCommand;
			button_left = new LeftCommand;
		}

		void handleInput(Game2D & game, Actor & actor, float dt)
		{
			/*if (game.isKeyPressed(GLFW_KEY_UP))  button_up->execute(actor, dt);
			if (game.isKeyPressed(GLFW_KEY_DOWN)) button_down->execute(actor, dt);
			if (game.isKeyPressed(GLFW_KEY_RIGHT)) button_right->execute(actor, dt);
			if (game.isKeyPressed(GLFW_KEY_LEFT)) button_left->execute(actor, dt);*/

			for (auto & m : key_command_map)
			{
				if (game.isKeyPressed(m.first)) m.second->execute(actor, dt);
			}
		}
	};

	class TankExample : public Game2D
	{
	public:
		MyTank tank;

		InputHandler input_handler;

	public:
		TankExample()
			: Game2D("This is my digital canvas!", 1024, 768, false, 2)
		{
			std::vector<char> key;
			int upKey, downKey, rightKey, leftKey;

			std::ifstream keyBind;
			keyBind.open("key_binding.txt");
			if (keyBind.is_open())
			{
				while (!keyBind.eof())
				{
					std::string str;
					getline(keyBind, str);
					key.push_back(str[0]);
				}
				keyBind.close();
			}
			upKey = key[0];
			downKey = key[1];
			rightKey = key[2];
			leftKey = key[3];
			//key mapping
			
			input_handler.key_command_map[upKey] = new UpCommand;
			input_handler.key_command_map[downKey] = new DownCommand;
			input_handler.key_command_map[rightKey] = new RightCommand;
			input_handler.key_command_map[leftKey] = new LeftCommand;
		}

		~TankExample()
		{
		}

		void update() override
		{
			// move tank
			/*if (isKeyPressed(GLFW_KEY_LEFT))	tank.center.x -= 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_RIGHT))	tank.center.x += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_UP))		tank.center.y += 0.5f * getTimeStep();
			if (isKeyPressed(GLFW_KEY_DOWN))	tank.center.y -= 0.5f * getTimeStep();*/

			input_handler.handleInput(*this, tank, getTimeStep());

			// rendering
			tank.draw();
		}
	};
}