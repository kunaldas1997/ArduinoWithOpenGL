#include "CustomFunctions/Mesh.h"

Mesh::Mesh()
{
	VAO = 0;
	VBO = 0;
	IBO = 0;
	EBO = 0;
	indexCount = 0;

}

void Mesh::CreateMesh(std::vector<float> vertices)
{
	indexCount = static_cast<int>(vertices.size());



	//	Vertex Array Object
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	//	Index buffer
	// glGenBuffers(1, &IBO);
	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(float) , &indices.front(), GL_STATIC_DRAW);

	//	Element Buffer Object
	// glGenBuffers(1, &EBO);
	// glBindBuffer(GL_ARRAY_BUFFER, EBO);

	// glBufferData(GL_ARRAY_BUFFER, elementBuffer.size() * sizeof(float), &elementBuffer.front(), GL_STATIC_DRAW);


	//	Buffer Array
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	// Connect Buffer Data
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices.front(), GL_STATIC_DRAW);

	// Vertex Attrib Pointer
	glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, 4-1*sizeof(float), 0);
	glEnableVertexAttribArray(0);

	//	Unbind 
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::RenderMesh()
{
	glBindVertexArray(VAO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);

	glDrawArrays(GL_LINE_STRIP, 0, indexCount);
	//glDrawElements(GL_LINES, indexCount, GL_UNSIGNED_INT, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

void Mesh::ClearMesh()
{
	if (IBO != 0)
	{
		glDeleteBuffers(1, &IBO);
		IBO = 0;
	}

	if (VBO != 0)
	{
		glDeleteBuffers(1, &VBO);
		VBO = 0;
	}

	if (VAO != 0)
	{
		glDeleteVertexArrays(1, &VAO);
		VAO = 0;
	}
	if (EBO != 0)
	{
		glDeleteVertexArrays(1, &EBO);
		EBO = 0;
	}
	indexCount = 0;
}


Mesh::~Mesh()
{
	ClearMesh();
}