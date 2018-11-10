#pragma once
#include "stb_image.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Texture
{
private:
	int width, height, nrChannels;
	unsigned int id;

public:
	Texture(char const *location, GLenum format);
	~Texture();
	void bindTextureToUnit(int texUnit);
};

