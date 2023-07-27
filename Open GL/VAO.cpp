#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{

	VBO.Bind();

	// configure the vertices attribute so that opengl know how to read the VBO
	glVertexAttribPointer(layout, numComponents,type, GL_FALSE, stride, offset);
	// ennabling the vertices attribute so that opengl to use it
	glEnableVertexAttribArray(layout);

	VBO.Unbind();
}

void VAO::Bind() 
{
	// make the VAO the current vertices array object by binding it
	glBindVertexArray(ID);

}

void VAO::Unbind() 
{
	// make the VAO the current vertices array object by binding it
	glBindVertexArray(0);

}
void VAO::Delete() 
{
	// make the VAO the current vertices array object by binding it
	glDeleteVertexArrays(1,&ID);
}