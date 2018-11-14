#include "Cube.h"

float Cube::vertices[] = { //pos, normal, tex
   -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f ,0.0f,
	0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f ,0.0f,
	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f ,1.0f,
	0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 1.0f ,1.0f,
   -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f ,1.0f,
   -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f, 0.0f ,0.0f,

   -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f ,0.0f,
	0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f ,0.0f,
	0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f ,1.0f,
	0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 1.0f ,1.0f,
   -0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f ,1.0f,
   -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f, 0.0f ,0.0f,

   -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f ,0.0f,
   -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f ,0.0f,
   -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f ,1.0f,
   -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f, 1.0f ,1.0f,
   -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f ,1.0f,
   -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f, 0.0f ,0.0f,

	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f ,0.0f,
	0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f ,0.0f,
	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f ,1.0f,
	0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f, 1.0f ,1.0f,
	0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f ,1.0f,
	0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f, 0.0f ,0.0f,

   -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f ,0.0f,
	0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 1.0f ,0.0f,
	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f ,1.0f,
	0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 1.0f ,1.0f,
   -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f, 0.0f ,1.0f,
   -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f, 0.0f ,0.0f,

   -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f ,0.0f,
	0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 1.0f ,0.0f,
	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f ,1.0f,
	0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 1.0f ,1.0f,
   -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f, 0.0f ,1.0f,
   -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f
};



bool Cube::initialized = false;
unsigned int Cube::VAO = 0;
unsigned int Cube::VBO = 0;
//unsigned int Cube::EBO = 0;


Cube::Cube(ShaderProgram* shader)
{
	if (!initialized)
		initialize();

	translation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
	rotation = glm::vec3(0.0f);

	cubeShader = shader;
}

Cube::Cube(ShaderProgram * shader, glm::vec3 color)
{
	if (!initialized)
		initialize();

	translation = glm::vec3(0.0f);
	scale = glm::vec3(1.0f);
	rotation = glm::vec3(0.0f);

	cubeShader = shader;
	this->color = color;
}

void Cube::draw()
{
	cubeShader->use();
	cubeShader->setMatrix4f("model", glm::value_ptr(model));
	cubeShader->set3f("aColor", color.x, color.y, color.z);
	cubeShader->set1f("ambient", ambient);
	for (int i = 0; i < textureVector.size(); i++)
	{
		textureVector[i]->bindTextureToUnit(i);
	}
	glBindVertexArray(VAO);
	//glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);	
	glDrawArrays(GL_TRIANGLES, 0, sizeof(vertices) / sizeof(float));
}

void Cube::pushTexture(Texture * tex)
{
	textureVector.push_back(tex);
}

glm::mat4* Cube::getModel()
{
	return &model;
}

void Cube::rotate(float deegres, glm::vec3 axis)
{
	rotation += glm::vec3(axis.x * deegres, axis.y * deegres, axis.z * deegres);
	transform();
}

void Cube::scaling(glm::vec3 scale)
{
	this->scale *= scale;
	transform();
}

void Cube::translate(glm::vec3 trans)
{
	translation += trans;
	transform();
}

glm::vec3 Cube::getPos()
{
	return translation;
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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0); //position of vertex
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1); //position of normal
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2); // position of texture

	/*glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);*/
}

void Cube::transform()
{
	glm::mat4 trans;
	trans = glm::translate(trans, translation);

	glm::vec3 vector = (glm::inverse(model) * glm::vec4(1, 0, 0, 0));
	trans = glm::rotate(trans, glm::radians(rotation.x), vector);
	vector = (glm::inverse(trans) * glm::vec4(0, 1, 0, 0));
	trans = glm::rotate(trans, glm::radians(rotation.y), vector);
	vector = (glm::inverse(trans) * glm::vec4(0, 0, 1, 0));
	trans = glm::rotate(trans, glm::radians(rotation.z), vector);

	trans = glm::scale(trans, scale);



	model = trans;
}
