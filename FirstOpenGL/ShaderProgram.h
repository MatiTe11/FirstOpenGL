#pragma once
#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H


#include "Shader.h"

class ShaderProgram
{
private:
	int ID;
public:
	ShaderProgram(const char* vertexPath, const char* fragmentPath);
	void use();
	void set4f(const std::string &name, float f1, float f2, float f3, float f4);
	~ShaderProgram();
};

#endif // !SHADER_PROGRAM_H