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

void ShaderProgram::set4f(const std::string &name, float f1, float f2, float f3, float f4)
{
	use();
	glUniform4f(glGetUniformLocation(ID, name.c_str()), f1,f2,f3,f4);
}


ShaderProgram::~ShaderProgram()
{
}
