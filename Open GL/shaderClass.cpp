#include "shaderClass.h"


std::string get_file_contents(const char* filename) 
{
	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return (contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentcode = get_file_contents(fragmentFile);

	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentcode.c_str();

	// create vertex shader object and get refrence 
	GLuint vertexSharder = glCreateShader(GL_VERTEX_SHADER); //creating refrence of shader
	// attach vertex shader source to the vertex shader object
	glShaderSource(vertexSharder, 1, &vertexSource, NULL);
	// compile the vertex shader into machine code
	glCompileShader(vertexSharder);

	compileErrors(vertexSharder,"VERTEX");


	



	// create fragment shader object and get its refrence
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	// attach fragment shaders source to the fragment shader object
	glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
	// compile the fragment shader 
	glCompileShader(fragmentShader);



	compileErrors(fragmentShader, "FRAGMENTS");

	// create shader program object and get its refrence 
	ID = glCreateProgram();
	// attach the vertices and fragment shaders to the shader program
	glAttachShader(ID, vertexSharder);
	glAttachShader(ID, fragmentShader);
	// wrap-up/links all the shaders together into shader program
	glLinkProgram(ID);

	compileErrors(ID, "PROGRAM/ID");



	// delete the now useless vertex and shaders
	glDeleteShader(vertexSharder);
	glDeleteShader(fragmentShader);

}

void Shader::Activate() 
{
	// tell opengl which shader we want to use
	glUseProgram(ID);
}
void Shader::Delete() 
{
	glDeleteProgram(ID);
}

void Shader::compileErrors(unsigned int shader, const char* type) 
{
	GLint hasCompiled;
	char infolog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infolog);
			std::cout << "shaders_comilation_error_for \n: " << type << "\n" << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);
		if (hasCompiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infolog);
			std::cout << "shaders_linking_error_for \n: " << type << "\n" << std::endl;
		}
	}

}