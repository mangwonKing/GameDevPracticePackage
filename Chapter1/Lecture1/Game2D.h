#pragma once

#include "RGB.h" //색을 결정
#include "Vector2.h" //2차원 벡터
#include "Vector3.h" //3차원 벡터
#include "Colors.h"
#include "Timer.h"
#include "DrawFunctions.h" //중요

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <thread>         // std::this_thread::sleep_for
#include <iostream>
#include <vector>
#include <string>
#include <map>

namespace jm
{
	using vec2 = Vector2<float>;
	using vec3 = Vector3<float>;

	class Game2D
	{
	private:
		int width = 640;
		int height = 480; //해상도

		GLFWwindow* glfw_window = nullptr; // 화면에 뜬 창에 대한 포인터, glfw 는 윈도우를 띄워주는 api

		Timer timer;

		float spf = 1.0f / 60.0f;		 // second(s) per frame  , fps 의 역수

		// control options 키보드 입력 
		std::map<int, bool> key_status;  // key_id, is_pressed
		std::map<int, bool> mbtn_status; // mouse_button_id, is_pressed
		bool draw_grid = false; // 키 입력에 따라 true

	public:
		Game2D()
		{}

		Game2D(const std::string& _title, const int& _width, const int& _height,
			const bool & use_full_screen = false, const int & display_ix = 0);

		~Game2D();

		Game2D & init(const std::string& _title, const int& _width, const int& _height,
			const bool & use_full_screen = false, const int & display_ix = 0);

		void reportErrorAndExit(const std::string& function_name, const std::string& message); // 에러 출력

		bool isKeyPressed(const int& key);
		bool isKeyReleased(const int & key);
		bool isKeyPressedAndReleased(const int& key); //키보드를 눌렀다가 때는것에 대한 3가지 함수

		bool isMouseButtonPressed(const int& mbtn);
		bool isMouseButtonReleased(const int& mbtn);
		bool isMouseButtonPressedAndReleased(const int& mbtn);

		vec2 getCursorPos(const bool& screen_coordinates = true);

		float getTimeStep();

		void drawGrid();

		void run();

		virtual void update() // 나만의 업데이트 함수를 만들 때 이 함수를 오버라이딩 해서 해봐라 라는 의미
		{
			// draw
			// play sould
			// physics update
			// etc.
		}
	};
}