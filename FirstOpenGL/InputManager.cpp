#include "InputManager.h"



void InputManager::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

InputManager::InputManager(GLFWwindow * window)
{
	this->window = window;
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}


InputManager::~InputManager()
{
}

void InputManager::update()
{
	glfwPollEvents();

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}
