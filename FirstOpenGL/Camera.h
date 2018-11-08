#pragma once
#include "InputObserver.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>


class Camera :public InputObserver
{
private:
	glm::vec3 position;
	glm::mat4 view;
	glm::mat4 projection;
	glm::vec3 direction;
	double speed;
	double frontSpeed;
	double rightSpeed;
	float sensitivity;
	double prevX, prevY;
	double pitch, yaw;
	

public:
	Camera(float sens, glm::vec3 pos, double speed, float screenWidth, float screenHeight);
	~Camera();
	void update(double deltaTime);
	glm::mat4* getViewMatrix();
	glm::mat4* getProjectionMatrix();
	// Inherited via InputObserver
	virtual void updateMouse(double X, double Y) override;
	virtual void updateKey(int key, int action) override;
};

