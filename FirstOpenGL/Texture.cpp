#include "Texture.h"



Texture::Texture(char const *location, GLenum format)
{
	unsigned char *data;
	data = stbi_load(location, &width, &height, &nrChannels, 0);
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);
	stbi_image_free(data);
}


Texture::~Texture()
{
}

void Texture::bindTextureToUnit(int texUnit)
{
	glActiveTexture(GL_TEXTURE0 + texUnit);
	glBindTexture(GL_TEXTURE_2D, id);
}
