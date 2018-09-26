#include "ShaderProgram.h"



ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath)
{
	Shader vertexShader(GL_VERTEX_SHADER, vertexPath);
	Shader fragmentShader(GL_FRAGMENT_SHADER, fragmentPath);

	ID = glCreateProgram();
	glAttachShader(ID, vertexShader.getID());
	glAttachShader(ID, fragmentShader.getID());
	glLinkProgram(ID);

	int  success;
	char infoLog[512];
	glGetProgramiv(ID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		throw infoLog;
	}
}

void ShaderProgram::use()
{
	glUseProgram(ID);
}


ShaderProgram::~ShaderProgram()
{
}
