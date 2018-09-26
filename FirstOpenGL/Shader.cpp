#include "Shader.h"



Shader::Shader(GLenum type, const GLchar* shaderPath)
{
	this->type = type;

	std::string shaderCode;
	std::ifstream shaderFile;
	// ensure ifstream objects can throw exceptions:
	shaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		shaderFile.open(shaderPath);
		std::stringstream shaderStream;
		// read file's buffer contents into streams
		shaderStream << shaderFile.rdbuf();
		// close file handlers
		shaderFile.close();
		// convert stream into string
		shaderCode = shaderStream.str();
	}
	catch (std::ifstream::failure e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		throw "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ";
	}
	shaderSource = shaderCode.c_str();

	compileShader();
}

int Shader::getID()
{
	return ID;
}


void Shader::compileShader()
{
	ID = glCreateShader(type);
	glShaderSource(ID, 1, &shaderSource, NULL);
	glCompileShader(ID);
	int  success;
	char infoLog[512];
	glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(ID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		throw infoLog;
	}
}

Shader::~Shader()
{
	glDeleteShader(ID);
}
