#pragma once
#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.h"

class Cube
{
private:
	static const float vertices[];
	static unsigned int indices[];
	static unsigned int VAO;
	static unsigned int VBO;
	static unsigned int EBO;
	static bool initialized;
	glm::mat4 model;
	static ShaderProgram* cubeShader;

	static void initialize();
	
public:
	Cube(ShaderProgram* shader);
	void draw();
	glm::mat4* getModel();
	~Cube();

	
};

