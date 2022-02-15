#include "CustomFunctions/Shader.h"

Shader::Shader()
{
	shaderID = 0;
	uniformModel = 0;
	uniformProjection = 0;
}

unsigned int Shader::GetProjectionLocation() { return uniformProjection; }
unsigned int Shader::GetModel() { return uniformModel; }

void Shader::UseShader() { glUseProgram(shaderID); }

std::string Shader::ReadFile(const char *filelocation)
{
	std::string content;
	std::ifstream newFile(filelocation, std::ios::in);

	if (!newFile.is_open())
	{
		std::cout << "Error Reading file: %s " << filelocation << std::endl;
		return "";
	}
	std::string line = "";
	while (!newFile.eof())
	{
		std::getline(newFile, line);
		content.append(line + "\n");
	}

	newFile.close();
	return content;
}

void Shader::ClearShader()
{
	if (shaderID != 0)
	{
		glDeleteProgram(shaderID);
		shaderID = 0;
	}
	uniformModel = 0;
	uniformProjection = 0;
}

void Shader::CreateShaderFromFile(const char *vertex, const char *fragment)
{
	std::string vertexShader = ReadFile(vertex);
	std::string fragmentShader = ReadFile(fragment);
	// std::string geoShader = ReadFile(geoshader);
	// std::string geofragmentShader = ReadFile(geoFrag);

	const char *vertexCode = vertexShader.c_str();
	const char *fragCode = fragmentShader.c_str();
	// const char *geoCode = geoShader.c_str();
	// const char *geoFragCode = geofragmentShader.c_str();

	CompileShader(vertexCode, fragCode);
}

void Shader::AddShader(unsigned int program, const char *shaderCode, GLenum shaderType)
{
	unsigned int shader_ = glCreateShader(shaderType);
	const GLchar *code[1];
	code[0] = shaderCode;

	int codeLength[1];
	codeLength[0] = (int)strlen(shaderCode);

	glShaderSource(shader_, 1, code, codeLength);
	glCompileShader(shader_);

	//	error check
	int result = 0;
	char elog[255] = {0};

	glGetShaderiv(shader_, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(shader_, sizeof(elog), NULL, elog);
		std::cout << "Error Compiling Shader: " << shaderType << std::endl;
		std::cout << elog << std::endl;
		return;
	}

	glAttachShader(program, shader_);
}
void Shader::CompileShader(const char *vertexCode, const char *fragCode)
{

	shaderID = glCreateProgram();

	if (!shaderID)
	{
		std::cout << "Shader Issue" << std::endl;
		return;
	}
	AddShader(shaderID, vertexCode, GL_VERTEX_SHADER);
	AddShader(shaderID, fragCode, GL_FRAGMENT_SHADER);
	// AddShader(shaderID, geoCode, GL_GEOMETRY_SHADER);
	// AddShader(shaderID, geoFrag, GL_FRAGMENT_SHADER);

	//	error check
	int result = 0;
	glLinkProgram(shaderID);

	glGetProgramiv(shaderID, GL_LINK_STATUS, &result);
	if (!result)
	{
		char elog[1024] = {0};
		glGetProgramInfoLog(shaderID, sizeof(elog), NULL, elog);
		std::cout << "Error Compiling Program:" << shaderID << std::endl;
		std::cout << elog << std::endl;
		return;
	}

	//	validation
	glGetProgramiv(shaderID, GL_VALIDATE_STATUS, &result);
	if (!result)
	{
		char elog[255] = {0};
		glGetProgramInfoLog(shaderID, sizeof(elog), NULL, elog);

		std::cout << ("Error Validation Program %s ", elog) << std::endl;
	}

	uniformModel = glGetUniformLocation(shaderID, "model");
	uniformProjection = glGetUniformLocation(shaderID, "projection");
}

Shader::~Shader()
{
}