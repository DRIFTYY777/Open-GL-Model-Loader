#include "VBO.h"



VBO::VBO(GLfloat* vertices, GLsizeiptr size) 
{
	glGenBuffers(1, &ID); //buffer object and pointing to refrence
	// bind the VBO specifying its a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	// introducing the vertices into VBO
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

}

void VBO::Bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}
void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void VBO::Delete()
{
	glDeleteBuffers(1, &ID);
}