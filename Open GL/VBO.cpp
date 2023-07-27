#include "VBO.h"



VBO::VBO(std::vector<Vertex>& vertices)
{
	glGenBuffers(1, &ID); //buffer object and pointing to refrence
	// bind the VBO specifying its a GL_ARRAY_BUFFER
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	// introducing the vertices into VBO
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

}



VBO::VBO(GLfloat* vertices, GLsizeiptr size)//del
{
	glGenBuffers(1, &ID); 
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

}//del








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