#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "InputObserver.h"
#include <vector>
#include <iostream>



class InputManager
{
private:
	static std::vector<InputObserver*> observers;
	GLFWwindow * window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	
public:
	InputManager(GLFWwindow * window);
	~InputManager();
	void update();
	void registerObserver(InputObserver* observer);
	void removeObserver(InputObserver* observer);
};

