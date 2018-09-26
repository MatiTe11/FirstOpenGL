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
	~ShaderProgram();
};

#endif // !SHADER_PROGRAM_H