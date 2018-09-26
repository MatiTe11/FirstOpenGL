#pragma once
#ifndef SHADER_H
#define SHADER_H
#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class Shader
{
private:
	int ID;
	const GLchar* shaderSource;
	GLenum type;

	void compileShader();
public:
	Shader(GLenum type, const GLchar* shaderPath);
	int getID();
	~Shader();
};
#endif // !SHADER_H
