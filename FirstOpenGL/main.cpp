#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "ShaderProgram.h"
#include "stb_image.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Cube.h"
#include "InputManager.h"
#include "Camera.h"



int main()
{
	float screenWidth = 800;
	float screenHeight = 600;

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(screenWidth, screenHeight, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	glViewport(0, 0, screenWidth, screenHeight);

	InputManager inputManager(window);
	glm::vec2 cursorPos = inputManager.getCursorPos();
	Camera camera(0.05f, glm::vec3(0,0,3), 20, screenWidth, screenHeight, cursorPos.x, cursorPos.y);
	inputManager.registerObserver(&camera);

	ShaderProgram program1("vertexShader.txt", "fragmentShader1.txt");
	ShaderProgram program2("vertexShader.txt", "fragmentShader2.txt");

	

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

	//texture
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int width, height, nrChannels;
	unsigned char *data = stbi_load("container.jpg", &width, &height, &nrChannels, 0);
	 
	unsigned int texture;
	glGenTextures(1, &texture);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	program2.setSampler2d("ourTexture", 0);
	stbi_image_free(data);
	///tex2
	unsigned int texture2;
	glGenTextures(1, &texture2);
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, texture2);

	data = stbi_load("awesomeface.png", &width, &height, &nrChannels, 0);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
	program2.setSampler2d("ourTexture2", 1);


	//Cube
	Cube myCube(&program2);
	myCube.scaling(glm::vec3(1.0f));
	myCube.translate(glm::vec3(0.5f));
	myCube.rotate(90.0f, glm::vec3(1.0f));

	glEnable(GL_DEPTH_TEST);

	double lastTime = glfwGetTime();;
	double now = glfwGetTime();;
	double deltaTime;

	while (!glfwWindowShouldClose(window))
	{
		now = glfwGetTime();
		deltaTime = now - lastTime;
		lastTime = now;

		inputManager.update();
		camera.update(deltaTime);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		program2.setMatrix4f("model", glm::value_ptr(*myCube.getModel()));
		program2.setMatrix4f("view", glm::value_ptr(*camera.getViewMatrix()));
		program2.setMatrix4f("projection", glm::value_ptr(*camera.getProjectionMatrix()));
		myCube.draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}