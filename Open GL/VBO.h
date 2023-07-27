#ifndef VBO_CLASS_H
#define VBO_CLASS_H

#include <glm/glm.hpp> //original


#include <glad/glad.h> //original


#include <vector>

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec3 color;
	glm::vec2 texUV;
};

class VBO
{
	public:
		GLuint ID;
		VBO(std::vector<Vertex>& vertices);
		VBO(GLfloat* vertices, GLsizeiptr size); //del


		void Bind();
		void Unbind();
		void Delete();


};



#endif // !VBO_CLASS_H

