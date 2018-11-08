#include "Cube.h"

 float Cube::vertices[] = {
	-0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
	 0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
	-0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
	 0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
	-0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
	 0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
	-0.5f, -0.5f,  0.5f,  0.0f, 1.0f,
	 0.5f, -0.5f,  0.5f,  1.0f, 1.0f,
};

unsigned int Cube::indices[] = {  // note that we start from 0!
		0, 1, 3,   // first triangle
		0, 2, 3,    // second triangle
		5,1,3,
		5,7,3,
		4,5,7,
		4,6,7,
		4,0,2,
		4,6,2,
		0,1,5,
		0,4,5,
		2,6,7,
		2,3,7,

};

bool Cube::initialized = false;
unsigned int Cube::VAO = 0;
unsigned int Cube::VBO = 0;
unsigned int Cube::EBO = 0;
ShaderProgram* Cube::cubeShader = nullptr;


Cube::Cube(ShaderProgram* shader)
{
	int scale = 100;
	for (int i = 0; i < 8; i++)
	{
		vertices[5*i] *= scale;
		vertices[5*i + 1] *= scale;
		vertices[5*i + 2] *= scale;

	}

	if (!initialized)
		initialize();

	cubeShader = shader;

	glm::vec3 vector = (glm::inverse(model) * glm::vec4(1, 0, 0, 0));
	//model = glm::rotate(model, glm::radians(45.0f), vector);
	vector = (glm::inverse(model) * glm::vec4(0, 0, 1, 0));
	//model = glm::rotate(model, glm::radians(45.0f), vector);
}

void Cube::draw()
{
	cubeShader->use();
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
}

glm::mat4* Cube::getModel()
{
	return &model;
}

void Cube::rotate(float deegres)
{
	model = glm::rotate(model, glm::radians(deegres), glm::vec3(0.0f, 1.0f, 0.0f));	
}


Cube::~Cube()
{
}

void Cube::initialize()
{
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0); //position of vertex
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1); // position of texture

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	
}
