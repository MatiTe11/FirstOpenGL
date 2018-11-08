#include "InputManager.h"


std::vector<InputObserver*> InputManager::observers;

void InputManager::framebuffer_size_callback(GLFWwindow * window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void InputManager::key_callback(GLFWwindow * window, int key, int scancode, int action, int mods)
{
	for (InputObserver *observer : observers)
	{
		observer->updateKey(key, action);
		std::cout << "keycall";
	}
	
}

void InputManager::cursor_position_callback(GLFWwindow * window, double xpos, double ypos)
{
	
	for (InputObserver *observer : observers) 
	{
		observer->updateMouse(xpos, ypos);
	}
}

InputManager::InputManager(GLFWwindow * window)
{
	this->window = window;
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, &InputManager::key_callback);
	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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

void InputManager::registerObserver(InputObserver * observer)
{
	observers.push_back(observer);
}

void InputManager::removeObserver(InputObserver * observer)
{
	auto iterator = std::find(observers.begin(), observers.end(), observer);

	if (iterator != observers.end()) 
	{
		observers.erase(iterator);
	}
}
