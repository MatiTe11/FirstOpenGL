#pragma once
#include <glad/glad.h> 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.h"
#include <vector>
#include "Texture.h"
#include <glm/gtc/type_ptr.hpp>

class Cube 
{
protected:
	static  float vertices[];
	static unsigned int indices[];
	static unsigned int VAO;
	static unsigned int VBO;
	//static unsigned int EBO;
	static bool initialized;
	glm::mat4 model;
	glm::vec3 translation;
	glm::vec3 scale;
	glm::vec3 rotation;
	ShaderProgram* cubeShader;
	std::vector<Texture*> textureVector;
	glm::vec3 color;
	float ambient = 0.1f;

	static void initialize();
	void transform();
	
public:
	Cube(ShaderProgram* shader);
	Cube(ShaderProgram* shader, glm::vec3 color);
	void draw();
	void pushTexture(Texture* tex);
	glm::mat4* getModel();
	void rotate(float deegres, glm::vec3 axis);
	void scaling(glm::vec3 scale);
	void translate(glm::vec3 trans);
	glm::vec3 getPos();
	~Cube();

};

