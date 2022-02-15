#pragma once
#define GLEW_STATIC
#include <glew.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>

class Shader
{
public:
	Shader();

	void CreateShaderFromFile(const char *vertex, const char *fragment);
	std::string ReadFile(const char *filelocation);
	unsigned int GetProjectionLocation();
	unsigned int GetModel();

	void UseShader();
	void ClearShader();

	~Shader();

private:
	unsigned int shaderID, uniformProjection, uniformModel;

	void CompileShader(const char *vertexzShaderCode, const char *fragShaderCode);
	void AddShader(unsigned int program, const char *shaderCode, GLenum shadertype);
};
