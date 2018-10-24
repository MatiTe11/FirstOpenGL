#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class InputManager
{
private:
	GLFWwindow * window;
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
	
public:
	InputManager(GLFWwindow * window);
	~InputManager();
	void update();
};

