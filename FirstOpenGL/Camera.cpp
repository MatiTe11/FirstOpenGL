#include "Camera.h"
#include <iostream>

Camera::Camera(float sens, glm::vec3 pos, double speed, float screenWidth, float screenHeight, double cursorX, double cursorY)
{
	sensitivity = sens;
	position = pos;
	this->speed = speed;
	this->prevX = 0;
	this->prevY = 0;
	frontSpeed = 0;
	rightSpeed = 0;
	projection = glm::perspective(glm::radians(45.0f), (screenWidth / screenHeight), 0.1f, 200.0f);
	direction = glm::vec3(0, 0, -1);
	updateMouse(cursorX, cursorY);
	yaw = 0;
	pitch = 0;
	updateMouse(cursorX, cursorY);
}

Camera::~Camera()
{
}


void Camera::update(double deltaTime)
{
	position -= (float)frontSpeed * (float)deltaTime * direction;
	position += glm::normalize(glm::cross(direction, glm::vec3(0,1,0))) * (float)rightSpeed * (float)deltaTime;
	view = glm::lookAt(position, position + direction, glm::vec3(0.0, 1.0, 0.0));
	std::cout << pitch<<  "yaw: " << yaw << std::endl;
}

glm::mat4* Camera::getViewMatrix()
{
	return &view;
}

glm::mat4* Camera::getProjectionMatrix()
{
	return &projection;
}

void Camera::updateMouse(double X, double Y)
{
	double deltaX = X - prevX;
	double deltaY = Y - prevY;
	prevX = X;
	prevY = Y;
	
	deltaX *= sensitivity;
	deltaY *= -sensitivity;
	
	pitch += deltaY;
	yaw += deltaX;
	std::cout << "yaw: " << X << " pitch: " << Y << std::endl;

	//update direction vector
	direction.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	direction.y = sin(glm::radians(pitch));
	direction.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	direction = glm::normalize(direction);
}

void Camera::updateKey(int key, int action)
{
	//just update key states
	if (action == GLFW_PRESS)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			frontSpeed = -speed;
			break;
		case GLFW_KEY_DOWN:
			frontSpeed = speed;
			break;
		case GLFW_KEY_RIGHT:
			rightSpeed = speed;
			break;
		case GLFW_KEY_LEFT:
			rightSpeed = -speed;
			break;

		default:
			break;
		}
	}
	else if (action == GLFW_RELEASE)
	{
		switch (key)
		{
		case GLFW_KEY_UP:
			frontSpeed = 0;
			break;
		case GLFW_KEY_DOWN:
			frontSpeed = 0;
			break;
		case GLFW_KEY_RIGHT:
			rightSpeed = 0;
			break;
		case GLFW_KEY_LEFT:
			rightSpeed = 0;
			break;

		default:
			break;
		}
	}
}
